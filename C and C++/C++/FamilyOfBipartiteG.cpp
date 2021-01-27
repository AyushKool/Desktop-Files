#include <bits/stdc++.h>
#define N 1000000007LL
#define int long long
template <typename T>
inline T max(const T &x, const T &y) { return x < y ? y : x; }

template <typename T>
inline T min(const T &x, const T &y) { return x < y ? x : y; }

template <typename T>
void rd(T &x)
{
    int f = 0, c;
    while ((c = getchar()) < 48 || 57 < c)
        f ^= !(c ^ 45);
    x = (c & 15);
    while (47 < (c = getchar(

    )) && c < 58)
        x = x * 10 + (c & 15);
    if (f)
        x = -x;
}

template <typename T>
inline void pt(T x)
{
    if (x < 0)
        x = -x, putchar('-');
    if (x > 9)
        pt(x / 10);
    putchar(x % 10 + 48);
}

signed main()
{
    int t;
    rd(t);
    while(t--)
    {
        int n, m;
        rd(n), rd(m);
        if (n==1 || m==1)
        {
            puts("1");
            continue;
        }
        else
        {
            int a = min(n,m), b = max(n, m);
            int ans = 1+(a%N)*((a-1)%N)*((b-1)%N)*((b+2)%N)/2;
            pt(ans);
        }
        
    }
    return 0;
}