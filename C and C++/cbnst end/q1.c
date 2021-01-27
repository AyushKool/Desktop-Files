#include <stdio.h>

float f(float x, float y)
{
    return x + y;
}

int main()
{
    float x, h, xPredict, yPredict, k1, k2, k3, k4;
    int i, n;
    printf("Enter x0 ad y0: ");
    scanf("%f%f", &x, &yPredict);
    printf("Enter x for which y is needed: ");
    scanf("%f", &xPredict);
    printf("Enter no. of subintervals: ");
    scanf("%d", &n);

    h = (xPredict - x) / n;
    for (i = 0; i < n; ++i)
    {
        x += i * h;
        k1 = h * f(x, yPredict);
        k2 = h * f(x + h / 2, yPredict + k1 / 2);
        k3 = h * f(x + h / 2, yPredict + k2 / 2);
        k4 = h * f(x + h, yPredict + k3);

        yPredict += (k1 + 2 * (k2 + k3) + k4) / 6;
        printf("\ny(%.2f) = %7.5f", x + h, yPredict);
    }
}