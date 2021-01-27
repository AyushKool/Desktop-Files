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
#define FOR(start, end, inc) for(auto i =  start; i!=end; i+=inc)
ll dp[1000001];

const int MOD = (int)1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vll a(n);
    for(ll& i : a) cin >> i;
    ll ans = 0, mx = 0;
    FOR(0, sz(a), 1){
        mx = max(mx, a[i]);
        ans += mx - a[i];
    }
    cout << ans;
}