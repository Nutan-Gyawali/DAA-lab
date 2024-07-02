#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long fact = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);

    // shows error if the user enters a negative integer
    if (n < 0)
    {
        printf("Error! Factorial of a negative number doesn't exist.");
        printf("\nNAME: Nutan Gyawali \nRoll Number: 28387/078");
    }

    else
    {
        for (i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        printf("Factorial of %d = %llu", n, fact);
        printf("\nNAME: Nutan Gyawali \nRoll Number: 28387/078");
    }

    return 0;
}
