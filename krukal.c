/*
 * Program: Kruskal's Algorithm
 *
 * Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest.
 * It is a greedy algorithm in graph theory as it finds a minimum spanning tree for a connected weighted graph adding increasing cost arcs at each step.
 * This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
 * If the graph is not connected, then it finds a minimum spanning forest (a minimum spanning tree for each connected component).
 *
 * Time Complexity: O(ElogE) or O(ElogV). Sorting of edges takes O(ELogE) time.
 * After sorting, we iterate through all edges and apply find-union algorithm.
 * The find and union operations can take at most O(LogV) time. So overall complexity is O(ELogE + ELogV) time.
 * The value of E can be at most O(V^2), so O(LogV) and O(LogE) are the same.
 * Therefore, overall time complexity is O(ElogE) or O(ElogV)
 * Space Complexity: O(E + V)
 *
 */

#include <stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0};
int mincost = 0;
int cost[10][10];

int find(int i)
{
    while (visited[i])
        i = visited[i];
    return i;
}

int uni(int i, int j)
{
    if (i != j)
    {
        visited[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\n");
    while (ne < n)
    {
        int min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (uni(u, v))
        {
            printf("Edge %d: (%d %d) cost: %d\n", ne, a, b, min);
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}
