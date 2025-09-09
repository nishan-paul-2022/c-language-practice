/*
 * Purpose: Estimates the number of days to complete a project based on a target work amount and daily progress.
 * Topic: Loops, Input/Output, Basic Arithmetic
 */

#include <stdio.h>

int main()
{
    int target_work_amount;
    int number_of_daily_progress_entries;
    int total_daily_progress;
    int current_progress;
    int days_count;
    int accumulated_progress;

    printf("Enter the total work amount required for the project (or Ctrl+D to exit): ");
    while (scanf("%d", &target_work_amount) == 1)
    {
        printf("Enter the number of daily progress entries: ");
        if (scanf("%d", &number_of_daily_progress_entries) != 1 || number_of_daily_progress_entries <= 0)
        {
            printf("Invalid number of daily progress entries. Please enter a positive integer.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            printf("\nEnter the total work amount required for the project (or Ctrl+D to exit): ");
            continue;
        }

        total_daily_progress = 0;
        printf("Enter %d daily progress values:\n", number_of_daily_progress_entries);
        for (int i = 0; i < number_of_daily_progress_entries; i++)
        {
            if (scanf("%d", &current_progress) != 1)
            {
                printf("Invalid input for daily progress. Exiting.\n");
                return 0;
            }
            total_daily_progress += current_progress;
        }

        days_count = 0;
        accumulated_progress = 0;

        // Calculate the number of days until accumulated progress meets or exceeds target
        if (total_daily_progress > 0) // Avoid infinite loop if no progress is made
        {
            while (accumulated_progress < target_work_amount)
            {
                accumulated_progress += total_daily_progress;
                days_count++;
            }
            printf("THE PROJECT WILL FINISH WITHIN %d DAY(S)\n\n", days_count);
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
