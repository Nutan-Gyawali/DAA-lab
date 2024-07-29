#include <stdio.h>
void findMaxMin(int arr[], int n, int *max, int *min)
{
    if (n <= 0)
        return;
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
    }
}
int main()
{
    int arr[100];
    int n, max, min;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    findMaxMin(arr, n, &max, &min);
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);

    return 0;
}
