#include <stdio.h>
#include <limits.h>

int setmini(int A[], int N)
{
    int mini = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < mini)
        {
            mini = A[i];
        }
    }
    return mini;
}

int setmaxi(int A[], int N)
{
    int maxi = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > maxi)
        {
            maxi = A[i];
        }
    }
    return maxi;
}

int main()
{
    int A[10];
    int N, i;

    printf("Enter the number of elements (max 10): ");
    scanf("%d", &N);

    if (N > 10)
    {
        printf("Number of elements should not exceed 10.\n");
        return 1;
    }

    printf("Enter %d elements:\n", N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Minimum element is: %d\n", setmini(A, N));
    printf("Maximum element is: %d\n", setmaxi(A, N));

    return 0;
}
