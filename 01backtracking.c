#include <stdio.h>
#include <stdbool.h>
#define MAX_ITEMS 5
struct Item
{
    int weight;
    int value;
};
struct Item items[MAX_ITEMS];
int knapsackCapacity;
int currentWeight = 0;
int currentValue = 0;
int maxPossibleValue = 0;
bool solution[MAX_ITEMS];
void knapsackBacktrack(int index)
{
    if (index == MAX_ITEMS)
    {
        if (currentValue > maxPossibleValue)
        {
            maxPossibleValue = currentValue;
            for (int i = 0; i < MAX_ITEMS; ++i)
            {
                solution[i] = (items[i].weight <= knapsackCapacity);
            }
        }
        return;
    }
    if (currentWeight + items[index].weight <= knapsackCapacity)
    {
        currentWeight += items[index].weight;
        currentValue += items[index].value;
        knapsackBacktrack(index + 1);

        currentWeight -= items[index].weight;
        currentValue -= items[index].value;
    }
    knapsackBacktrack(index + 1);
}
void solveKnapsack()
{
    knapsackBacktrack(0);
    printf("Optimal Solution:\n");
    printf("Item\tWeight\tValue\tInclude\n");
    for (int i = 0; i < MAX_ITEMS; ++i)
    {
        printf("%d\t%d\t%d\t%s\n", i + 1, items[i].weight, items[i].value, solution[i] ? "Yes" : "No");
    }
    printf("Total Value: %d\n", maxPossibleValue);
}
int main()
{
    items[0].weight = 4;
    items[0].value = 5;
    items[1].weight = 7;
    items[1].value = 30;
    items[2].weight = 9;
    items[2].value = 48;
    items[3].weight = 43;
    items[3].value = 16;
    knapsackCapacity = 53;

    for (int c = 0; c < 3; c++)
    {
        printf("%d\t", items[c].weight);
        printf("%d", items[c].value);
        printf("\n");
    }
    solveKnapsack();
    return 0;
}
