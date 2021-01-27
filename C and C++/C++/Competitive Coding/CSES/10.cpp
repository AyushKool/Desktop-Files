#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<ll>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define F first
#define S second
#define mp make_pair
#define FOR(start, end, inc) for (auto i = start; i != end && i < end; i += inc)
ll dp[1000001];

const int MOD = (int)1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=5; i<=n; i*=5){
        
        ans += n/i;
    }
    cout << ans;
}