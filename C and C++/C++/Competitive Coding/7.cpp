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

vi dp;
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

bool lMin(const int &i)
{
    return dp[i] < dp[i - 1] && dp[i] < dp[i + 1];
}
bool lMax(const int &i)
{
    return dp[i] > dp[i - 1] && dp[i] > dp[i + 1];
}

// Complete the candies function below.
long candies(const vi &a)
{
    int n = a.size();
    if (n < 2)
        return 1;
    dp = vi(n, 1);

    for (int i = 1; i <= n - 1; ++i)
    {
        if (a[i] > a[i - 1])
            dp[i] = dp[i - 1] + 1;
    }
    for (int i = n-1; i >-1; --i)
    {
        if (a[i] > a[i + 1])
            dp[i] = max(dp[i + 1] + 1, dp[i]);
    }
    unsigned long s = 0;
    for(int i : dp) s+=i;
    return s;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    long result = candies(a);
    cout << result << "\n";
    return 0;
}
