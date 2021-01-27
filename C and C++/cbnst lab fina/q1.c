
#include <stdio.h>
#include <stdlib.h>

void display(double **matrix, int n)
{
    int i, j;
    for (i = 0; i != n; ++i)
    {
        for (j = 0; j != n+1; ++j)
            printf("%7.2lf", matrix[i][j]);
        printf("\n");
    }
}

void gauss_elimination(double **matrix, int n)
{
    int i,j, k, piv;
    double *tmp, p, factor, *sol, b, coeff;
    for (j = 0, piv = 0; j != n; ++j, piv = j)
    {
        while (piv < n && matrix[piv][j] == 0)
            piv++;
        if (piv >= n)
            continue;
        else if (piv != j)
        {
            tmp = matrix[piv];
            matrix[piv] = matrix[j];
            matrix[j] = tmp;
        }
        p = matrix[j][j];
        for (i = j + 1; i < n; ++i)
        {
            factor = matrix[i][j] / p;
            for (k = j; k < n + 1; ++k)
                matrix[i][k] -= factor * matrix[j][k];
        }
    }
    printf("After Gauss Elimination:\n");
    display(matrix, n);
    printf("Solutions: \n");
    sol = (double *)calloc(n, sizeof(double));
    for (i = n - 1; i >= 0; --i)
    {
        b = matrix[i][n], coeff = matrix[i][i];
        if (b == 0 && coeff == 0)
        {
            printf("Infinite Solutions.\n");
            return;
        }
        else if (b != 0 && coeff == 0)
        {
            printf("No Solutions.\n");
            return;
        }
        sol[i] = b;
        for (j = n - 1; j > i; --j)
            sol[i] -= sol[j] * matrix[i][j];
        sol[i] /= coeff;
    }

    for (i = 0; i < n; ++i)
        printf("X%d = %5.2lf\n", i, sol[i]);
}

int main()
{
    double **matrix;
    int n, i, j;
    double num;
    printf("Enter n (Number of Equations): ");
    scanf("%d", &n);

    matrix = (double **)calloc(n, sizeof(double *));
    for (i = 0; i != n; ++i)
        matrix[i] = (double *)calloc(n + 1, sizeof(double));

    printf("Enter elements:\n");
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n + 1; ++j)
        {
            scanf("%lf", &num);
            matrix[i][j] = num;
        }
    }
    gauss_elimination(matrix, n);
}