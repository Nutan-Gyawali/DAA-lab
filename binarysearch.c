

#include <stdio.h>

int binarySearch(int arr[], int size, int key);

int main()
{
    int n, key, index;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    index = binarySearch(arr, n, key);

    if (index == -1)
    {
        printf("Key not found\n");
        printf("\nNAME: Nutan Gyawali \nRoll Number: 28387/078");
    }

    else
    {
        printf("Key found at position %d\n", index + 1);
        printf("\nNAME: Nutan Gyawali \nRoll Number: 28387/078");
    }

    return 0;
}

int binarySearch(int arr[], int size, int key)
{
    int low = 0, high = size - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
