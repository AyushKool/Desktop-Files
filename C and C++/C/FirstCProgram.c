/*  
	Ayush Koul
	Section B
	Roll #: 30
	
	This program completes certain tasks
*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

//converts temperature from fahrenheit to Celsius and vice versa: F = (9/5)C + 32
void cToF(float c)
{    
	float f = 1.8 * c + 32;
	printf("\nThe temperature in fahrenheit is %f\n", f);
}

//converts temperature from Celsius to fahrenheit and vice versa: C = (5/9)(F - 32)
void fToC(float f)
{
	float c = (5.0/9) * (f - 32);
	printf("\nThe temperature in celsuis is %f\n", c);
}

//calculates area and perimeter of rectangle with length l and height h
void rect(float l, float h)
{
	float a, p;
	a = l * h;
	p = 2 * (l + h);
	printf("\nThe area of a %f x %f rectangle is: %f \nThe perimeter of a %f x %f rectangle is: %f\n", l, h, a, l, h, p);
}

//calculates area and circumference of circle with radius r
void circle(float r)
{
	float a, c;
	a = 3.141592 * r * r;
	c = 2 * 3.141592 * r;
	printf("\nThe area of the circle with radius %f is %f \nThe circumference of the circle with radius %f is %f\n", r, a, r, c);
}

//computes simple interest
void sInterest(float p, float r, float t)
{
	printf("\nThe simple interest = %f\n", ((p * r * t)/100));
}

//computes hcf of a and b
int gcf(int a, int b)
{
	if (b > a)
		gcf(b, a);
	if (b == 0)
		return a;
	return gcf(b, a%b);
}

//Write a program to input 5 marks of a student and find out the percentage
void percentage(float a, float b, float c, float d, float e)
{
	float i = (a + b + c + d + e)/5;
	printf("\nThe percentage of the student is %f%\n", i);
}

//swapping without 3rd variable
void swapWoVar(float a, float b)
{
	printf("\nBefore:\ta = %f and b = %f", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("\nAfter\ta = %f and b = %f\n", a, b);
}

//finds the sum of a and b
void sum(float a, float b)
{
	printf("\nThe sum of %f and %f is %f\n", a, b, (a + b));
}

//swapping with 3rd variable
void swapWVar(float a, float b)
{
	float c = a;
	printf("\nBefore:\ta = %f and b = %f", a, b);
	a = b;
	b = c;
	printf("\nAfter\ta = %f and b = %f\n", a, b);
}

void roots(int a, int b, int c)
{
	double det = (b*b) - (4*a*c);
	if (det < 0)
		printf("\nThe roots are complex\n");
	else
	{
		double r1 = (-b + sqrt(det))/(2*a);
		double r2 = (-b - sqrt(det))/(2*a);
		printf("\nThe roots are %f and %f\n", r1, r2);
	}
}

void power(int x, int y)
{
	printf("\nx^y = %f\n", pow(x, y));
}

void backwards(int a)
{
	//00241
	int b;
	while(a != 0)
	{
		b = a%10;
		printf("%d", b);
		a/=10;
	}
}

void eo(int a)
{
	if (a%2 == 0)
		printf("\n%d is even\n", a);
	else
		printf("%d is odd\n", a);
}

void pno(int a)
{
	if (a > 0)
		printf("\n%d is positive\n", a);
	else if (a < 0)
		printf("%d is negative\n", a);
	else
		printf("%d is 0\n", a);
}

//finds largest of 5 numbers
void largest()
{
	int a, b, c, d, e;
	printf("\nEnter\n");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	if (a < b)
		a = b;
	if (a < c)
		a = c;
	if (a < d)
		a = d;
	if (a < e)
		a = e;
	printf("\n%d\n", a);
}

void largest2()
{
	int a[5];
	printf("\nEnter\n");
	for (int i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	
	for (int i = 1; i < 5; i++)
	{
		if (a[i-1] < a[i])
			a[0] = a[i];
	}
	printf("\n%d\n", a[0]);
}


//finds if year is leap year
void leap(int a)
{
	if ((a%100 != 0 && a%4 == 0) || (a%100==0 && a%400==0))
		printf("leap yr");
	else
		printf("not leap yr");
}

void main()
{
	//float cel, fah, length, width, radius, principle, rate, time, marks_1, marks_2, marks_3, marks_4, marks_5, num_1, num_2;
	//int a, b, c;
	//String ans = "";
	
	//while (ans !=  "")
	
	largest2();

	//backwards(908);
	
	/*
	printf("Enter x and y for x^y:\n")
	printf("x = ");
	scanf("%d", & a);
	printf("\nb = ");
	scanf("%d", & b);
	power(a, b);
	*/
	
	/*
	printf("Enter a number:\n")
	scanf("%d", &a);
	pno(a);
	*/
	
	/*
	printf("Enter a number:\n")
	scanf("%d", &a);
	eo(21);
	*/
	
	/*
	printf("Enter the values of a, b, c for the quadratic: ax^2 + bx + c\n");
	printf("a = ");
	scanf("%d", & a);
	printf("\nb = ");
	scanf("%d", & b);
	printf("\nc = ");
	scanf("%d", & c);
	roots(a, b, c);
	*/
	
	/*
	printf("Enter a temperature in Celsius:\n");
	scanf("%f", & cel);
	cToF(cel);
	*/
	
	/*
	printf("Enter a temperature in fahrenheit:\n");
	scanf("%f", & fah);
	fToC(fah);
	*/
	
	/*
	printf("Enter the dimensions of the rectangle: (length, width)\n");
	scanf("%f %f", & length, & width);
	rect(length, width);
	*/
	
	/*
	printf("Enter the radius of the circle:\n");
	scanf("%f", & radius);
	circle(radius);
	*/
	
	/*
	printf("Enter the principle amount, then the rate (as a percentage) and then the time:\n");
	scanf("%f %f %f", & principle, & rate, & time);
	sInterest(principle, rate, time);
	*/
	
	/*
	printf("Enter the 5 marks of the student (out of 100):\n");
	scanf("%f %f %f %f %f", & marks_1, & marks_2, & marks_3, & marks_4, & marks_5);
	percentage (marks_1, marks_2, marks_3, marks_4, marks_5);
	*/
	
	/*
	printf("Enter 2 numbers for addition:\n");
	scanf("%f %f", & num_1, & num_2);
	sum(num_1, num_2);
	*/
	
	/*
	printf("Enter 2 numbers for swapping with a 3rd variable:\n");
	scanf("%f %f", & num_1, & num_2);
	swapWVar(num_1, num_2);
	*/
	
	/*
	printf("Enter 2 numbers for swapping without a 3rd variable:\n");
	scanf("%f %f", & num_1, & num_2);
	swapWoVar(num_1, num_2);
	*/
}



//compile: gcc -o c.exe firstCProgram.c
//run: c.exe