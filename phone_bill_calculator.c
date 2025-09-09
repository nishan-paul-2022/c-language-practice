/*
 * Purpose: Calculates and compares costs for two different phone call billing plans (Mile and Juice) based on call durations.
 * Topic: Loops, Conditional Statements, Arithmetic Operations, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number_of_test_cases;
    int i;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &number_of_test_cases) != 1 || number_of_test_cases < 0)
    {
        printf("Invalid input for number of test cases.\n");
        return 0;
    }

    for (i = 0; i < number_of_test_cases; i++)
    {
        int number_of_calls;
        int call_duration;
        int mile_cost = 0;
        int juice_cost = 0;

        printf("\n--- Test Case %d ---\n", i + 1);
        printf("Enter the number of calls: ");
        if (scanf("%d", &number_of_calls) != 1 || number_of_calls <= 0)
        {
            printf("Invalid number of calls. Skipping this test case.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            continue;
        }

        printf("Enter %d call durations (in seconds):\n", number_of_calls);
        for (int j = 0; j < number_of_calls; j++)
        {
            if (scanf("%d", &call_duration) != 1 || call_duration < 0)
            {
                printf("Invalid call duration. Skipping remaining calls for this test case.\n");
                // Clear input buffer
                while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
                break; // Exit inner loop
            }

            // Calculate Mile plan cost: 10 cents for every 30 seconds or part thereof
            // (duration / 30) gives full 30-second blocks. +1 accounts for any remaining part.
            // Example: 0-30s -> 1 block, 31-60s -> 2 blocks
            mile_cost += ((call_duration / 30) + 1) * 10;

            // Calculate Juice plan cost: 15 cents for every 60 seconds or part thereof
            // (duration / 60) gives full 60-second blocks. +1 accounts for any remaining part.
            // Example: 0-60s -> 1 block, 61-120s -> 2 blocks
            juice_cost += ((call_duration / 60) + 1) * 15;
        }

        // Compare costs and print the result
        if (mile_cost < juice_cost)
        {
            printf("Case %d: Mile %d\n", i + 1, mile_cost);
        }
        else if (juice_cost < mile_cost)
        {
            printf("Case %d: Juice %d\n", i + 1, juice_cost);
        }
        else // mile_cost == juice_cost
        {
            printf("Case %d: Mile Juice %d\n", i + 1, mile_cost);
        }
    }

    return EXIT_SUCCESS;
}
