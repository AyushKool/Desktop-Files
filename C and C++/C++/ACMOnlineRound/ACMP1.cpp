#include <bits/stdc++.h>
#include <cstring>
//#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define all(c) (c).begin(), (c).end()
#define tr(c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)
template <typename T>
void rd(T &x)
{
    int f = 0, c;
    while ((c = getchar()) < 48 || 57 < c)
        f ^= !(c ^ 45);
    x = (c & 15);
    while (47 < (c = getchar()) && c < 58)
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

template <typename T>
inline void pt(T x, int c) { pt(x), putchar(c); }

template <typename T>
inline T max(const T &x, const T &y) { return x < y ? y : x; }

template <typename T>
inline T min(const T &x, const T &y) { return x < y ? x : y; }

int main()
{
    int t;rd(t);
    while(t--)
    {
        
    }
    return 0;
}