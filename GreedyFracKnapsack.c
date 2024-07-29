#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int value;
    int weight;
};
int cmp(const void *a, const void *b)
{
    double r1 = ((double)((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double r2 = ((double)((struct Item *)b)->value) / ((struct Item *)b)->weight;
    return (r1 > r2) ? -1 : 1;
}
double greedyKnapsack(int W, struct Item arr[], int n)
{
    // Sort items by value to weight ratio
    qsort(arr, n, sizeof(struct Item), cmp);
    double x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }
    int tempW = W;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight > tempW)
        {
            break;
        }
        x[i] = 1.0;
        tempW -= arr[i].weight;
    }
    if (tempW > 0 && n > 0)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (arr[i].weight > tempW)
            {
                break;
            }
        }
        if (i < n)
        {
            x[i] = (double)tempW / arr[i].weight;
        }
    }
    double finalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        finalValue += x[i] * arr[i].value;
    }
    return finalValue;
}
int main()
{
    int W, n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum value we can obtain = %.2f\n", greedyKnapsack(W, arr, n));
    return 0;
}
