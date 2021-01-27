#include <stdio.h>
#include <stdlib.h>
int main()
{

    int **A, B[3][3] = {0}, i, j;
    A = (int **)malloc(3 * sizeof(int *));
    for (i = 0; i < 3; i++)
        A[i] = (int *)malloc(3 * sizeof(int));
    printf("Address of A is (%u)\n", &A);
    printf("Address inside A is (%u)\n\n", A);

    for (i = 0; i < 3; i++)
    {
        printf("%u[%u]-> ", A + i, *(A + i));
        for (j = 0; j < 3; j++)
        {
            if (j != 2)
                printf("<%u> - ", *(A + i) + j);
            else
                printf("<%u>  ", *(A + i) + j);
        }
        printf("\n\n");
    }
    printf("---------------------------------------------------");
    printf("\n\nAddress of B is (%u)\n", &B);
    printf("Address inside B is (%u)\n\n", B);

    for (i = 0; i < 3; i++)
    {
        printf("%u[%u]-> %u", B + i + 3, *(B + i) + 3);
        for (j = 0; j < 3; j++)
        {
            if (j != 2)
                printf("<%u> - ", *(B + i) + j);
            else
                printf("<%u>  ", *(B + i) + j);
        }
        printf("\n\n");
    }
    printf("---------------------------------------------------");
}
