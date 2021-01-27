#include <stdio.h>
#define MAX 100

void main()
{
    int n, i, j;
    float x[MAX], y[MAX], xPredict, yPredict = 0, nr, dr;

    printf("Enter the no. of terms: ");
    scanf("%d", &n);

    //Input x and y
    for (i = 0; i < n; ++i)
    {
        printf("\nEnter x%d and y%d: ", i, i);
        scanf("%f%f", x + i, y + i);
    }

    printf("\nEnter the x for which you want the y: ");
    scanf("%f", &xPredict);

    for (i = 0; i < n; ++i)
    {
        nr = dr = 1;
        for (j = 0; j < n; ++j)
        {
            if (j != i)
            {
                nr *= xPredict - x[j];
                dr *= x[i] - x[j];
            }
        }
        yPredict += (nr / dr) * y[i];
    }

    printf("\ny(%.2f) = %.4f", xPredict, yPredict);
}