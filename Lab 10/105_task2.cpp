#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
    string name;

public:
    Student() {}
    Student(string s)
    {
        name = s;
    }
    Student(Student &obj)
    {
        name = obj.name;
        cout << "Copy constructor invoked" << endl;
    }
    void show(void)
    {
        cout << name << endl;
    }
    Student &operator=(Student &obj)
    {
        name = obj.name;
        cout << "Assignment operator invoked" << endl;
        return *this;
    }
};
class Department
{
private:
    string name;
    // It is essential that each member of this class be created with unique string for member data "name"
    // which is provided as an argument to the constructor
    // So to avoid copying it is necessary to keep the overloaded assignment operator and copy constructor private
    Department &operator=(Department &obj)
    {
        name = obj.name;
        cout << "Assignment operator invoked" << endl;
        return *this;
    }
    Department(Department &obj)
    {
        name = obj.name;
        cout << "Copy constructor invoked" << endl;
    }

public:
    Department() {}
    Department(string s) : name(s) {}
};
int main(void)
{
    Student s1("Tanjila");
    Student s2("Faria");
    Student s3(s2);
    cout << "s3= ";
    s3.show();
    Student s4;
    s4 = s1;
    cout << "s4= ";
    s4.show();

    Department d1("CSE"), d2;
    //d2=d1; // can't be assigned as overloaded assignment operaor is kept private
    //Department d3(d1); // can't be copied as constructor is kept private
}