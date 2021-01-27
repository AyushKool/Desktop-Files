#include <iostream>
using namespace std;

template <typename T>
void rd(T &x)
{
    int f = 0, c;
    while ((c = getchar()) < 48 || 57 < c)
        f ^= !(c ^ 45); //'-' ASCII is 45
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

int main()
{
    int x;
    rd(x);
    pt(x);
}