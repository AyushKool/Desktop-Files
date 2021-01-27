#include <stdio.h>
#define N 30

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void quicksort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r, piv = a[l];
    while (i < j)
    {
        while (a[i] <= piv)
            i++;
        while (a[j] > piv)
            j--;
        if (i < j)
            swap(a + i, a + j);
    }
    a[l] = a[j];
    a[j] = piv;
    quicksort(a, l, j - 1);
    quicksort(a, j + 1, r);
}

int main()
{
    int a[N], n;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}