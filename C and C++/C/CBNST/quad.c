/*Name: Aayush Tyagi
  Section: A
  Roll no. : 03
  Problem Statement: Program in C to find the roots
  of quadratic equation.*/
#include <stdio.h>
#include <math.h>
#include<conio.h>
int main()
{
    double a, b, c, d;
    double root1, root2;
    printf("Enter a, b and c where a*x*x + b*x + c = 0: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    d = b*b - 4*a*c;

    if (d < 0)//Imaginary roots
    {
        printf("Imaginary roots:\n");
        printf("First root = %lf + i%lf\n", -b/(double)(2*a), sqrt(-d)/(2*a));
        printf("Second root = %lf - i%lf\n", -b/(double)(2*a), sqrt(-d)/(2*a));
    }
    else//Real roots
    {
        printf("Real roots:\n");
        root1 = (-b + sqrt(d))/(2*a);
        root2 = (-b - sqrt(d))/(2*a);

        printf("First root = %lf\n", root1);
        printf("Second root = %lf\n", root2);
    }
}
