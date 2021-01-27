#include <stdio.h>

float f(float x)
{
    return 1 / (1 + x * x);
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
    while (n % 2)
    {
        printf("n must be even. Enter again: ");
        scanf("%d", &n);
    }

    h = (b - a) / n;
    result = f(a) + f(b);
    for (i = 1; i < n; ++i)
    {
        if (i % 2) //true when i is odd
            result += 4 * f(a + i * h);
        else
            result += 2 * f(a + i * h);
    }
    result *= h / 3;

    printf("\n\nResult = %7.6f", result);
}