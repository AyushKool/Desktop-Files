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

int main()
{
    ll n;
    cin >> n;
    if(n==1){cout << 1; return 0;}
    if(n==2||n==3){cout << "NO SOLUTION"; return 0;}
    if(n%2)//odd
    {
        FOR(1, n+1, 2)
        {
            cout << i << " ";
        }
        FOR(2, n, 2)
        {
            cout << i << " ";
        }
    }
    else
    {
        FOR(2, n+1, 2)
        {
            cout << i << " ";
        }
        FOR(1, n, 2)
        {
            cout << i << " ";
        }
    }
    
}