#include <stdio.h>
#define N 30

void selectsort(int a[], int n)
{
    int pos, min;
    for (int i = 0; i < n - 1; i++)
    {
        pos = i, min = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > a[j])
                min = a[j], pos = j;
        }
        a[pos] = a[i];
        a[i] = min;
    }
}

int main()
{
    int a[N], n;
    printf("Enter size: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    selectsort(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}