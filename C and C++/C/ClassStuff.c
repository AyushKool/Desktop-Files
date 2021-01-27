#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

/*
	This program uses pointers to find real roots of nth degree polynomial
*/

void si()
{
    int p, r, t;
    printf("Enter P, r, t:");
    scanf("%d%d%d", &p, &r, &t);
    printf("I = %f", ((p*r*t)/100));
}

void sum()
{
    int a, b;
    printf("Enter two numbers:");
    scanf("%d%d", &a, &b);
    printf("Sum = %d", a+b);
}

void cube()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Cube = %.0f", (a*a*a));
}

int fact(int n)
{
    if(n<=1)
        return 1;
    return n*fact(n-1);
}

int nCr(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
    //printf("nCr: %d", (fact(n)/(fact(r)*fact(n-r))));
}

int isPrime(int n, int i)
{
    if (n<=2)
        return (n==2)? 1:0;
    if (n%i==0)
        return 0;
    if (i*i>n)
        return 1;
    return isPrime(n, i+1);
}

void prime()
{
    int a;
    printf("Enter a num:");
    scanf("%d", &a);
    isPrime(a, 2) ? printf("Yes") : printf("No");
}

int countFactors(int n)
{
	if (n<2 && n>-2)
		return 1;
    int c = 2;
    for (int i=2; i<=n/2; i++)
        if(n%i==0)
            c++;
    return c;
}

void factors(int n)
{
    int *a = malloc(countFactors(n)*sizeof(int));
    *a = 1;
    *(a+countFactors(n)-1) = n;

    int c = 1;

    for (int i=2; i<=n/2; i++)
    {
        if (n%i==0)
        {
            *(a+c) = i;
            c++;
        }
    }
    printFactors(a, countFactors(n));
}

void printFactors(int *a, int size)
{
    for (int i=0; i<size; i++)
        printf("%d ", *(a+i));
}

void poly()
{
	int d;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &d);
    d++;

    int *a;
    a = malloc(d*sizeof(int));

    for (int i=0; i<d; i++)
    {
        printf("\nEnter the value of A%d: ", d-i-1);
        scanf("%d", a+i);
    }

    int possible = countFactors(*a) * countFactors(*(a+d-1));
	printf("%d: %d", *a, countFactors(*a));
	printf("\n%d: %d", *(a+d-1), countFactors(*(a+d-1)));
    //for (int i=0; i<possible; i++){}
}

void series(int n)
{
    float s = 0;
    for (int i=1; i<=n; i++)
    {
        s += (1.0/fact(i));
    }
    printf("Sum = %f", s);
}

void main()
{
	int n;
	setvbuf(stdout, 0, _IONBF, 0);
	//poly();
	factors(32544);
}