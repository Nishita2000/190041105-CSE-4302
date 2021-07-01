#include <bits/stdc++.h>
using namespace std;
class calculator
{
private:
    int val;

public:
    calculator() : val(0) {}
    calculator(int v) : val(v) {}
    int getValue(void)
    {
        return val;
    }
    void setValue(int Value)
    {
        val = Value;
    }
    void display(void)
    {
        cout << "Calculator Display : " << val << endl;
    }
    void addValue(int Value)
    {
        val += Value;
        display();
    }
    void subtract(int Value)
    {
        val -= Value;
        display();
    }
    void multiply(int Value)
    {
        val *= Value;
        display();
    }
    void divideBy(int Value)
    {
        if (Value != 0)
            val /= Value;
        else
            cout << "Divide By 0 is undefined" << endl;
        display();
    }
    void clear(void)
    {
        val = 0;
    }
    ~calculator()
    {
        cout << "Calculator Object is destroyed" << endl;
    }
};
int main(void)
{
    calculator cal;
    cal.addValue(10);
    cal.addValue(7);
    cal.multiply(31);
    cal.subtract(42);
    cal.divideBy(7);
    cal.divideBy(0);
    cal.addValue(3);
    cal.subtract(1);
    cal.clear();
}