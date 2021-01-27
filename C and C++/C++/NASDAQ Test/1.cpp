#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int, int>;
#define mp make_pair

int solve(string &s)
{
    if (sz(s) == 1)
        return 1;
    if (sz(s) == 0)
        return 0;
    string r = "";
    int count = 0;
    for (size_t i = 0; i < sz(s) - 1; i++)
    {
        int a = s[i] - 48, b = s[i + 1] - 48;
        // cout << a << b << endl;
        while (i+1<sz(s) && (a - b))
        {
            i++;
            a = b, b = s[i + 1] - 48;
        }
        if(i >= sz(s)-1 && s[i]-s[i+1]) break;
        r = r + s[i+1];
        // cout << r << endl;
    }
    return solve(r) + 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        unsigned n;
        cin >> n;
        string s("", n);
        char ch;
        for (auto i = 0; i < n; i++)
            cin >> ch, s[i] = ch;
        cout << solve(s) << endl;
        // cout << s << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}