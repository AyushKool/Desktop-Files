#include <stdio.h>

float f(float x, float y)
{
    return (y - x) / (y + x);
}

void main()
{
    float x, h, xPredict, yPredict;
    int i, n;
    printf("Enter x0 ad y0: ");
    scanf("%f%f", &x, &yPredict);
    printf("Enter x for which y is needed: ");
    scanf("%f", &xPredict);
    printf("Enter no. of subintervals: ");
    scanf("%d", &n);

    h = (xPredict - x) / n;
    for (i = 0; i < n; ++i)
        yPredict += h * f(x + i*h, yPredict);

    printf("\ny(%.2f) = %7.5f", xPredict, yPredict);
}