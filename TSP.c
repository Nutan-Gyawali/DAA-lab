#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int tsp(int graph[][4], int path[], int n, int pos, int visited, int **dp)
{
    if (visited == ((1 << n) - 1))
        return graph[pos][0];
    if (dp[visited][pos] != -1)
        return dp[visited][pos];
    int ans = INT_MAX, next_city = -1;
    for (int city = 0; city < n; city++)
    {
        if ((visited & (1 << city)) == 0)
        {
            int newAns = graph[pos][city] + tsp(graph, path, n, city, visited | (1 << city), dp);
            if (newAns < ans)
            {
                ans = newAns;
                next_city = city;
            }
        }
    }
    path[visited] = next_city;
    return dp[visited][pos] = ans;
}
void printPath(int path[], int n)
{
    printf("Path: ");
    int current = 0, visited = 1;
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d -> ", current);
        current = path[visited];
        visited |= (1 << current);
    }
    printf("%d -> %d\n", current, 0);
}
int main()
{
    int graph[4][4] = {{0, 10, 15, 20},
                       {5, 0, 9, 10},
                       {6, 13, 0, 12},
                       {8, 8, 9, 0}};
    int n = 4;
    for (int c = 0; c < 4; c++)
    {
        for (int d = 0; d < 4; d++)
            printf("%d  ", graph[c][d]);
        printf("\n");
    }
    int path[1 << n]; // Array to store the path
    int **dp = (int **)malloc((1 << n) * sizeof(int *));
    for (int i = 0; i < (1 << n); i++)
    {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    int min_cost = tsp(graph, path, n, 0, 1, dp);
    printf("Minimum cost is %d\n", min_cost);
    printPath(path, n);
    for (int i = 0; i < (1 << n); i++)
        free(dp[i]);
    free(dp);
    return 0;
}
