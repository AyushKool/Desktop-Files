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
    ll n,s=0;
    cin >> n;

    for (size_t i = 0; i < n-1; i++)
    {
        int a;
        cin >> a;
        s+=a;
    }
    cout << n*(n+1)/2 - s;
}