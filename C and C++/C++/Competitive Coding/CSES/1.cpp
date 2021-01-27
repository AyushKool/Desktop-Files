#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

ll dp[1000001];

const int MOD = (int)1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    cout << n;
    while (n > 1)
    {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        cout << " " << n;
    }
}