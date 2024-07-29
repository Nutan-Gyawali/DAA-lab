#include <stdio.h>
#include <string.h>

void runLengthEncode(char *str)
{
    int n = strlen(str);

    // Traverse the input string
    for (int i = 0; i < n; i++)
    {
        // Count occurrences of current character
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        // Print the count followed by the character
        printf("%d%c", count, str[i]);
    }
    printf("\n");
}

int main()
{
    char str[] = "BBBWWB";

    printf("Original string: %s\n", str);
    printf("Expected run-length encoded string: 3B2W1B\n");
    printf("Actual run-length encoded string: ");
    runLengthEncode(str);

    return 0;
}