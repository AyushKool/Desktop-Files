#include <stdio.h>
#include <conio.h>

void charType()
{
	char c;
	printf("Enter:\n");
	scanf("%c", &c);
	
	if ((c>=65 && c<=90) || (c>=97 && c<=122))
		printf("alphabet");
	else if (c>=48 && c<= 57)
		printf("number");
	else
		printf("special character");
}

void vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		printf("vowel");
	else
		printf("not vowel");
}

void mangoes(int n)
{
	float bill = 5 * n;
	if (n > 20)
		bill *= .9;
	else if (n > 10)
		bill *= .95;
	printf("%f", bill);
		
}

void grade(float f)
{
	printf("Grade: ");
	if (f >= 85)
		printf("A");
	else if (f<85 && f>=70)
		printf("B");
	else if (f<70 && f>=55)
		printf("C");
	else if (f<55 && f>=40)
		printf("D");
	else
		printf("F");
}

void triangle(int a, int b, int c)
{
	if (a+b <= c || a+c <= b || b+c <= a)
		printf("Not valid triagle");
	else
		printf("Valid triagle");
}

void expression(int a, int b, int c, int d)
{
	if (c != d)
	{
		float ans = (float) (a-b)/(c-d);
		printf("%f", ans);
	}
	else
		printf("undefined expression");
	
}

int abs(int a)
{
	if (a < 0)
		a *= -1;
	return a;
}

void digit(int a)
{
	if (abs(a)-10 < 0)
		printf("single");
	else
		printf("multi");
}

void input(int a)
{
	if (a%2 ==0 && a%5 == 0)
		printf("%d", (a*a));
	else
		printf("%d", (a*a*a));
}

void main()
{
	/*
	int a, b, c, d;
	char ch;
	
	printf("Enter marks:\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	float f = (a + b + c + d)/4.0;
	grade(f);
	
	printf("\nEnter a alphabet:\n");
	ch = getch();
	vowel(ch);
	*/
	
	input(10);
}