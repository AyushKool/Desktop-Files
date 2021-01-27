#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

ll dp[1000001];

const int MOD = (int) 1e9 + 7;
/*
CSES DP PROBLEMS EDITORIAL: https://codeforces.com/blog/entry/70018
GOOD ARTICLE ON MINIMUM COIN CHANGE: https://medium.com/@trykv/how-to-solve-minimum-coin-change-f96a758ccade

*/
int main(){
    
    int n, x; cin >> n >> x;
    vi coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i <= x; i++){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int sum = 0; sum <= x; sum++) {
            if(sum >= coins[i - 1]) {
                dp[sum] = min(dp[sum], dp[sum - coins[i - 1]] + 1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}