/*
 * Program: Job Sequencing Problem
 *
 * Job Sequencing Problem is a variation of the Activity Selection Problem.
 * The difference between the two is that in the Activity Selection Problem, a single resource is available and each activity is to be scheduled in this single resource, whereas in Job Sequencing Problem there are multiple resources available and each activity is to be scheduled in a single resource.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 *
 */
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a job
struct Job
{
    int id;
    int deadline;
    int profit;
};

// A utility function to compare two jobs according to their profit
int compare(const void *a, const void *b)
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Function to schedule the jobs to maximize profit
void jobSequencing(struct Job jobs[], int n)
{
    // Sort all jobs according to decreasing order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

    // Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Array to keep track of free time slots
    int *slots = (int *)malloc(maxDeadline * sizeof(int));
    for (int i = 0; i < maxDeadline; i++)
    {
        slots[i] = -1;
    }

    int totalProfit = 0;
    int numJobs = 0;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (we start from the last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            // Free slot found
            if (slots[j] == -1)
            {
                slots[j] = i;
                totalProfit += jobs[i].profit;
                numJobs++;
                break;
            }
        }
    }

    // Print the result
    printf("Maximum profit: %d\n", totalProfit);
    printf("Number of jobs: %d\n", numJobs);
    printf("Maximum profit sequence of jobs: ");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slots[i] != -1)
        {
            printf("%d ", jobs[slots[i]].id);
        }
    }
    printf("\n");

    // Free the allocated memory
    free(slots);
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job *jobs = (struct Job *)malloc(n * sizeof(struct Job));
    printf("Enter the deadline and profit of each job:\n");
    for (int i = 0; i < n; i++)
    {
        jobs[i].id = i + 1;
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    // Free the allocated memory
    free(jobs);

    return 0;
}
