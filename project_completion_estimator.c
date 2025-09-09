/*
 * Purpose: Estimates the number of days to complete a project based on a target work amount and daily progress.
 * Topic: Loops, Input/Output, Basic Arithmetic
 */

#include <stdio.h>

int main()
{
    int targetWorkAmount;
    int numberOfDailyProgressEntries;
    int totalDailyProgress;
    int currentProgress;
    int daysCount;
    int accumulatedProgress;

    printf("Enter the total work amount required for the project (or Ctrl+D to exit): ");
    while (scanf("%d", &targetWorkAmount) == 1)
    {
        printf("Enter the number of daily progress entries: ");
        if (scanf("%d", &numberOfDailyProgressEntries) != 1 || numberOfDailyProgressEntries <= 0)
        {
            printf("Invalid number of daily progress entries. Please enter a positive integer.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            printf("\nEnter the total work amount required for the project (or Ctrl+D to exit): ");
            continue;
        }

        totalDailyProgress = 0;
        printf("Enter %d daily progress values:\n", numberOfDailyProgressEntries);
        for (int i = 0; i < numberOfDailyProgressEntries; i++)
        {
            if (scanf("%d", &currentProgress) != 1)
            {
                printf("Invalid input for daily progress. Exiting.\n");
                return 0;
            }
            totalDailyProgress += currentProgress;
        }

        daysCount = 0;
        accumulatedProgress = 0;

        // Calculate the number of days until accumulated progress meets or exceeds target
        if (totalDailyProgress > 0) // Avoid infinite loop if no progress is made
        {
            while (accumulatedProgress < targetWorkAmount)
            {
                accumulatedProgress += totalDailyProgress;
                daysCount++;
            }
            printf("THE PROJECT WILL FINISH WITHIN %d DAY(S)\n\n", daysCount);
        }
        else
        {
            printf("No progress is being made daily. The project will never finish.\n\n");
        }
        
        printf("Enter the total work amount required for the next project (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
