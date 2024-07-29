#include <stdio.h>
void subsetSum(int set[], int n, int sum, int subset[], int index)
{
    if (sum == 0)
    {
        printf("{ ");
        for (int i = 0; i < index; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }
    if (n == 0 || sum < 0)
        return;
    subsetSum(set, n - 1, sum, subset, index);
    subset[index] = set[n - 1];
    subsetSum(set, n - 1, sum - set[n - 1], subset, index + 1);
}
int main()
{
    int n;
    printf("Enter number of elements in the set: ");
    scanf("%d", &n);
    int set[n];
    printf("\nEnter elements of the set:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &set[i]);
    }
    int sum;
    printf("\nEnter target sum: ");
    scanf("%d", &sum);
    int subset[n]; // Assuming maximum possible size
    printf("\nSubsets with sum %d are:\n", sum);
    subsetSum(set, n, sum, subset, 0);
    return 0;
}
