#include <stdio.h>
#include <stdlib.h>

//displaying the table
void display(float *x, float **y, int n)
{
    int i, j;
    printf("  x: ");
    for (i = 0; i < n; ++i)
        printf("%6.2f", x[i]);
    printf("\n");
    for (i = 0; i < n; ++i)
    {
        printf(i == 0 ? "  y: " : "D%dy: ", i);
        for (j = 0; j < n - i; ++j)
            printf("%6.2f", y[i][j]);
        printf("\n");
    }
}

void main()
{
    int n, i, j;
    float *x, **y, xPredict, yPredict, h, u, mult;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    y = (float **)calloc(n, sizeof(float *));
    x = (float *)calloc(n, sizeof(float));
    for (i = 0; i < n; ++i)
    {
        y[i] = (float *)calloc(n - i, sizeof(float));
        printf("\nEnter x%d and y%d: ", i, i);
        scanf("%f%f", x + i, y[0] + i);
    }

    //calculating the forward differences
    for (i = 1; i < n; ++i)
        for (j = 0; j < n - i; ++j)
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];

    printf("\nEnter x for which y is needed: ");
    scanf("%f", &xPredict);

    h = x[1] - x[0]; //step size
    mult = u = (xPredict - x[0]) / h;

    yPredict = y[0][0];
    for (i = 1; i < n; ++i)
    {
        yPredict += mult * y[i][0];
        mult *= (u - i) / (i + 1);
    }

    printf("\n\nTable:\n");
    display(x, y, n);
    printf("\ny(%.2f) = %.4f", xPredict, yPredict);
}
