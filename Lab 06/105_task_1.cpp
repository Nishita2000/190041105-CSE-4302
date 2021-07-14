#include <bits/stdc++.h>
using namespace std;
class Coordinate
{
private:
    float abscissa;
    float ordinate;

public:
    Coordinate(float x, float y) : abscissa(x), ordinate(y)
    {
    }
    float getDistance(void)
    {
        return sqrt(powf(abscissa, 2) + powf(ordinate, 2));
    }
    float getDistance(Coordinate c)
    {
        return sqrt(powf((abscissa - c.abscissa), 2) + powf((ordinate - c.ordinate), 2));
    }
    void move_x(float val)
    {
        abscissa += val;
    }
    void move_y(float val)
    {
        ordinate += val;
    }
    void move(float val)
    {
        move_x(val);
        move_y(val);
    }
    void Display(void)
    {
        cout << "Abscissa: " << abscissa << " "
             << "Ordinate: " << ordinate << endl;
    }
    Coordinate operator++()
    {
        return Coordinate(++abscissa, ++ordinate);
    }
    Coordinate operator--()
    {
        return Coordinate(--abscissa, --ordinate);
    }
    Coordinate operator++(int)
    {
        return Coordinate(abscissa++, ordinate++);
    }
    Coordinate operator--(int)
    {
        return Coordinate(abscissa--, ordinate--);
    }
    bool operator>(Coordinate c)
    {
        return getDistance() > c.getDistance();
    }
    bool operator>=(Coordinate c)
    {
        return getDistance() >= c.getDistance();
    }
    bool operator<(Coordinate c)
    {
        return getDistance() < c.getDistance();
    }
    bool operator<=(Coordinate c)
    {
        return getDistance() <= c.getDistance();
    }
    bool operator==(Coordinate c)
    {
        return getDistance() == c.getDistance();
    }
    bool operator!=(Coordinate c)
    {
        return getDistance() != c.getDistance();
    }
    ~Coordinate()
    {
    }
};
int main(void)
{
    Coordinate c1(3.5, 9), c2(4, 6.7);
    cout << "Distance from origin: " << c1.getDistance() << endl;
    cout << "Distance from another object: " << c1.getDistance(c2) << endl;
    c1.move(5);
    c1++;
    --c2;
    c1.Display();
    c2.Display();
    if (c1 != c2)
        cout << "Not equal" << endl;
    else
        cout << "Equal" << endl;
}