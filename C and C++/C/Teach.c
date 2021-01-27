#include <stdio.h>
#include <conio.h>
#include <math.h>

void checkVC(char c)
{
	if (c < 97)
		c += 32;
	switch (c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			printf("Vowel");
			break;
		default:
			printf("Consonant");
	}
}

void printNumName(short int n)
{
	switch(n)
	{
		case 1:
			printf("One");
			break;
		case 2:
			printf("Two");
			break;
		case 3:
			printf("Three");
			break;
		case 4:
			printf("Four");
			break;
		case 5:
			printf("Five");
			break;
		default:
			printf("Invalid Input");
	}
}

void printName()
{
	int i = 0;
	while (i < 10)
	{
		printf("Ayush\n");
		i++;
	}
}

void printNum(int n, int l)
{
	int i = 0;
	while (i < l)
	{
		printf("%d\n", n);
		i++;
	}
}

void sumDigits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	printf("Sum = %d", sum);
}

void reverse(int n)
{
	while (n > 0)
	{
		printf("%d", (n%10));
		n /= 10;
	}
}

void series1(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n;
		n--;
	}
	printf("Sum = %d", sum);
}

void series2(int n)
{
	float sum = 0, i = 0;
	while (i < n)
	{
		sum += pow(-1,i) * (i+1);
		i++;
	}
	printf("Sum = %f", sum);
}

void series3(int n)
{
	float sum = 0;
	while (n > 0)
	{
		sum += pow(n,2);
		n--;
	}
	printf("Sum = %f", sum);
}

void series4(int n)
{
	float sum = 0, i = 0;
	while (i < n)
	{
		sum += pow(-1, i) * pow(i+1,2);
		i++;
	}
	printf("Sum = %f", sum);
}

void main()
{
	/*
	char c;
	printf("Enter a character:\n");
	checkVC(getch());
	*/
	
	/*
	short int n;
	printf("Enter a number from 1 - 5:\n");
	scanf("%i", &n);
	printNumName(n);
	*/
	
	/*
	printName();
	*/
	
	/*
	int n, l;
	printf("Enter a number:\n");
	scanf("%d", &n);
	printf("Enter how many times to print:\n");
	scanf("%d", &l);
	printNum(n , l);
	*/
	
	/*
	int n;
	printf("Enter a number:\n");
	scanf("%d", &n);
	sumDigits(n);
	*/
	
	/*
	int n;
	printf("Enter a number:\n");
	scanf("%d", &n);
	reverse(n);
	*/
	
	/*
	int n;
	printf("Enter a number:\n");
	scanf("%d", &n);
	series1(n);
	*/
	
	/*
	int n;
	printf("Enter a number:\n");
	scanf("%d", &n);
	series2(n);
	*/
	
	/*
	int n;
	printf("Enter a number:\n");
	scanf("%d", &n);
	series3(n);
	*/
	
	/*
	int n;
	printf("Enter a number:\n");
	scanf("%d", &n);
	series4(n);
	*/
}