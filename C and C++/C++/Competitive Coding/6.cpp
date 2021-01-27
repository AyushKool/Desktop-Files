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
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define mp make_pair
//https://www.hackerrank.com/challenges/abbr/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
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

bool isSame(const char &a, const char &b)
{
    return a == b || abs(a - b) == 32;
}

bool isLower(const char &a)
{
    return a > 90 && a < 123;
}
// Complete the abbreviation function below.
string abbreviation(const string &a, const string &b)
{

    int n = a.size(), m = b.size();
    if (m > n)
        return "NO";
    vvb dp(n + 1, vb(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        if (isLower(a[i - 1]) && dp[i - 1][0])
            dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= min(i, m); ++j)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            if (isLower(a[i - 1]))
            {
                if (isSame(a[i - 1], b[j - 1]))
                    dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
                else if (dp[i - 1][j])
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m] ? "YES" : "NO";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(t--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
         cout << abbreviation(a, b) << "\n";
    }
    return 0;
}