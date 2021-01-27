
#include <stdio.h>
#include <stdlib.h>

typedef float dt;

void init(dt **matrix, int n)
{
    int i, j;
    double num;
    printf("Enter elements:\n");
    for (i = 0; i != n; ++i)
    {
        for (j = 0; j != n + 1; ++j)
        {
            scanf("%lf", &num);
            matrix[i][j] = (dt)num;
        }
    }
}

void swapRow(dt **matrix, int a, int b)
{
    dt *tmp = matrix[a];
    matrix[a] = matrix[b];
    matrix[b] = tmp;
}

void gauss_jordan(dt **matrix, int n)
{
    for (int j = 0, piv = 0; j != n; ++j, piv = j)
    {
        while (piv < n && matrix[piv][j] == 0)
            piv++;
        if (piv >= n)
            continue;
        else if (piv != j)
            swapRow(matrix, piv, j);
        dt p = matrix[j][j];
        for (int i = 0; i < n; ++i)
        {
            if (i == j)
                continue;
            float factor = (float)matrix[i][j] / p;
            for (int k = j; k < n + 1; ++k)
                matrix[i][k] -= factor * matrix[j][k];
        }
    }

    //finding solutions
    printf("Solutions: \n");
    dt *sol = (dt *)calloc(n, sizeof(dt));
    for (int i = n - 1; i >= 0; --i)
    {
        float b = matrix[i][n], coeff = matrix[i][i];
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
        sol[i] = b / coeff;
    }

    for (int i = 0; i < n; ++i)
        printf("X%d = %5.2f\n", i, sol[i]);
}

int main()
{
    dt **matrix;
    int n, i;
    printf("Enter n (Number of Equations): ");
    scanf("%d", &n);

    matrix = (dt **)calloc(n, sizeof(dt *));
    for (i = 0; i != n; ++i)
        matrix[i] = (dt *)calloc(n + 1, sizeof(dt));
    init(matrix, n);

    gauss_jordan(matrix, n);
}