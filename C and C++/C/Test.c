#include <stdio.h>
#include <conio.h>

void frequencyArr()
{
	int i, j = 0, count = 1, val, loop;
	int a[] = {5, 4, 6, 7, 5, 5, 8, 7, 4, 2};

	for (i = 1; i < 10; i++)
	{
		if (a[j] > a[i]) //swap a[j] and a[i]
		{
			a[j] += a[i];
			a[i] = a[j] - a[i];
			a[j] -= a[i];
		}
		if (i == 9)
		{
			i = j + 1;
			j++;
		}
	}

	val = a[0];
	for (i = 1; i < 10; i++)
	{
		if (val == a[i])
			count++;
		else
		{
			printf("The number %d appears %d times\n", val, count);
			count = 1;
			val = a[i];
		}
	}
}

void main()
{
	// int n, p = 0, neg = 0;
	// do
	// {
	// 	scanf("%d", &n);
	// 	if (n > 0)
	// 		p++;
	// 	else if (n < 0)
	// 		neg++;
	// } while (n);
	// printf("positive: %d\nnegative: %d", p, neg);
	
	
	
	// int n=5;
    // int a[n] = {0};
    // for(int i=0;i<n;i++) printf("%d ", a[i]);

}