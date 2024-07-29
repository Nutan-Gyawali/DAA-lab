#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int medianOfMedians(int arr[], int left, int right)
{
    int n = right - left + 1;
    int medianIndex = left + n / 2;
    if (n <= 5)
    {
        // Find median directly if the size is <= 5
        for (int i = left; i <= right; i++)
        {
            for (int j = i + 1; j <= right; j++)
            {
                if (arr[j] < arr[i])
                {
                    swap(&arr[i], &arr[j]);
                }
            }
        }
        return arr[medianIndex];
    }
    int numMedians = (n + 4) / 5;
    int *medians = (int *)malloc(numMedians * sizeof(int));
    for (int i = 0; i < numMedians; i++)
    {
        int subLeft = left + i * 5;
        int subRight = subLeft + 4;
        if (subRight >= right)
        {
            subRight = right;
        }
        medians[i] = medianOfMedians(arr, subLeft, subRight);
    }
    int medianOfMediansValue = medianOfMedians(medians, 0, numMedians - 1);
    free(medians);
    return medianOfMediansValue;
}
int partition(int arr[], int left, int right, int pivot)
{
    int pivotValue = arr[pivot];
    swap(&arr[pivot], &arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++)
    {
        if (arr[i] < pivotValue)
        {
            swap(&arr[i], &arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(&arr[storeIndex], &arr[right]);
    return storeIndex;
}
int deterministicSelect(int arr[], int left, int right, int k)
{
    if (left == right)
    {
        return arr[left];
    }
    int pivot = medianOfMedians(arr, left, right);
    int pivotIndex = partition(arr, left, right, pivot);
    if (k == pivotIndex)
    {
        return arr[k];
    }
    else if (k < pivotIndex)
    {
        return deterministicSelect(arr, left, pivotIndex - 1, k);
    }
    else
    {
        return deterministicSelect(arr, pivotIndex + 1, right, k);
    }
}
int main()
{
    int arr[100];
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position (k) to find the k-th smallest element: ");
    scanf("%d", &k);
    if (k < 0 || k >= n)
    {
        printf("Invalid position!\n");
        return 1;
    }
    int result = deterministicSelect(arr, 0, n - 1, k);
    printf("The %d-th smallest element is %d\n", k, result);
    return 0;
}
