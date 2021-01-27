#include <iostream>

using namespace std;

//Tower Of Hanoi
void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
        printf("%c->%c\n", a, c);
    else
    {
        hanoi(n - 1, a, c, b);
        hanoi(1, a, b, c);
        hanoi(n - 1, b, a, c);
    }
}

//Greatest Common Factor/Divisor
int gcf(int a, int b)
{
    if (!b)
        return a;
    else if (b == 1)
        return 1;
    return gcf(b, a % b);
}

//Ackermann Function
int ack(int a, int b)
{
    if (!a)
        return b + 1;
    else if (a > 0 && !b)
        return ack(a - 1, 1);
    return ack(a - 1, ack(a, b - 1));
}

int main()
{
    // printf("%d\n", ack(2,1));
    // printf("%d", gcf(3,6));
    // hanoi(3, 'a', 'b', 'c');
}