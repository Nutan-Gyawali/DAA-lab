/*
 *
 * Program: Matrix Chain Multiplication
 *
 * The matrix chain multiplication problem is a combinatorial optimization problem where we have a sequence of matrices and the goal is to find the most efficient way to multiply these matrices.
 *
 * Time Complexity: O(n^3)
 * Space Complexity: O(n^2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int MatrixChainOrder(int p[], int i, int j, int **dp, int **bracket);
void printOptimalParenthesis(int i, int j, int **bracket, int *name);

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int **dp = (int **)malloc(n * sizeof(int *));
    int **bracket = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; ++i)
    {
        dp[i] = (int *)malloc(n * sizeof(int));
        bracket[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j)
        {
            dp[i][j] = -1;
            bracket[i][j] = -1;
        }
    }

    printf("Enter dimensions of matrices:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, 1, n - 1, dp, bracket));

    int name = 1;
    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n - 1, bracket, &name);
    printf("\n");

    // Deallocate memory
    for (int i = 0; i < n; ++i)
    {
        free(dp[i]);
        free(bracket[i]);
    }
    free(arr);
    free(dp);
    free(bracket);

    return 0;
}

int MatrixChainOrder(int p[], int i, int j, int **dp, int **bracket)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int k;
    int mini = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k, dp, bracket) +
                MatrixChainOrder(p, k + 1, j, dp, bracket) +
                p[i - 1] * p[k] * p[j];

        if (count < mini)
        {
            mini = count;
            bracket[i][j] = k;
        }
    }

    dp[i][j] = mini;
    return mini;
}

void printOptimalParenthesis(int i, int j, int **bracket, int *name)
{
    if (i == j)
    {
        printf("A%d", *name);
        (*name)++;
        return;
    }

    printf("(");
    printOptimalParenthesis(i, bracket[i][j], bracket, name);
    printOptimalParenthesis(bracket[i][j] + 1, j, bracket, name);
    printf(")");
}
