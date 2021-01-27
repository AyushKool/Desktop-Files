#include <bits/stdc++.h>
using namespace std;
#define tr(c, i) for(typeof(c.begin())i = c.begin(); i!=c.end(); i++)
typedef vector<int> vi;
vi v;
vi val;

int solve(int ind, int k) //till index ind (including)
{
    if (val[ind] != -1)
        return val[ind];
    int l = val[0];
    for (int i = 1; i != ind + 1; i++)
    {
        for (int j = 0; j != i; j++)
        {
            if ((v[i] + v[j]) % k != 0)
                l = max(solve(j, k) + 1, l);
            else
                continue;
        }
    }
    val[ind] = l;
    return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //v = {19, 10, 12, 10, 24, 25, 22};
    int n, k, i;
    cin >> n >> k;
    while(n--)
    {
        cin >> i;
        v.push_back(i);
    }
    val = vi(v.size(), -1);
    val[0] = (v[0] % k ? 1 : 0);
    
    cout << solve(v.size()-1, k) << endl;
    tr(val, i)
        cout << *i << " ";
    return 0;
}

/*
6 9
422346306 940894801 696810740 862741861 85835055 313720373

5
*/