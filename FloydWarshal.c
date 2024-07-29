#include <stdio.h>
#include <stdlib.h>
#define INF 99999
void floydWarshall(int **w, int n)
{
    int **d;
    d = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        d[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = w[i][j];
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    printf("The shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", d[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        free(d[i]);
    }
    free(d);
}
int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **w;
    w = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        w[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the adjacency matrix (use %d to represent infinity):\n", INF);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    floydWarshall(w, n);
    for (int i = 0; i < n; i++)
    {
        free(w[i]);
    }
    return 0;
}
