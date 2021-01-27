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
    string s;
    cin >> s;
    int f[26] = {0};
    for (char c : s)
        f[c - 'A']++;
    int odd_count = 0, odd_ind = -1;
    for (int i = 0; i < 26; i++)
        if (f[i] & 1)
            odd_count++, odd_ind = i;
    if (odd_count > 1)
        cout << "NO SOLUTION";
    else
    {
        string t = "";
        for (int i = 0; i < 26; i++)
        {
            if(f[i] < 1 || f[i]&1) continue;
            for (int j = 0; j < f[i] / 2; ++j)
                t += (char)(i + 'A');
        }
        cout << t;
        while (odd_ind > -1 && f[odd_ind]--)
            cout << (char)(odd_ind + 'A');
        reverse(all(t));
        cout << t;
    }
}