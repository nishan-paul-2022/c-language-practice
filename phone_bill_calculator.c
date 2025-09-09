/*
 * Purpose: Calculates and compares costs for two different phone call billing plans (Mile and Juice) based on call durations.
 * Topic: Loops, Conditional Statements, Arithmetic Operations, Input/Output
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main()
{
    int numberOfTestCases;
    int i;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &numberOfTestCases) != 1 || numberOfTestCases < 0)
    {
        printf("Invalid input for number of test cases.\n");
        return 0;
    }

    for (i = 0; i < numberOfTestCases; i++)
    {
        int numberOfCalls;
        int callDuration;
        int mileCost = 0;
        int juiceCost = 0;

        printf("\n--- Test Case %d ---\n", i + 1);
        printf("Enter the number of calls: ");
        if (scanf("%d", &numberOfCalls) != 1 || numberOfCalls <= 0)
        {
            printf("Invalid number of calls. Skipping this test case.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            continue;
        }

        printf("Enter %d call durations (in seconds):\n", numberOfCalls);
        for (int j = 0; j < numberOfCalls; j++)
        {
            if (scanf("%d", &callDuration) != 1 || callDuration < 0)
            {
                printf("Invalid call duration. Skipping remaining calls for this test case.\n");
                // Clear input buffer
                while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
                break; // Exit inner loop
            }

            // Calculate Mile plan cost: 10 cents for every 30 seconds or part thereof
            // (duration / 30) gives full 30-second blocks. +1 accounts for any remaining part.
            // Example: 0-30s -> 1 block, 31-60s -> 2 blocks
            mileCost += ((callDuration / 30) + 1) * 10;

            // Calculate Juice plan cost: 15 cents for every 60 seconds or part thereof
            // (duration / 60) gives full 60-second blocks. +1 accounts for any remaining part.
            // Example: 0-60s -> 1 block, 61-120s -> 2 blocks
            juiceCost += ((callDuration / 60) + 1) * 15;
        }

        // Compare costs and print the result
        if (mileCost < juiceCost)
        {
            printf("Case %d: Mile %d\n", i + 1, mileCost);
        }
        else if (juiceCost < mileCost)
        {
            printf("Case %d: Juice %d\n", i + 1, juiceCost);
        }
        else // mileCost == juiceCost
        {
            printf("Case %d: Mile Juice %d\n", i + 1, mileCost);
        }
    }

    return EXIT_SUCCESS;
}
