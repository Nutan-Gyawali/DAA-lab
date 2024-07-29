#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Job
{
    char id;
    int deadline;
    int profit;
} Job;
int compare(const void *a, const void *b)
{
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int main()
{
    int n;
    printf("Enter the number of Jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    printf("Enter Job details (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Job %d: ", i + 1);
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    qsort(jobs, n, sizeof(Job), compare);
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; ++i)
        slot[i] = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j)
        {
            if (slot[j] == false)
            {
                result[j] = i;  // Assign Job index to this slot
                slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }
    printf("Maximum profit sequence of Jobs:\n");
    for (int i = 0; i < n; ++i)
    {
        if (slot[i])
        {
            printf("%c ", jobs[result[i]].id);
        }
    }
    printf("\n");
    return 0;
}
