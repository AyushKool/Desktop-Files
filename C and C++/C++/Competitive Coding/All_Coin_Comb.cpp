#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vb = vector<bool>;
using vvb = vector<vb>;

#define pb push_back
#define rsz resize
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define mp make_pair

void print(const vvi &v)
{
    for (vi a : v)
    {
        for (int b : a)
            cout << b << " ";
        cout << endl;
    }
}
void print(const vi &v)
{
    for (int a : v)
        cout << a << " ";
    cout << endl;
}

int solve(const vi &c, int amt)
{
    int n = c.size();
    int dp[amt + 1];
    fill(dp, dp + amt + 1, 0);
    dp[0] = 1;
    // print(vi(dp, dp + amt + 1));
    for (int j = 0; j < n; ++j)
    {
        for (int i = 1; i <= amt; ++i)
        {

            if (c[j] <= i)
            {
                dp[i] += dp[i - c[j]];
                // dp[i]++;
            }
        }
    }
    // print(vi(dp, dp + amt + 1));

    return dp[amt];
}

int main()
{
    int n, amt;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> amt;
    cout << solve(a, amt);
    return 0;
}
