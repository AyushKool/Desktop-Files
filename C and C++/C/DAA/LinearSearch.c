#include <stdio.h>

void Recursive(int *a, int i, int n, int k)
{
    if (i == n)
        printf("\nNot Present.\nNumber of Comparisons: %d\n", n);
    else if (a[i] == k)
        printf("\nPresent.\nNumber of Comparisons: %d\n", i + 1);
    else
        i++, Recursive(a, i + 1, n, k);
}

void Iterative(int *a, int n, int k)
{
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == k)
        {
            printf("\nPresent.\nNumber of Comparisons: %d\n", i + 1);
            return;
        }
    }
    printf("\nNot Present.\nNumber of Comparisons: %d\n", n);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], k;
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        scanf("%d", &k);
        Recursive(a, 0, n, k);
    }
    return 0;
}