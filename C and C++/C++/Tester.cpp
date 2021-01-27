#include <bits/stdc++.h>
using namespace std;

typedef set<int> si;
typedef set<si> sii;

void disp(vector<int> a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
}

bool cmp(int a, int b)
{
    return __builtin_popcount(a) < __builtin_popcount(b);
}

int *f()
{
    int a, *p;
    cout << "Value of a is " << a << endl;
    p = &a;
    return p;
}

int poww(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2)
        return a * poww(a, b - 1);
    else
        return a * a * poww(a, b / 2);
}

void power(int n)
{
    if (n == 0)
        cout << "1 ";
    power(n - 1);
    cout << poww(2, n - 1) << " ";
}

int main()
{
    // cout << poww(2, 5);
    // int *a = f();
    // *a = 7;
    // f();
    // int a;
    // cin >> a;
    // cout << a;
    // vector<int> v = {1,2,3,4,5,6,7,8,9};
    // stable_sort(v.begin(), v.end(), cmp);
    // disp(v);

    sii eq;
    si a, b;
    for(int i=0; i < 10; i++)
    {
        // if (i < 10)
        //     a.insert(i);
        // else
        //     b.insert(i);

        a.insert(i);
        b.insert(i);
    }
    eq.insert(a);
    eq.insert(b);
    for(si s : eq)
    {
        for (auto x : s)
        {
            x = 0;
        }
        for (auto x : s)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}