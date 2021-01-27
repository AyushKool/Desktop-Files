#include <stdio.h>

void main()
{
    int n, a, b, count = 1;
    scanf("%d%d", &n, &a);

    while (--n)
    {
        scanf("%d", &b);
        if (b > a)
            count++;
        a = b;
    }
    printf("%d", count);
}