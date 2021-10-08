#include <bits/stdc++.h>
using namespace std;
const int MAX = 200;
template <typename T>
class my_stack
{
private:
    T arr[MAX];
    int top;

public:
    my_stack() : top(-1) {}
    int size(void)
    {
        return top;
    }
    void push(T data)
    {
        arr[++top] = data;
    }
    T pop(void)
    {
        return arr[top--];
    }
    T peek(void)
    {
        return arr[0];
    }
};
int main(void)
{
    my_stack<int> s1;
    s1.push(8);
    s1.push(100);
    s1.push(400);
    while (s1.size() >= 0)
        cout << s1.pop() << endl;

    my_stack<float> s2;
    s2.push(9.782);
    s2.push(123.45);
    s2.push(5.8);
    while (s2.size() >= 0)
        cout << s2.pop() << endl;
}
