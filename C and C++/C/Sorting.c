//This is a program that illustrates multiple sorting methods

#include <stdio.h>
#include <conio.h>

const int n;

void mergeSort(int a[], int l, int r)
{
	int i, j, k, mid = (l+r)/2;
	int b[l+r+1];
	
	//Dividing
	if (l<r)
	{
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
	}
	else
		return;
	
	//Merging
	for (i=l, j=mid+1, k=l; i<=mid && j<=r; k++)
	{
		/*
		Why can't I do this?
		a[i]<a[j] ? b[k]=a[i++] : b[k]=a[j++];
		*/
		
		if(a[i]<a[j]) 
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
	}
	
	while(i<=mid)
		b[k++] = a[i++];
	
	while(j<=r)
		b[k++] = a[j++];
	
	for(i=l; i<=r; i++)
		a[i] = b[i];
}

void swap(int *a, int *b)
{
	
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

int partition(int a[], int l, int r)
{
	int piviot = a[r], i = l-1, j;
	for (j=l; j<r; j++)
	{
		if (a[j]<=piviot)
			
		{
			i++;
			swap(&a[j], &a[i]);
		}
	}
	swap(&a[r], &a[i+1]);
	return i+1;
}

void quickSort(int a[], int l, int r)
{
	
	if (l<r)
	{
		int prt = partition(a, l, r);
		quickSort(a, l, prt-1);
		quickSort(a, prt+1, r);
	}
	else
		return;
}



void insertSort()
{
	
}

//Array should be sorted in ascending order
//Returns index of number or -1 if number is not in array
int binarySearchA(int a[], int num)
{
	int l=0, r=n-1, mid = n/2;
	while(l<=r)
	{
		if (a[mid]==num)
			return mid;
		if (a[mid]>num)
		{
			r=mid-1;
			mid -= (r-l)/2 + 1;
		}
		else
		{
			l=mid+1;
			mid += (r-l)/2 +1;
		}
	}
	return -1;
}

//Array should be sorted in descending order
//Returns index of number or -1 if number is not in array
int binarySearchD(int a[], int num)
{
	int l=0, r=n-1, mid = n/2;
	while(l<=r)
	{
		if (a[mid]==num)
			return mid;
		if (a[mid]<num)
		{
			r=mid-1;
			mid -= (r-l)/2 + 1;
		}
		else
		{
			l=mid+1;
			mid += (r-l)/2 +1;
		}
	}
	return -1;
}

//Array should either be ascending or descending
//Returns 1 for ascending and 0 for descending
int isAsc(int a[])
{
	//a[0]>=a[n-1] ? return 0 : return 1;
}

void main()
{
	int a[10], i, num, index;
	setvbuf(stdout, 0, _IONBF, 0);
	
	printf("Enter limit: ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	
	/*
	mergeSort(a, 0, n-1);
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
	*/
	
	//isAsc(a) ? index = binarySearchA(a, num) : index = binarySearchD(a, num);
	/*
	printf("Enter number: ");
	scanf("%d", &num);
	if (index!=-1)
		printf("index = %d", index);
	else
		printf("Element not in array");
	*/
	quickSort(a, 0, n-1);
	for(i=0;i<n;i++)
		printf("%d ", a[i]);
}