#include <bits/stdc++.h>
using namespace std;
class Employee
{
private:
    string name;
    int age, salary;

public:
    Employee() {}
    Employee(string nam, int c, int sal) : name(nam), age(c), salary(sal) {}
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
};

class Developer : public Employee
{
private:
    string company;

public:
    Developer() {}
    Developer(string nam, int c, int sal, string d) : Employee(nam, c, sal), company(d) {}
    // It's not mendatory to overload virtual function in child class
    void setData(void)
    {
        Employee::setData();
        cout << "Enter company name: ";
        cin >> company;
    }
    // It's compulsory to define pure virtual function in child class
    void showData(void)
    {
        Employee::info();
        cout << "Company: " << company << endl;
    }
};

class Teacher : public Employee
{
private:
    string institution;

public:
    Teacher() {}
    Teacher(string nam, int c, int sal, string d) : Employee(nam, c, sal), institution(d) {}
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
int main(void)
{
    // Employee emp;  //Can't make object from abstract class
    Employee *emp[2];
    emp[0] = new Developer("Faria", 20000, 24, "Grameenphone");
    emp[1] = new Teacher();
    emp[0]->showData();
    emp[1]->setData();
    emp[1]->showData();
}
