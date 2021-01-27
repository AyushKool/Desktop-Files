#include <stdio.h>
#include <stdlib.h>

#define show printf("\n");for(int i=0; i!=n; i++)\
        printf("%d ", a[i])
#define input for(int i=0; i!=n; i++)\
        scanf("%d", &a[i])

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void sort(int a[], int n)
{
    for(int i=0; i!=n-1; i++)
    {
        for(int j=i; j!=n; j++)
        {
            if(a[i] > a[j])
                swap(a+i,a+j);
        }
    }
}

void removeDupSorted(int *a, int n)
{
    sort(a, n);
    show;
    printf("\n%d ", a[0]);
    for(int i=1; i!=n; i++)
    {
        if (a[i] == a[i-1])
            continue;
        printf("%d ", a[i]);
    }
}

void delInd(int **a, int n, int ind)
{
    for(int i = ind; i!=n; i++)
        (*a)[i] = (*a)[i+1];
    *a = (int*) realloc(*a, (n-1)*sizeof(int));
}

void removeDupUnsorted(int *a, int n)
{
    
}

void main()
{
    int n = 10, *a = (int*) calloc(sizeof(int), n);
    input;
    show;
    delInd(&a, n, 3);
    show;
}