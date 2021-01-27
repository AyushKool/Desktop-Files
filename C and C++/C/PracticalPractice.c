#include <stdio.h>
#include <stdlib.h>

void del(int *a, int *n, int pos)
{
    for (int i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
    a = (int *)realloc(a, (*n) * sizeof(int));
}

int main()
{
    int n = 6, *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    //delete multiples of 5
    // for(int i=0; i<n; i++)
    // {
    //     if (*(a+i)%5==0)
    //         del(a, &n, i), i--;
    // }

    //delete alternate elements
    // n = (n+1)/2;
    // for(int i=1; i<n; i++)
    //     a[i] = a[2*i];
    // a = (int *)realloc(a, n*sizeof(int));

    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
}