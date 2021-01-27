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

int sh(vi& v)
{
    auto i = sz(v);
    while(i>0 && !(v[i] - v[i-1]))i--;
    if(i==0) return v[0];
    return v[i-1];
}

int solve(vi &v)
{
    sort(all(v));
    int sum = 0, i=2;
    while(i<sz(v))
    {
        vi a(v.begin()+i, v.begin()+i+3);
        sum += sh(a);
        cout << sh(a);
        i+=4;
    }
    return sum;
}



int main()
{
    unsigned int n;
    cin >> n;
    vi a(n);
    for (auto i = 0; i < n; i++)
        cin >> a[i];
    cout << endl;
    cout << solve(a);
    return 0;
}