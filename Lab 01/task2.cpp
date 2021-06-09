#include<bits/stdc++.h>
using namespace std;
class RationalNumber
{
private:
    int numerator;
    int denominator;
public:
    void assign(int numer,int denomi)
    {
        if(denomi!=0)
        {
            numerator=numer;
            denominator=denomi;
        }
        else
            cout<<"Mathematically Undefined!"<<endl;
    }
    double convert(void)
    {
        return ((double)numerator)/((double)denominator);
    }
    void invert(void)
    {
        if(numerator!=0)
            assign(denominator,numerator);
        else
            cout<<"Mathematically Undefined!"<<endl;
    }
    void print(void)
    {
        cout<<"The Rational Number is "<<numerator<<"/"<<denominator<<endl;
    }
};
int main(void)
{
    RationalNumber number;
    int num,den;
    cin>>num>>den;
    number.assign(num,den);
    if(den!=0)
    {
        number.print();
        cout<<"After Converting :"<<number.convert()<<endl;
        number.invert();
        number.print();
    }
}
