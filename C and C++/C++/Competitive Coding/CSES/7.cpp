#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
#define FOR(start, end, inc) for (auto i = start; i != end && i < end; i += inc)
ll dp[1000001];

const int MOD = (int)1e9 + 7;

ll solve(const int &n)
{
    ll ans = n * n;
    ans = ans * (ans - 1)/2;
    ans -= 4 * (n - 1) * (n - 2);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    FOR(1, n + 1, 1)
        cout << solve(i) << endl;
}