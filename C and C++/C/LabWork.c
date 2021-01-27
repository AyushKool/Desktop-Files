#include <stdio.h>
#define IN(a)               \
    for (i = 0; i < n; i++) \
    scanf("%d", &a[i])
#define OUT(a)              \
    for (i = 0; i < n; i++) \
    printf("%d ", a[i])

// void tester(){
//     sum(4,5);
//     printf("%d", 2);
// }

// void sum(int a, int b)
// {
//     //return 1;
// }

//3rd Repeating Element
void p1a()
{
    int i, j, k, n, a[20], count = 0, flag = 0, repeat = 0, ind;
    printf("Enter limit:");
    scanf("%d", &n);
    IN(a);
    printf("\n\nOutput:\n");

    for (i = 0; i < n && count < 3; i++, repeat = 0)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (a[i] == a[j])
            {
                for (k = 0; k < i; k++)
                {
                    if (a[i] == a[k])
                    {
                        repeat = 1;
                        break;
                    }
                }
                break;
            }
        }
        if (!repeat)
            count++;
        if (count == 3)
            ind = i;
    }
    if (count == 3)
        printf("3rd repeating element: %d", a[ind]);
    else
        printf("No 3rd repeating element.");
}

//3rd Non-Repeating Element
void p1b()
{
    int i, j, n, a[20], count = 0, repeat = 0, ind;
    printf("\nEnter limit:");
    scanf("%d", &n);
    IN(a);
    printf("\nOutput:\n");

    for (i = 0; i < n && count < 3; i++, repeat = 0)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (a[i] == a[j])
            {
                repeat = 1;
                break;
            }
        }
        if (!repeat)
            count++;
        if (count == 3)
            ind = i;
    }
    if (count == 3)
        printf("3rd non-repeating element: %d", a[ind]);
    else
        printf("No 3rd non-repeating element.");
}

void swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void p6()
{
    int i, j, n, a[20], flag = 0;
    printf("\nEnter limit:");
    scanf("%d", &n);
    IN(a);
    printf("\nOutput:\n");

    for (i = 0, j = 0; i < n; i++, j = 0, flag = 0)
    {
        //loops goes until a[i] is positive
        while (a[i] < 0) // 1 if neg, 0 if pos
            i++;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            j = 0;
            while (a[i] > 0)
                swap(&a[i], &a[i + ++j]);
        }
        else
            break;
    }
    OUT(a);
}

void rev(int *a, int i, int j)
{
    for (; i < j; i++, j--)
        swap(&a[i], &a[j]);
}

//Left Rotations
void lr()
{
    int i, n, a[20], k;
    printf("\nEnter limit:");
    scanf("%d", &n);
    IN(a);
    printf("\nEnter no. of rotations:");
    scanf("%d", &k);
    k %= n;
    if (k)
    {
        rev(a, 0, k - 1);
        rev(a, k, n - 1);
        rev(a, 0, n - 1);
    }
    printf("\nOutput:\n");
    OUT(a);
}

//Right Rotations
void rr()
{
    int i, n, a[20], k;
    printf("\nEnter limit:");
    scanf("%d", &n);
    IN(a);
    printf("\nEnter no. of rotations:");
    scanf("%d", &k);
    k %= n;
    if (k)
    {
        rev(a, 0, n - k - 1);
        rev(a, n - k, n - 1);
        rev(a, 0, n - 1);
    }
    printf("\nOutput:\n");
    OUT(a);
}

void main()
{
    //lr(k) equals rr(n-k) and vice versa
    p1a();
}