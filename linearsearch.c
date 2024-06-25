#include <stdio.h>

int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Driver code
int main(void)
{
    int N, x;

    // Take the size of the array as input from the user
    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &N) != 1 || N <= 0)
    {
        printf("Invalid input for number of elements.\n");
        return 1;
    }

    int arr[N];

    // Take the elements of the array as input from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid input for array element.\n");
            return 1;
        }
    }

    // Take the key to be searched as input from the user
    printf("Enter the element to be searched: ");
    if (scanf("%d", &x) != 1)
    {
        printf("Invalid input for the element to be searched.\n");
        return 1;
    }

    // Function call
    int result = search(arr, N, x);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);

    return 0;
}
