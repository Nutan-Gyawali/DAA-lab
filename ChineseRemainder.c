#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
int modInverse(int a, int m)
{
    a = a % m;
    for (int x = 1; x < m; x++)
    {
        if ((a * x) % m == 1)
        {
            return x;
        }
    }
    return -1; // Inverse doesn't exist if we reach here
}
int findX(int num[], int rem[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
    {
        prod *= num[i];
    }
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int Ni = prod / num[i];
        int Mi = modInverse(Ni, num[i]);
        result += rem[i] * Ni * Mi;
    }
    return result % prod;
}
int main()
{
    int num[] = {3, 5, 13};
    int rem[] = {2, 2, 4};
    int k = sizeof(num) / sizeof(num[0]);

    for (int i = 0; i < 3; i++)
    {
        printf("%d  %d", num[i], rem[i]);
        printf("\n");
    }
    int x = findX(num, rem, k);
    printf("The solution is %d\n", x);
    return 0;
}
