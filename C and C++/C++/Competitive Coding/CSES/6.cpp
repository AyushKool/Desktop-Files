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
#define FOR(start, end, inc) for(auto i =  start; i!=end && i<end; i+=inc)
ll dp[1000001];

const int MOD = (int)1e9 + 7;

//https://www.programmingresources.tech/2020/08/cses-number-spiral-problem-solution.html
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll x, y;
        cin >> y >> x;
        ll z = max(x, y);
        ll nn = z*(z-1) + 1;
        ll ans = z%2 ? nn + x-y : nn + y-x; 
        cout << ans << endl;
    }
}