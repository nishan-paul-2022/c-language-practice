/*
 * Purpose: Estimates the number of days to complete a project based on a target work amount and daily progress.
 * Topic: Loops, Input/Output, Basic Arithmetic
 */

#include <stdio.h>

int main(void) {
    int target_work, num_daily_entries, total_daily_progress, current_progress, days_count, accumulated_progress;

    printf("Enter the total work amount required for the project (or Ctrl+D to exit): ");
    while (scanf("%d", &target_work) == 1) {
        printf("Enter the number of daily progress entries: ");
        if (scanf("%d", &num_daily_entries) != 1 || num_daily_entries <= 0) {
            printf("Invalid number of daily progress entries. Please enter a positive integer.\n");
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin)); // Clear buffer
            printf("\nEnter the total work amount required for the project (or Ctrl+D to exit): ");
            continue;
        }

        total_daily_progress = 0;
        printf("Enter %d daily progress values:\n", num_daily_entries);
        for (int i = 0; i < num_daily_entries; i++) {
            if (scanf("%d", &current_progress) != 1) {
                printf("Invalid input for daily progress. Exiting.\n");
                return 0;
            }
            total_daily_progress += current_progress;
        }

        days_count = 0;
        accumulated_progress = 0;

        if (total_daily_progress > 0) {
            while (accumulated_progress < target_work) {
                accumulated_progress += total_daily_progress;
                days_count++;
            }
            printf("THE PROJECT WILL FINISH WITHIN %d DAY(S)\n\n", days_count);
        } else {
            printf("No progress is being made daily. The project will never finish.\n\n");
        }

        printf("Enter the total work amount required for the next project (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
