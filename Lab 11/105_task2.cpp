#include <bits/stdc++.h>
using namespace std;
const int LEN = 32;
const int MAX = 100;
enum Employee_type
{
    tdeveloper,
    tteacher
};
class Employee
{
private:
    char name[LEN];
    int age, salary;
    static int count;
    static Employee *emp[];

public:
    Employee() {}
    void info(void)
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
    virtual void setData(void)
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter salary: ";
        cin >> salary;
    }
    virtual void showData(void) = 0;
    virtual Employee_type get_type(); //get type
    static void add();                //add an Employee
    static void display();            //display all Employees
    static void read();               //read from disk file
    static void write();
};
int Employee::count=0;
Employee *Employee::emp[MAX];
class Developer : public Employee
{
private:
    char company[LEN];

public:
    Developer() {}
    void setData(void)
    {
        Employee::setData();
        cout << "Enter company name: ";
        cin >> company;
    }
    void showData(void)
    {
        Employee::info();
        cout << "Company: " << company << endl;
    }
};

class Teacher : public Employee
{
private:
    char institution[LEN];

public:
    Teacher() {}
    void setData()
    {
        Employee::setData();
        cout << "Enter institution name: ";
        cin >> institution;
    }
    void showData(void)
    {
        Employee::info();
        cout << "Institution: " << institution << endl;
    }
};
void Employee::add()
{
    char ch;
    cout << "'d' to add a developer"
         << "\n't' to add a teacher"
         << "\n Enter selection : ";
    cin >> ch;
    switch (ch)
    { //create specified Employee type
    case 'd':
        emp[count] = new Developer;
        break;
    case 't':
        emp[count] = new Teacher;
        break;
    default:
        cout << "\nUnknown Employee type\n";
        return;
    }
    emp[count++]->setData(); //get Employee data from user
}
//display all employees
void Employee::display()
{
    for (int j = 0; j < count; j++)
    {
        cout << (j + 1);            //display number
        switch (emp[j]->get_type()) //display type
        {
        case tdeveloper:
            cout << ".Type : Developer" << endl;
            break;
        case tteacher:
            cout << ".Type : Teacher" << endl;
            break;
        default:
            cout << ".Unknown type" << endl;
        }
        emp[j]->showData(); //display employee data
        cout << endl;
    }
}
//return the type of this object
Employee_type Employee::get_type()
{
    if (typeid(*this) == typeid(Developer))
        return tdeveloper;
    else if (typeid(*this) == typeid(Teacher))
        return tteacher;
    else
    {
        cerr << "\nBad employee type";
        exit(1);
    }
}
//write all current memory objects to file
void Employee::write()
{
    int size;
    cout << "Writing " << count << " employees.\n";
    ofstream ouf;        //open ofstream in binary
    Employee_type etype; //type of each employee object
    ouf.open("Employee.bin", ios::trunc | ios::binary);
    if (!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < count; j++) //for every employee object
    {                               //get its type
        etype = emp[j]->get_type();
        //write type to file
        ouf.write((char *)&etype, sizeof(etype));
        switch (etype) //find its size
        {
        case tdeveloper:
            size = sizeof(Developer);
            break;
        case tteacher:
            size = sizeof(Teacher);
            break;
        } //write employee object to file
        ouf.write((char *)(emp[j]), size);
        if (!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}
//read data for all employees from file into memory
void Employee::read()
{
    int size;            //size of employee object
    Employee_type etype; //type of employee
    ifstream inf;        //open ifstream in binary
    inf.open("Employee.bin", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    count = 0; //no employees in memory yet
    while (true)
    { //read type of next employee
        inf.read((char *)&etype, sizeof(etype));
        if (inf.eof()) //quit loop on eof
            break;
        if (!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (etype)
        {                //make new employee
        case tdeveloper: //of correct type
            emp[count] = new Developer;
            size = sizeof(Developer);
            break;
        case tteacher:
            emp[count] = new Teacher;
            size = sizeof(Teacher);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } //read data from file into it
        inf.read((char *)emp[count], size);
        if (!inf) //error but not eof
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        count++; //count employee
    }            //end while
    cout << "Reading " << count << " employees\n";
}
int main(void)
{
    char ch;
    while (true)
    {
        cout << "'a' -- add data for an employee"
                "\n'd' -- display data for all employees"
                "\n'w' -- write all employee data to file"
                "\n'r' -- read all employee data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a': //add an employee to list
            Employee::add();
            break;
        case 'd': //display all employees
            Employee::display();
            break;
        case 'w': //write employees to file
            Employee::write();
            break;
        case 'r': //read all employees from file
            Employee::read();
            break;
        case 'x':
            exit(0); //exit program
        default:
            cout << "\nUnknown command";
        } //end switch
    }     //end while
    return 0;
} //end main()
