#include <stdio.h>

void insertSort(int a[],  int n)
{
	int i, j, shifts = 0, cmps = 0, temp;
	for(i=1; i<n; ++i)
	{
		temp = a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			cmps++, shifts++;
			a[j+1] = a[j];
			j--;
		}
		shifts++;
		a[j+1] = temp;
	}
	printf("\n");
	for (int i = 0; i < n; i++)
          printf("%d ", a[i]);
	printf("\ncomparisons = %d\nshifts = %d\n\n", cmps, shifts);
}

int main()
{
     int t;
     scanf("%d", &t);
     while (t--)
     {
          int n;
          scanf("%d", &n);
          int a[n];
          for (int i = 0; i < n; i++)
               scanf("%d", a + i);
          insertSort(a, n);
     }
     return 0;
}