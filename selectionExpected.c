#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int randomizedSelect(int arr[], int low, int high, int k)
{
    if (low == high)
    {
        return arr[low];
    }
    srand(time(NULL));
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    int pivotIndex = partition(arr, low, high);
    int leftSize = pivotIndex - low + 1;

    if (k == leftSize)
    {
        return arr[pivotIndex];
    }
    else if (k < leftSize)
    {
        return randomizedSelect(arr, low, pivotIndex - 1, k);
    }
    else
    {
        return randomizedSelect(arr, pivotIndex + 1, high, k - leftSize);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {81, 29, 12, 6, 3, 14, 27, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Original array:\n");
    printArray(arr, n);
    int kthSmallest = randomizedSelect(arr, 0, n - 1, k);
    printf("\nThe %d-th smallest element is: %d\n", k, kthSmallest);
    return 0;
}
