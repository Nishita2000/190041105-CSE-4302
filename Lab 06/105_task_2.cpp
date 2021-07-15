#include <bits/stdc++.h>
using namespace std;
class FLOAT
{
private:
    float data;

public:
    FLOAT() {}
    FLOAT(float d) : data(d)
    {
    }
    void setValue(float d)
    {
        data = d;
    }
    void Display(void)
    {
        cout << "Data: " << data << endl;
    }
    FLOAT operator+(FLOAT f)
    {
        return FLOAT(data + f.data);
    }
    FLOAT operator-(FLOAT f)
    {
        return FLOAT(data - f.data);
    }
    FLOAT operator*(FLOAT f)
    {
        return FLOAT(data * f.data);
    }
    FLOAT operator/(FLOAT f)
    {
        if (f.data != 0)
            return FLOAT(data / f.data);
        else
        {
            cout << "Invalid" << endl;
            return FLOAT(data);
        }
    }
    operator int() const
    {
        return int(data);
    }
};

int main(void)
{
    FLOAT f1(5.7), f2(9.8), f3, f4;
    f3.setValue(4.33);
    f1.Display();
    f2.Display();
    f3.Display();
    f4 = f1 + f2;
    f4.Display();
    f4 = f1 - f3;
    f4.Display();
    f4 = f1 * f2;
    f4.Display();
    f4 = f2 / f3;
    f4.Display();
    int i = f2;
    cout << "Int: " << i << endl;
}