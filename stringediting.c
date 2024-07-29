#include <stdio.h>
#include <string.h>
int editCount(char initStr[], char finalStr[], int initLen, int finalLen)
{

    int dp[initLen + 1][finalLen + 1];
    for (int i = 0; i <= initLen; i++)
    {
        for (int j = 0; j <= finalLen; j++)
        {

            if (i == 0)
                dp[i][j] = j; // Min. operations = j

            else if (j == 0)
                dp[i][j] = i;

            else if (initStr[i - 1] == finalStr[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + (dp[i - 1][j] < dp[i][j - 1] ? (dp[i - 1][j] < dp[i - 1][j - 1] ? dp[i - 1][j] : dp[i - 1][j - 1])
                                                            : dp[i][j - 1]);
        }
    }
    return dp[initLen][finalLen];
}
int main()
{
    char initStr[100], finalStr[100];
    printf("Enter the initial string: ");
    scanf("%s", initStr);
    printf("Enter the final string: ");
    scanf("%s", finalStr);
    int initLen = strlen(initStr);
    int finalLen = strlen(finalStr);
    int count = editCount(initStr, finalStr, initLen, finalLen);
    printf("Minimum edit distance between '%s' and '%s' is %d\n", initStr, finalStr, count);
    return 0;
}
