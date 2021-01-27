#include <stdio.h>
#define MAX 5

void display(int q[], int f, int r)
{
    printf("\nQueue:\n");
    for (int i = f; i != r; i = (i + 1) % MAX)
        printf("%d ", q[i]);
    printf("%d\n\n", q[r]);
}

void insert(int q[], int *f, int *r)
{
    printf("\nEnter data: ");
    *r = (*r + 1) % MAX;
    scanf("%d", &q[*r]);
    if (*f == -1)
        *f = *r;
    printf("\n");
}

void serve(int q[], int *f, int *r)
{
    printf("\n%d was served.\n\n", q[*f]);
    if (*f == *r)
        *f = *r = -1;
    else
        *f = (*f + 1) % MAX;
}

int main()
{
    int q[MAX], f = -1, r = -1, op;
    do
    {
        printf("Enter:\n1. Insert\n2. Serve\n3. Display\n4. Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (f == 0 && r == MAX - 1 || r + 1 == f)//(r+1)%MAX==f
                printf("\nQueue Overflow.\n\n");
            else
                insert(q, &f, &r);
            break;
        case 2:
            if (f == -1)
                printf("\nQueue Underflow.\n\n");
            else
                serve(q, &f, &r);
            break;
        case 3:
            if (f == -1)
                printf("\nQueue Empty.\n\n");
            else
                display(q, f, r);
            break;
        }
    } while (op != 4);
}