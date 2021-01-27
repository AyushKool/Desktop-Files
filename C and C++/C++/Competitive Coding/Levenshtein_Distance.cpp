#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
// #define N (int)(1e7 + 7)
#define N 200

unsigned short dp[N][N];
const int Cr = 1, Ci = 1, Cd = 1;

void print(int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}

//Time: O(nm) | Space: O(nm)
int solve(string &a, string &b)
{
    int n = a.size() + 1, m = b.size() + 1;
    iota(*dp, (unsigned short *)(dp + 1), 0);
    for (int i = 1; i < n; ++i)
        dp[i][0] = i;

    // print(n,m);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (a[i - 1] == b[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min({Cr + dp[i - 1][j - 1], Ci + dp[i][j - 1], Cd + dp[i - 1][j]}, [](int a, int b) -> bool { return a < b; });
        }
    }

    // print(n,m);
    // cout << endl << **dp << " " << **(dp + 1)<< endl;

    return dp[n - 1][m - 1];
}

int main()
{
    // string a, b;
    // cin >> a >> b;
    // cout << solve(a, b);

    // cout << ((dp+1) - (dp)) << endl;
    cout << dp + 1 << ' ' << *dp + 200;
    // cout << ((*dp+1) - (*dp)) << endl;
    // cout << sizeof(unsigned short);
}