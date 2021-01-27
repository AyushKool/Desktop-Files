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
#define F first
#define S second
#define mp make_pair
#define FOR(start, end, inc) for (auto i = start; i != end && i < end; i += inc)
ll dp[1000001];

const int MOD = (int)1e9 + 7;

int main()
{
    int n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum & 1)
        cout << "NO";
    else
    {
        //n mod 4 is 0 or 3
        vi a, b;
        int j = n % 4 ? 3 : 4;

        FOR(0, (n - 1) / 4, 1)
        {
            a.push_back(4 * i + 1 + j);
            a.push_back(4 * i + 4 + j);
            b.push_back(4 * i + 2 + j);
            b.push_back(4 * i + 3 + j);
        }

        if (n % 4) //n mod 4 = 3
        {
            a.push_back(1);
            a.push_back(2);
            b.push_back(3);
        }
        else //n mod 4 = 0
        {
            a.push_back(1);
            a.push_back(4);
            b.push_back(2);
            b.push_back(3);
        }
        cout << "YES";
        cout << "\n"
             << a.size() << "\n";
        for (int i : a)
            cout << i << " ";
        cout << "\n"
             << b.size() << "\n";
        for (int i : b)
            cout << i << " ";
    }
}