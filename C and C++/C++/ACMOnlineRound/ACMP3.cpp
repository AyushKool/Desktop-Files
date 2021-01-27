#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(), c.end()
typedef map<char, int> mci;
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
int main()
{
    int t;
    rd(t);

    while (t--)
    {
        int k, n;
        rd(n), rd(k);
        mci ans;
        string s, p;
        cin >> s;
        mci::iterator it;

        for (int i = 0; i != k; i++)
        {
            cin >> p;
            for (int j = 0; j != p.size(); j++)
                ans.insert(make_pair(p[j], i + 1));
        }

        for (int i = 0; i != n; i++)
        {
            it = ans.find(s[i]);
            pt(it->second, ' ');
        }
        putchar('\n');
    }
}
