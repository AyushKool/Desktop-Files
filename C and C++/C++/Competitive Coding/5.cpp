#include <iostream>
#include <cstdio>
using namespace std;
#define MOD 10000007
int main()
{
    //    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long solve[103][103];
    int i = 0, j = 0;
    for (i = 0; i < 102; i++)
    {
        solve[i][0] = 1;
        solve[i][i] = 1;
    }
    for (i = 1; i < 102; i++)
        for (j = 1; j < 102; j++)
            if (i != j)
                solve[i][j] = (solve[i - 1][j] % MOD + solve[i - 1][j - 1] % MOD) % MOD;
    int n, r;
    scanf("%d%d", &n, &r);
    if (n < r)
        printf("-1\n");
    else
    {
        printf("%lld", solve[n - 1][r - 1] % MOD);
    }
    return 0;
}