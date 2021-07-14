#include <bits/stdc++.h>
using namespace std;
class ZooAnimal
{
private:
    string nameOfAnimal;
    int birthYear;
    int cageNumber;
    float weight;
    int height;

public:
    ZooAnimal() : nameOfAnimal("Elephant"), birthYear(2000), cageNumber(206), weight(1800.00), height(13)
    {
    }
    void setName(string name)
    {
        nameOfAnimal = name;
    }
    void setCageNo(int num)
    {
        cageNumber = num;
    }
    void setWeight(float wt)
    {
        weight = wt;
    }
    void setHeight(float ht)
    {
        height = ht;
    }
    void setBirthYear(int year = 2021)
    {
        if (year > 2021)
            birthYear = 2021;
        else
            birthYear = year;
    }
    void getName(void)
    {
        cout << "Name of Animal: " << nameOfAnimal << endl;
    }
    void getBirthYear(void)
    {
        cout << "Birth Year: " << birthYear << endl;
    }
    void getCageNo(void)
    {
        cout << "Cage No: " << cageNumber << endl;
    }
    void getWeight(void)
    {
        cout << "Wight: " << weight << endl;
    }
    void getHeight(void)
    {
        cout << "Height: " << height << endl;
    }
    int getAge(void)
    {
        return (2021 - birthYear);
    }
    void getInformation(void)
    {
        cout << "Name of Animal: " << nameOfAnimal << endl;
        cout << "Birth Year: " << birthYear << endl;
        cout << "Cage No: " << cageNumber << endl;
        cout << "Wight: " << weight << endl;
        cout << "Height: " << height << endl;
    }
    int operator==(int data)
    {
        return (weight == data) ? 1 : 0;
    }
    void operator--(int dec)
    {
        height -= dec;
    }
};
int main(void)
{
    ZooAnimal animal1, animal2;
    animal1.getInformation();
    animal1.operator--(5);
    animal1.getHeight();
    if (animal1 == 70)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    cout << animal1.getAge() << endl;
    animal2.setBirthYear(2025);
    animal2.setCageNo(560);
    animal2.setHeight(12);
    animal2.setName("Panda");
    animal2.setWeight(1200);
    animal2.getBirthYear();
    animal2.getCageNo();
    animal2.getHeight();
    animal2.getName();
    animal2.getWeight();
}