//https://www.codechef.com/OCT19A/problems/S10E

#include <bits/stdc++.h>
using namespace std;
#define VI vector<short>
main()
{
    short t;
    cin >> t;
    while (t--)
    {
        short n, price, count = 1, last = 0, i = 0;
        cin >> n;
        VI v(n);
        if (!n)
            continue;
        cin >> price;
        v[i++] = price;
        while (--n)
        {
            cin >> price;
            v[i++] = price;
            if (i - last > 5)
            {
                count++;
                last = i;
            }
        }
        cout << count << "\n";
    }
}