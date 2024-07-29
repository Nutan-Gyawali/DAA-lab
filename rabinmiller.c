#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long modularExponentiation(long long a, long long b, long long m)
{
    long long result = 1;
    a = a % m;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % m;
        b = b >> 1;
        a = (a * a) % m;
    }
    return result;
}
int rabinMiller(long long n, int k)
{
    if (n <= 1 || n == 4)
        return 0;
    if (n <= 3)
        return 1;
    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; ++i)
    {
        long long a = 2 + rand() % (n - 4);
        long long x = modularExponentiation(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        int prime = 0;
        while (d != n - 1)
        {
            x = (x * x) % n;
            d *= 2;
            if (x == n - 1)
            {
                prime = 1;
                break;
            }
            if (x == 1)
                return 0;
        }
        if (!prime)
            return 0;
    }
    return 1;
}
int main()
{
    srand(time(NULL));
    long long num;
    int iterations = 5;
    printf("Enter an integer: ");
    scanf("%lld", &num);
    int result = rabinMiller(num, iterations);
    if (result)
    {
        printf("%lld is likely a prime number.\n", num);
    }
    else
        printf("%lld is not a prime number.\n", num);
    printf("Name: Nutan Gyawali Roll No: 28387\n");
    return 0;
}
