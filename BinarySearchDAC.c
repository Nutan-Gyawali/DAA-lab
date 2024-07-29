#include <stdio.h>
int binarySearch(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, left, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}
int main()
{
    int arr[100];
    int n, x, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);
    result = binarySearch(arr, 0, n - 1, x);
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }
    return 0;
}
