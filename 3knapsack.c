#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and corresponding value of Item
struct Item
{
    int profit, weight;
};

// Comparison function to sort Item according to profit/weight ratio
int cmp(const void *a, const void *b)
{
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    double r1 = (double)item1->profit / (double)item1->weight;
    double r2 = (double)item2->profit / (double)item2->weight;
    return r2 - r1 > 0 ? 1 : -1;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    // Sorting Item on basis of ratio
    qsort(arr, N, sizeof(struct Item), cmp);

    double finalvalue = 0.0;

    // Looping through all items
    for (int i = 0; i < N; i++)
    {
        // If adding Item won't overflow, add it completely
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        else
        {
            // If we can't add current Item, add fractional part of it
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

// Driver code
int main()
{
    int N, W, i;

    printf("Enter the number of items: ");
    scanf("%d", &N);

    struct Item *arr = (struct Item *)malloc(N * sizeof(struct Item));

    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the profit and weight of each item:\n");
    for (i = 0; i < N; i++)
    {
        printf("Item %d:\n", i + 1);
        printf("Profit: ");
        scanf("%d", &arr[i].profit);
        printf("Weight: ");
        scanf("%d", &arr[i].weight);
    }

    // Function call
    double maxProfit = fractionalKnapsack(W, arr, N);
    printf("Maximum profit: %lf\n", maxProfit);

    free(arr);
    return 0;
}
