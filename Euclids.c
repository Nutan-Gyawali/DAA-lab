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
    int num[] = {5, 7, 11};
    int rem[] = {1, 1, 3};
    int k = sizeof(num) / sizeof(num[0]);
    int x = findX(num, rem, k);
    for (int c = 0; c < 3; c++)
    {
        printf("%d \t", num[c]);
    }
    printf("\n");
    for (int c = 0; c < 3; c++)
    {
        printf("%d \t", rem[c]);
    }
    printf("The solution is %d\n", x);
    return 0;
}
