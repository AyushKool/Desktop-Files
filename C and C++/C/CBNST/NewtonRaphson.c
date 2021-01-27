/*
Name: Ayush Koul
Roll No.: 24
Sec: A

Problem Statement: WAP to find solution of an equation using bisection method
*/

#include <stdio.h>
#include <math.h>
// #define err(N) 1e-##N
#define error 1e-5 //for n decimal place precision, write 1e-n+1

double f(double x)
{
    return x * log10(x) - 1.2;
    // return x*x*x - x*x + 2;
    // return x*x -3;
    // return exp(-x)*(3.2*sin(x) - 0.5*cos(x)) - 3.2968;
    // return exp(-x) - sin(x);
    // return 3*x + sin(x) - exp(-x);
    // return x*x*x + 2*x*x + 10*x - 20;
    // return 3*x - cos(x) - 1;
    // return x * cos(x / (x - 2)); //1, 3
    // return (exp(-2*x) - 1)/x - x*x; //no solutions
    // return exp(x*x - 1) + 10*sin(2*x) - 5; //
    // return exp(-x) + 3*x*x; //no solutions
    // return tan(x) - x - 1; //
}

double f_prime(int x)
{
    return log10(x) + 1/log(10);
}

double abso(double a)
{
    return (a < 0 ? -a : a);
}

void nr(double a)
{
    double fa, fprime;
    do
    {
        fa = f(a), fprime = f_prime(a);
        if (fprime == 0)
        {
            printf("Invalid Number.");
            return;
        }
        if (abso(fa) < error)
        {
            printf("%.10lf", a);
            return;
        }
        else
        {
            a = a - fa/fprime;
        }
    } while (1);
}

int main()
{
    nr(2);
}