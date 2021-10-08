#include <bits/stdc++.h>
using namespace std;
template <typename T>

T amax(T arr[], int size, int n)
{
    T brr[size];
    copy(arr, arr + size, brr);
    sort(brr, brr + size, greater<T>());
    return brr[n - 1];
}
int main()
{
    int arr[] = {5, 18, 32, 195, 6, 44};
    cout << amax(arr, 6, 2) << endl;
}