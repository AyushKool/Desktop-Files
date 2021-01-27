#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL read()
{
    LL k = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        k = k * 10 + c - 48, c = getchar();
    return k * f;
}

int du[100010], head[100010], tot;
struct zzz
{
    int t, nex;
} e[100010 << 1];

inline void add(int x, int y)
{
    e[++tot].t = y;
    e[tot].nex = head[x];
    head[x] = tot;
}

int main()
{
    int t = read();
    while (t--)
    {
        int n = read(), m = read();
        tot = 0;
        for (int i = 1; i <= n; ++i)
            du[i] = 0, head[i] = 0;
        for (int i = 1; i <= m; ++i)
        {
            int x = read(), y = read();
            ++du[x], ++du[y];
            add(x, y);
            add(y, x);
        }
        if (!(m & 1))
        {
            printf("1\n");
            for (int i = 1; i <= n; ++i)
                printf("1 ");
        }
        else
        {
            bool flag = 0;
            for (int i = 1; i <= n; ++i)
                if (du[i] & 1)
                    flag = 1;
            if (flag)
            {
                flag = 0;
                printf("2\n");
                for (int i = 1; i <= n; ++i)
                    if ((du[i] & 1) && flag == 0)
                        printf("2 "), flag = 1;
                    else
                        printf("1 ");
            }
            else
            {
                int pos = 0;
                for (int x = 1; x <= n; ++x)
                    if (du[x])
                    {
                        for (int i = head[x]; i; i = e[i].nex)
                            --du[e[i].t];
                        pos = x;
                        break;
                    }
                printf("3\n");
                for (int i = 1; i <= n; ++i)
                    if (i == pos)
                        printf("3 ");
                    else if ((du[i] & 1) && flag == 0)
                        printf("2 "), flag = 1;
                    else
                        printf("1 ");
            }
        }
        printf("\n");
    }
    return 0;
}