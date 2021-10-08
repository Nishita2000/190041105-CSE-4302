#include <bits/stdc++.h>
using namespace std;
namespace space
{
    int x = 14;
}
namespace my_namespace
{
    int x = 7;
}
int main(void)
{
    int x = 20;
    cout << x << endl;
    cout << space::x << endl;
    cout << my_namespace::x << endl;
}