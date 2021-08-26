#include <bits/stdc++.h>
using namespace std;

class Int
{
private:
    int cnt = 0;
    int *data;

public:
    Int()
    {
        data = new int[50];
    }
    /*Int(Int &obj)
    {
        cnt = obj.cnt;
        for (int i = 0; i < cnt; i++)
            data[i] = obj.data[i];
    }
    void operator=(Int &obj)
    {
        cnt = obj.cnt;
        for (int i = 0; i < cnt; i++)
            data[i] = obj.data[i];
    }*/
    void setData(int d)
    {
        data[cnt++] = d;
    }
    void change(int position, int value)
    {
        data[position] = value;
    }
    void show(void)
    {
        for (int i = 0; i < cnt; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

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
    Int arr1, arr2;
    arr1.setData(70);
    arr1.setData(100);
    arr1.setData(200);
    arr2 = arr1;
    cout << "arr1: ";
    arr1.show();
    cout << "arr2: ";
    arr2.show();
    arr1.change(0, 50);
    cout << "arr1: ";
    arr1.show();
    cout << "arr2: ";
    arr2.show();

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