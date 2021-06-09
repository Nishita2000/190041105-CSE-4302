#include<bits/stdc++.h>
using namespace std;
class Product
{
private:
    string name;
    double discountPercent, unitPrice;
public:
    Product() : unitPrice(10),discountPercent(0.5)
    {

    }
    void assignName(string s)
    {
        name=s;
    }
    void setPrice(double price)
    {
        if(price>=0)
            unitPrice=price;
    }
    void setDiscPercent(double percent)
    {
        if(percent>=0 && percent<=10)
            discountPercent=percent;
    }
    double getSellingPrice(int nos)
    {
        return (unitPrice-((unitPrice*discountPercent)/100)) * nos;
    }
    void display(void)
    {
        cout<<name<<" has a unit price BDT "<<unitPrice<<".Current discount "<<discountPercent<<"%."<<endl;
    }
};
int main(void)
{
    Product x1,x2;
    x1.assignName("Pepsi");
    x1.setPrice(30);
    x1.setDiscPercent(7);
    x1.display();
    cout<<"Price: "<<x1.getSellingPrice(5)<<endl;
    x2.assignName("Noodles");
    x2.setPrice(80);
    x2.setDiscPercent(11);
    x2.display();
    cout<<"Price: "<<x2.getSellingPrice(2)<<endl;
}
