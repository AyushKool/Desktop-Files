/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 11: WAP to sort array using quick sort.
*/
#include <stdio.h>
#define N 10

void quicksort(int a[N], int lb, int ub)
{
    int i = lb, j = ub, key = a[lb], t;
    if (lb >= ub)
        return;
    while (i < j)
    {
        while (key >= a[i] && i < j)
            i++;
        while (key < a[j])
            j--;
        if (i < j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[lb] = a[j];
    a[j] = key;
    quicksort(a, lb, j - 1);
    quicksort(a, j + 1, ub);
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
        quicksort(a, 0, n - 1);
        printf("\nSorted Array: ");
        for (i = 0; i != n; i++)
            printf("%d ", a[i]);
        printf("\n\nDo you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
}