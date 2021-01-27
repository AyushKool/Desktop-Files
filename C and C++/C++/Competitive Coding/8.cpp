#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
//https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
//Solution: https://medium.com/swlh/smallest-missing-positive-integer-in-an-array-b6f197e78a16

void print(int *a, int n)
{
    for(int i=0; i<n; i++) cout << a[i] << " ";
    cout << endl;
}

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int find(int *a, int end, int n)
{
    for (int i = 0; i < end; ++i)
        if(a[i] > 0 && a[a[i] - 1] > 0)
            a[a[i] - 1] = -a[a[i] - 1];
    print(a, n);
    for (int i = 0; i < n; ++i)
        if (a[i] > 0)
            return i + 1;
    return n + 1;
}

void filter(int *a, int n)
{
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (a[start] >= 1 && a[start] <=n)
            start++;
        else
            swap(a[start], a[end--]);
    }
    if (n - start < 1)
        cout << 1 << endl;
    print(a, n);
    cout << find(a, start, n) << endl;
}

int main(void)
{
    int n = 7;
    // cin >> n;
    int a[n] = {1, -2, 3, -4, 5, -6, 7};
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    filter(a, n);
    return 0;
}