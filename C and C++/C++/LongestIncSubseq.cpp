#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi val;
//returns length of longest increasing subsequence with last index as k-1
int lis(const vi &v, int k)
{
    if (k < 0)
        return 0;
    if (k == 0)
        return 1;
    if (val[k]!=0)
        return val[k];
    int longest = 1;
    for (int i = 0; i != k+1; i++)
    {
        for (int j = 0; j != i; j++)
            if (v[j] < v[i])
                longest = max(longest, lis(v, j) + 1);
    }
    val[k] = longest;
    return longest;
}

main()
{
    vi v = {6,2,5,1,7,4,8,3};
    val = vi(v.size(), 0);
    for (int i=0; i!=v.size(); i++)
        cout << lis(v, i) << endl;
}