#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    set<int> s;
    int arr[8];
    for (int i = 0; i < 16; i++)
    {
        if (i % 2)
            s.insert(i);
        else
            arr[i / 2] = i;
    }
    vector<int> v(16);
    merge(arr, arr + 8, s.begin(), s.end(), v.begin());
    for (int i : v)
        cout << i << " ";
}
