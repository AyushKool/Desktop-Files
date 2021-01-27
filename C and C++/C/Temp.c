#include <stdio.h>
#include <math.h>

void main()
{
	int num, b, n = 0;
	float r = 0;
	printf("Enter the number in decimal:\n");
	scanf("%d", &num);
	printf("Enter the base:\n");
	scanf("%d", &b);
	
	while(b <= num)
	{
		r += (pow(10, n) * (num%b));
		printf("r = %f   n = %d   num = %d\n", r, n, num);
		num /= b;
		n++;
	}
	r += pow(10, n) * (num%b);
	
	
	
	printf("number in base %d is: %f", b, r);
}