#include <stdio.h>
#include <conio.h>
#include <math.h>



float* f(int a)
{
	static float ans[3];
	ans[0] = sqrt(a);
	ans[1] = a*a;
	ans[2] = a*a*a;
	
	return ans;
}


void main()
{
	float *p;
	int n;
	setvbuf(stdout, 0, _IONBF, 0);
	printf("Enter a num: ");
	scanf("%d", &n);
	
	p=f(n);
	
	printf("Sqrt = %.2f\n", p[0]);
	printf("Square = %.2f\n", p[1]);
	printf("Cube = %.2f", p[2]);	
}