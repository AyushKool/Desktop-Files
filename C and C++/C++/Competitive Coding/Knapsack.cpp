#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define mp make_pair

void print(const vvi &v)
{
    for (vi a : v)
    {
        for (int b : a)
            cout << b << " ";
        cout << endl;
    }
}
void print(const vi &v)
{
    for(int a: v) cout << a << " ";
    cout << endl;
}

void solve(const vvi &items, int sum)
{
    int n = sz(items);
    vvi val(n + 1, vi(sum + 1, 0));
    // print(val);
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 0; j <= sum; j++)
        {
            if (j >= items[i - 1][1])
                val[i][j] = max(val[i - 1][j], val[i - 1][j - items[i - 1][1]] + items[i - 1][0]);
            else
                val[i][j] = val[i - 1][j];
        }
    }
    // print(val);
    vi usedItems;
    for (size_t i = n, j = sum; j > 0 && i > 0; i--)
    {
        if (val[i][j] != val[i - 1][j])//i-1th item was used
        {
            j -= items[i - 1][1];
            usedItems.pb(i - 1);
        }
    }
    reverse(all(usedItems));
    print(usedItems);
}

int main()
{
    int n = 4, sum = 10;
    vvi items(n, vi(2, 0));
    items = {{1, 2}, {4, 3}, {5, 6}, {6, 7}}; //{value, weight}
    // print(items);
    solve(items, sum);
    return 0;
}
