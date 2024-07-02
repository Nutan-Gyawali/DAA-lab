#include <stdio.h>

int main()
{
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }

    printf("\n");

    printf("\nNAME: Nutan Gyawali \nRoll Number: 28387/078");

    fflush(stdout); // Flush output buffer

    return 0;
}
