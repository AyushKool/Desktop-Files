/*
Name: Ayush Koul
Roll No.: 24
Sec: A

Problem Statement: WAP to convert matrix to upper triangular and lower triangular and print its status
*/

#include <stdio.h>
#include <stdlib.h>

typedef float dt;

void swap(dt *a, dt *b)
{
    dt t = *a;
    *a = *b;
    *b = t;
}

int minimum(int n, int m)
{
    return (n < m ? n : m);
}

dt **transpose(dt **matrix, int *n, int *m)
{
    dt **temp = (dt **)calloc(*m, sizeof(dt *));
    for (int i = 0; i != *m; ++i)
        temp[i] = (dt *)calloc(*n, sizeof(dt));
    for (int i = 0; i < *n; ++i)
    {
        for (int j = 0; j < *m; ++j)
        {
            // swap(&(matrix[i][j]), &(matrix[j][i]));
            temp[j][i] = matrix[i][j];
        }
    }
    *n ^= *m;
    *m ^= *n;
    *n ^= *m;
    return temp;
}

void init(dt **matrix, int n, int m)
{
    int i, j;
    double num;
    printf("Enter elements:\n");
    for (i = 0; i != n; ++i)
    {
        for (j = 0; j != m; ++j)
        {
            scanf("%lf", &num);
            matrix[i][j] = (dt)num;
        }
    }
}

void display(dt **matrix, int n, int m)
{
    int isUpper = 1, isLower = 1;
    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != m; ++j)
        {
            printf("%7.2f", (double)matrix[i][j]); //put -%5d for right align and no minus for left align
            if (i < j && matrix[i][j] != 0)
                isLower = 0;
            if (i > j && matrix[i][j] != 0)
                isUpper = 0;
        }
        printf("\n");
    }

    //Classify the Matrix
    if (isUpper && isLower)
        printf("This is Upper and Lower Triangular\n");
    else if (isUpper)
        printf("This is Upper Triangular\n");
    else if (isLower)
        printf("This is Lower Triangular\n");
    else
        printf("This is neither Upper nor Lower\n");
    printf("\n");
}

void swapRow(dt **matrix, int a, int b)
{
    dt *tmp = matrix[a];
    matrix[a] = matrix[b];
    matrix[b] = tmp;
}

void toUpperTri(dt **matrix, int n, int m)
{
    int min = minimum(n, m);
    for (int j = 0, piv = 0; j != min; ++j, piv = j)
    {
        while (piv < n && matrix[piv][j] == 0)
            piv++;
        if (piv >= n)
            continue;
        else if (piv != j)
            swapRow(matrix, piv, j);
        dt p = matrix[j][j];
        for (int i = j + 1; i < n; ++i)
        {
            float factor = matrix[i][j] / p;
            for (int k = j; k < m; ++k)
                matrix[i][k] -= factor * matrix[j][k];
        }
    }
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
            display(matrix, n, n + 1);
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

dt **toLowerTri(dt **matrix, int *n, int *m)
{
    matrix = transpose(matrix, n, m);
    toUpperTri(matrix, *n, *m);
    return transpose(matrix, n, m);
}

int main()
{
    dt **matrix;
    int n, m, i;
    printf("Enter n, m of matrix: ");
    scanf("%d%d", &n, &m);

    matrix = (dt **)calloc(n, sizeof(dt *));
    for (i = 0; i != n; ++i)
        matrix[i] = (dt *)calloc(m, sizeof(dt));
    init(matrix, n, m);

    display(matrix, n, m);
    toUpperTri(matrix, n, m);
    display(matrix, n, m);
    // matrix = toLowerTri(matrix, &n, &m);
    // display(matrix, n, m);

    // gauss_jordan(matrix, n);
}