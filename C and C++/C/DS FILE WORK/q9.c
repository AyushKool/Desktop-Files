/*
Name: Ayush Koul
Roll No: 24
Section: A

Problem Statement 9: WAP to sort array using insertion sort.
*/
#include <stdio.h>
#define N 10

void insertsort(int a[], int n)
{
    int i, j, t;
    for (int i = 1; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while (j >= 0 && t < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
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
        insertsort(a, n);
        printf("\nSorted Array: ");
        for (i = 0; i != n; i++)
            printf("%d ", a[i]);
        printf("\n\nDo you wish to continue (y/n): ");
        fflush(stdin);
        scanf("%c", &op);
    } while (op != 'n' && op != 'N');
}