#include <stdio.h>
#include <stdlib.h> // For abs function
#define N_MAX 20    // Maximum size of chessboard
char board[N_MAX][N_MAX];
int queenPositions[N_MAX]; // To store column positions of queens
void printBoard(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'Q')
            {
                printf("Q%d ", i + 1); // Print row position of queen
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
}
int isSafe(int row, int col, int N)
{
    for (int i = 0; i < col; i++)
    {
        if (queenPositions[i] == row || abs(queenPositions[i] - row) == abs(i - col))
            return 0;
    }
    return 1;
}
int solveNQueens(int col, int N)
{
    if (col >= N)
        return 1;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, N))
        {
            board[i][col] = 'Q';
            queenPositions[col] = i;
            if (solveNQueens(col + 1, N))
                return 1;
            board[i][col] = '-';
        }
    }
    return 0;
}
int main()
{
    int N;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &N);
    if (N <= 0 || N > N_MAX)
    {
        printf("Invalid input for N. Please enter a value between 1 and %d.\n", N_MAX);
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = '-';
        }
    }
    if (solveNQueens(0, N))
    {
        printf("\nSolution found:\n");
        printBoard(N);
        printf("\nQueen positions (row, column):\n");
        for (int i = 0; i < N; i++)
        {
            printf("Q%d, %d\n", i + 1, queenPositions[i] + 1);
        }
    }
    else
    {
        printf("No solution exists for N = %d.\n", N);
    }
    return 0;
}
