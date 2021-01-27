#include <stdio.h>
#define N 30

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a + j, a + j + 1);
        }
    }
}

int main()
{
    int a[N], n;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    bubblesort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}