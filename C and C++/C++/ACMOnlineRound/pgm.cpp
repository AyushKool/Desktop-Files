#include <bits/stdc++.h>
using namespace std;

typedef map<string, pair<int, int>> msp;

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
        int n, sum = 0, c;
        rd(n);
        msp a;
        string s;
        msp::iterator it;
        for (int i = 0; i != n; i++)
        {
            cin >> s >> c;
            it = a.find(s);
            if (it == a.end())
            {
                a.insert(make_pair(s, make_pair(0, 0)));
                it = a.find(s);
            }
            if (c == 0)
                (it->second).first++;
            else
                (it->second).second++;
        }

        for (it = a.begin(); it != a.end(); it++)
            sum += max((it->second).first, (it->second).second);
        pt(sum, '\n');
    }
}
