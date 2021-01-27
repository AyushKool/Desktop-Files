#include <stdio.h>

float f(float x)
{
    return 1 / (1 + x);
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
    while (n % 3)
    {
        printf("n must be multiple of 3. Enter again: ");
        scanf("%d", &n);
    }

    h = (b - a) / n;
    result = f(a) + f(b);
    for (i = 1; i < n; ++i)
    {
        if (i % 3 == 0) //true when i multiple of 3
            result += 2 * f(a + i * h);
        else
            result += 3 * f(a + i * h);
    }
    result *= 3 * h / 8;
    printf("\n\nResult = %7.6f", result);
}