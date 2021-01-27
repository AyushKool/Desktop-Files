#include <stdio.h>
#include <math.h>

void main()
{
	int mass;
	double energy, c;
	printf("Enter a mass:");
	scanf("%d", & mass);
	c = 3 * pow(10, 8);
	energy = mass * c * c;
	printf("Energy = %e", energy);
}
/*	int i = -3, j = 2;
	j = i++ - --j + j++ + j++ * --i + i++;
	printf("i = %d j = %d", i, j);
	j += 0;
	printf("i = %d j = %d", i, j);
	
	
	/*
	int x = 5, y = 5, z;
	z = (x = 5, y = 2, x^y);
	z = ~z;
	printf("%d", z);
	 if (~(x^y))
		 printf("Equal");
	 else
		 printf("not Equal");
*/