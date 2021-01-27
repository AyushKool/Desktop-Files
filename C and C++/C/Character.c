#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
	/*
	char c;
	int a;
	printf("Enter a number:\n");
	scanf("%d", &a);
	printf("Enter a character:\n");
	scanf(" %c", &c);

	printf("%d and %c", a, c);
	*/
	
	int n, c = 1, t = 0, sum = 0;
	printf("Enter a number:\n");
	scanf("%d", &n);
	
	while (c <= n)
	{
		t += c;
		sum += t;
		c++;
	}
	
	printf("Sum = %d", sum);
}