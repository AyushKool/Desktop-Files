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
    string s;
    cin >> s;
    int c = 1, max = 1;
    for (auto i = 0; i <= sz(s) - 2; i++, c = 1)
    {
        while (i <= sz(s) - 2 && s[i] == s[i + 1])
            c++, i++;
        
        if (c > max)
            max = c;
    }
    cout << max;
}