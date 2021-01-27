//https://codeforces.com/problemset/problem/634/A
#include <stdio.h>
#define maxn 200000
int n, a[maxn], b[maxn];
int main()
{
    while (~scanf("%d", &n))
    {
        int p1, p2;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] == 1)
                p1 = i;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &b[i]);
            if (b[i] == 1)
                p2 = i;
        }
        int gg = 0;
        for (int i = p1, j = p2, k = 0; k < n; i = (i + 1) % n, j = (j + 1) % n, k++)
        {
            if (a[i] == 0)
                i = (i + 1) % n;
            if (b[j] == 0)
                j = (j + 1) % n;
            if (a[i] != b[j])
            {
                gg = 1;
                break;
            }
        }
        printf("%s\n", gg ? "NO" : "YES");
    }
}