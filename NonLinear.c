#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int findKthSmallest(int arr[], int n, int k)
{
    if (k <= 0 || k > n)
    {
        printf("Invalid position!\n");
        return -1;
    }
    selectionSort(arr, n);
    return arr[k - 1];
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
    int result = findKthSmallest(arr, n, k);
    if (result != -1)
    {
        printf("The %d-th smallest element is %d\n", k, result);
    }
    return 0;
}
