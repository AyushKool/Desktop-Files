/*
https://codeforces.com/contest/1366/problem/A
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    unsigned short t;
    cin >> t;
    while (t--)
    {
        int a, b, em = 0, diff;
        cin >> a >> b;
        diff = abs(a-b);
        // cout << min({a, b, (a+b)/3}, comp) << endl;
        if (diff > min(a, b))
        {
            cout << min(a, b) << endl;
            continue;
        }
        
        if (a != b)
            em += diff, a = min(a,b) - diff;
        em += 2*a/3;

        cout << em << endl;
    }
}