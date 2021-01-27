//https://www.codechef.com/ACMIND16/problems/ICPC16G
#include <bits/stdc++.h>
using namespace std;

void disp(vector<int> a)
{
    for (auto i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
}

void rrot(vector<int> &a, int k)
{
    rotate(a.begin(), a.begin() + a.size() - k, a.end());
}

bool xr(vector<int> a, vector<int> b, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] ^ b[i])
            return false;
    return true;
}

main()
{
    int n, m, i, count = 0, tmp;
    cin >> n >> m;
    vector<int> a(n, 0), b(n, 0);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        b[tmp] = 1;
    }
    while (n--)
    {
        if (xr(a, b, n))
            count++;
        rrot(b, 1);
    }
    cout << "\n\n"
         << count;
}