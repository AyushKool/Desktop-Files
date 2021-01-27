/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 10: WAP to sort array using merge sort.
*/
#include <stdio.h>
#define N 10

void merge(int ar[], int i1, int j1, int i2, int j2)
{
    int temp[N], i = i1, j = i2, k = 0;
    while ((i <= j1) && (j <= j2))
    {
        if (ar[i] < ar[j])
            temp[k++] = ar[i++];
        else
            temp[k++] = ar[j++];
    }
    while (i <= j1)
        temp[k++] = ar[i++];
    while (j <= j2)
        temp[k++] = ar[j++];
    for (i = i1, j = 0; i <= j2; i++, j++)
        ar[i] = temp[j];
}

void mergesort(int a[N], int lb, int ub)
{
    int mid = 0;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, (mid + 1), ub);
        merge(a, lb, mid, (mid + 1), ub);
    }
}

int main()
{
    int a[N], n, i;
    char op;
    do
    {
        printf("Enter size of array: ");
        scanf("%d", &n);
        for (i = 0; i != n; i++)
            scanf("%d", a + i);
        mergesort(a, 0, n-1);
        printf("\nSorted Array: ");
        for (i = 0; i != n; i++)
            printf("%d ", a[i]);
        printf("\n\nDo you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
}