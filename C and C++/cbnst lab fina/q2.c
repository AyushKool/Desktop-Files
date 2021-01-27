
#include <stdio.h>
#define error 1e-4 //for n decimal place precision, write 1e-n+1

double f(double x)
{
    return x*x*x - 2*x -5;
}

double abso(double a)
{
    return (a < 0 ? -a : a);
}

void regulaFalsi(double a, double b)
{
    double fa, fb;
    do
    {
        fa = f(a), fb = f(b);
        if (fa * fb > 0)
        {
            printf("Invalid range.");
            return;
        }

        if (abso(fa) < error)
        {
            printf("%lf", a);
            return;
        }

        else if (abso(fb) < error)
        {
            printf("%lf", b);
            return;
        }

        else
        {
            double x = (a * fb - b * fa) / (fb - fa);
            if (f(x) * fa < 0)
                b = x;
            else
                a = x;
        }
    } while (1);
}

int main()
{
    regulaFalsi(2, 3);
}