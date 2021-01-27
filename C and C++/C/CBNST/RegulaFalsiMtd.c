/*
Name: Ayush Koul
Roll No.: 24
Sec: A

Problem Statement: WAP to find solution of an equation using regula-falsi method
*/

#include <stdio.h>
#include <math.h>
// #define err(N) 1e-##N
#define error 1e-2 //for n decimal place precision, write 1e-n+1

double f(double x)
{
    // return x * log10(x) - 1.2;
    // return x*x*x - x*x + 2;
    // return x*x -3;
    // return exp(-x)*(3.2*sin(x) - 0.5*cos(x)) - 3.2968;
    // return exp(-x) - sin(x);
    // return 3*x + sin(x) - exp(-x);
    // return x*x*x + 2*x*x + 10*x - 20;
    // return 3*x - cos(x) - 1;
    return x * cos(x / (x - 2)); //1, 3
    // return (exp(-2*x) - 1)/x - x*x; //no solutions
    // return exp(x*x - 1) + 10*sin(2*x) - 5; //
    // return exp(-x) + 3*x*x; //no solutions
    return tan(x) - x - 1; //
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
            printf("%.10lf", a);
            return;
        }

        else if (abso(fb) < error)
        {
            printf("%.10lf", b);
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
    regulaFalsi(1,3);
}