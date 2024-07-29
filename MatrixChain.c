#include <stdio.h>
#include <limits.h>
void matrixChainOrder(int p[], int n)
{
    int m[n][n], s[n][n];
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("\n Minimum number of multiplications: %d\n", m[1][n - 1]);
}
int main()
{
    int p;
    int arr[] = {3, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (p = 0; p < n; p++)
    {
        printf("%d\t", arr[p]);
    }
    matrixChainOrder(arr, n);
    return 0;
}
