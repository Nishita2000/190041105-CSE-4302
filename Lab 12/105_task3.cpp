#include <bits/stdc++.h>
using namespace std;
const int MAX = 2;
template <typename T>
class my_stack
{
private:
    T arr[MAX];
    int top;

public:
    my_stack() : top(-1) {}
    class Full
    {
    };
    class Empty
    {
    };
    int size(void)
    {
        return top;
    }
    void push(T data)
    {
        if (top == MAX - 1)
            throw Full();
        else
            arr[++top] = data;
    }
    T pop(void)
    {
        if (top == -1)
            throw Empty();
        else
            return arr[top--];
    }
    T peek(void)
    {
        if (top == -1)
            return Empty();
        else
            return arr[0];
    }
};

int main(void)
{
    try
    {
        my_stack<int> s1;
        my_stack<float> s2;
        s1.push(8);
        s1.push(100);
        s1.push(400);
        while (s1.size() >= 0)
            cout << s1.pop() << endl;

        s2.push(9.782);
        s2.push(123.45);
        s2.push(5.8);
        while (s2.size() >= 0)
            cout << s2.pop() << endl;
    }
    catch (my_stack<int>::Full)
    {
        cout << "Exception : Stack Overflow" << endl;
    }
    catch (my_stack<int>::Empty)
    {
        cout << "Exception : Stack Underflow" << endl;
    }
    catch (my_stack<float>::Full)
    {
        cout << "Exception : Stack Overflow" << endl;
    }
    catch (my_stack<float>::Empty)
    {
        cout << "Exception : Stack Underflow" << endl;
    }
}
