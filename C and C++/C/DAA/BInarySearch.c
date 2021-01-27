#include <stdio.h>

int first(int arr[], int low, int high, int k, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || k > arr[mid - 1]) && arr[mid] == k)
            return mid;
        else if (k > arr[mid])
            return first(arr, (mid + 1), high, k, n);
        else
            return first(arr, low, (mid - 1), k, n);
    }
    return -1;
}

int last(int arr[], int low, int high, int k, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low)/2; 
        if ((mid == n - 1 || k < arr[mid + 1]) && arr[mid] == k)
            return mid;
        else if (k < arr[mid])
            return last(arr, low, (mid - 1), k, n);
        else
            return last(arr, (mid + 1), high, k, n);
    }
    return -1;
}

int search(int arr[], int n, int k)
{
    int i, j;
    i = first(arr, 0, n - 1, k, n);
    if (i == -1)
        return i;
    j = last(arr, i, n - 1, k, n);

    return j - i + 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n], k;
        for (int i = 0; i < n; i++)
            scanf("%d", a + i);
        scanf("%d", &k);
        int ans = search(a, n, k);
        printf(ans == -1 ? "Key not present.\n\n" : "%d - %d\n\n", k, ans);
    }
    return 0;
}