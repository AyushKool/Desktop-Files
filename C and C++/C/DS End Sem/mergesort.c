#include <stdio.h>
#define N 30

void merge(int a[], int l, int m, int h)
{
    int i = l, j = m + 1, t[h - l + 1], k = 0;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }
    while (i <= m)
        t[k++] = a[i++];
    while (j <= h)
        t[k++] = a[j++];
    for (i = l, k = 0; i <= h; i++, k++)
        a[i] = t[k];
}

void mergesort(int a[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

int main()
{
    int a[N], n;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}