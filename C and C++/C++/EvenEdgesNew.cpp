#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

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

const int N = 1000005;

int n, m, T, ans[N], d[N];

signed main()
{
    rd(T);
    while (T--)
    {
        rd(n), rd(m);
        rep(i, 1, n) ans[i] = 1, d[i] = 0;
        int uu, vv;
        rep(i, 1, m)
        {
            int u, v;
            rd(u), rd(v);
            ++d[u], ++d[v];
            uu = u, vv = v;
        }
        if (m & 1)//if m is odd
        {
            bool flag = 0;
            rep(i, 1, n) if (d[i] & 1)//if degree of ith node is odd
            {
                ans[i] = 2;
                flag = 1;
                break;
            }
            if (flag)
                puts("2");
            else
            {
                puts("3");
                ans[uu] = 2;
                ans[vv] = 3;
            }
        }
        else
            puts("1");
        rep(i, 1, n) pt(ans[i], ' ');
    }
    return 0;
}