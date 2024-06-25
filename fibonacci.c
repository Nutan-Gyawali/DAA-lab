#include <stdio.h>

int main()
{
    int i, n;

    // initialize first and second terms
    int t1 = 0, t2 = 1;

    // initialize the next term (3rd term)
    int nextTerm = t1 + t2;

    // get number of terms from user
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // handle cases where n is 1 or 2
    if (n <= 0)
    {
        printf("Please enter a positive integer.\n");
    }
    else if (n == 1)
    {
        printf("Fibonacci Series: %d\n", t1);
    }
    else
    {
        // print the first two terms t1 and t2
        printf("Fibonacci Series: %d, %d", t1, t2);

        // print 3rd to nth terms
        for (i = 3; i <= n; ++i)
        {
            printf(", %d", nextTerm);
            t1 = t2;
            t2 = nextTerm;
            nextTerm = t1 + t2;
        }
        printf("\n");
    }

    return 0;
}
