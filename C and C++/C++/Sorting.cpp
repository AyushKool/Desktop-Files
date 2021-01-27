#include <iostream>
#include <math.h>
using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

//Sorts array in O(n^2)
void bubblesort(int a[], int n)
{
    /*
    Worst Case is when array is in reverse order: O(n^2)
    Best Case is when array is in order: O(n)
    */
    // return sizeof(a)/sizeof(int);
    bool swapped;
    for (int i = 0; i < n; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionsort(int a[], int n)
{
    /*
    Time complexity: O(n^2)
    */
    int minind;
    for (int i = 0; i < n - 1; i++)
    {
        minind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minind])
                minind = j;
        }
        swap(a[i], a[minind]);
    }
}

void insertionSort(int arr[], int n)
{
    /*
    Time complexity: O(n^2)
    */
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

// A function to merge the two half into a sorted data.
void merge(int *a, int low, int high, int mid)
{
    // We have low to mid and mid+1 to high already sorted.
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;

    // Merge the two parts into temp[].
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    // Insert all the remaining values from i to mid into temp[].
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (j <= high)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    // Assign sorted data stored in temp[] to a[].
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

// A function to split array into two parts.
void mergeSort(int a[], int low, int high)
{
    /*
    Time Complexity: O(nlogn)
    */
    int mid;
    if (low < high)
    {
        mid = low + (high - low) / 2;
        // Split the data into two half.
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        // Merge them to get sorted output.
        merge(a, low, high, mid);
    }
}

/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition(int arr[], int low, int high)
{
    //pivot -->a[high]
    int i = low;     // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < arr[high])
        {
            swap(arr[i], arr[j]);
            i++; // increment index of smaller element
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quicksort(int arr[], int low, int high)
{
    /*
    Worst Case: O(n^2) --> partition is always greatest or smallest (array is already sorted)
    Best Case: O(nlogn) --> partition always picks the middle element
    Average Case: O(nlogn)
    */
    if (low < high)
    {
        /* pi is partitioning index, arr[pi] is now  
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void quicksort(int a[], int n)
{
    quicksort(a, 0, n-1);
}

//counting sort (Range: [low, high])
void countingsort(int a[], int n, int low, int high)
{
    //Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input
    int counter[high-low+1] = {0}, sorted[n];
    for(int i=0; i<n;i++)
        counter[a[i]-low]++;
    // display(counter, high-low+1);
    // cout << endl;
    for(int i=1; i<high-low+1;i++)
        counter[i] += counter[i-1];
    // display(counter, high-low+1);
    // cout << endl;
    for(int i=0; i<n;i++)
    {
        sorted[counter[a[i]-low]-1] = a[i];
        counter[a[i]-low]--;
    }
    for(int i=0; i<n;i++)
        a[i] = sorted[i];
}

//counting sort using place (base 10), subroutine for radix sort
void countingsort(int a[], int n, int place)
{
    int counter[10] = {0}, sorted[n];
    for(int i=0; i<n;i++)
        counter[a[i]/place %10]++;
    display(counter, 10);
    cout << endl;
    for(int i=1; i<10;i++)
        counter[i] += counter[i-1];
    display(counter, 10);
    cout << endl;
    for(int i=0; i<n;i++)
    {
        sorted[counter[a[i]/place %10] - 1] = a[i];
        counter[a[i]/place %10]--;
    }
    for(int i=0; i<n;i++)
        a[i] = sorted[i];
}

int getmax(int a[], int n)
{
    int max = a[0];
    for (int i=1; i<n; i++)
        if(a[i]>max)
            max = a[i];
    return max;
}

void radixsort(int a[], int n)
{
    //LSD -> MSD: sorts correctly
    //MSD -> LSD: Lexigrahically ??????????????????????
    /*
    Time Complexity: O(d*(n+b))
    d --> digits of maximum number
    b --> base of representing numbers
    */
    int m = log10(getmax(a, n)) + 1;
 
	// Calling countSort() for digit at mth place in every input
	for(int i=1; i<=m; i++)
        countingsort(a, n, i);
}

//bucket sort


int main()
{
    int arr[] = {5, 2, 4, 7, 12, 3, 4, 7}, n = sizeof(arr) / sizeof(int);
    // int (*a)[5] =  &arr;
    // cout << sizeof(*a)/sizeof(int) << endl;
    // cout << bubblesort(*a);
    //quicksort(arr, n);
    radixsort(arr, n);
    display(arr, n);
}