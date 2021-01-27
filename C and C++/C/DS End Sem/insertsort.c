#include <stdio.h>
#define N 30

void insertsort(int a[], int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && t < a[j])
            a[j + 1] = a[j], j--;
        a[j + 1] = t;
    }
}

int main()
{
    int a[N], n;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    insertsort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}