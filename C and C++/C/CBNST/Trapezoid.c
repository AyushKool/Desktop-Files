#include <stdio.h>

float f(float x)
{
    return 1 / (10 + x * x * x);
}

void main()
{
    float a, b, h, result;
    int i, n;

    printf("Enter lower limit (a): ");
    scanf("%f", &a);
    printf("Enter upper limit (b): ");
    scanf("%f", &b);
    printf("Enter no. of subintervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;
    result = f(a) + f(b);
    for (i = 1; i < n; ++i)
        result += 2 * f(a + i * h);
    result *= h / 2;

    printf("Result = %7.6f", result);
}