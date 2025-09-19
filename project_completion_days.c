/*
 * Purpose: Calculates the number of days required to complete a project based on total work and daily work capacity.
 * Topic: Basic Arithmetic, Loops, Conditional Logic, Integer Division
 */

#include <stdio.h>

int main(void) {
    int total_work, num_workers, worker_capacity, total_daily_capacity, days_needed;

    printf("Enter total work and number of workers: ");

    while (scanf("%d %d", &total_work, &num_workers) != EOF) {
        total_daily_capacity = 0;
        
        for (int i = 0; i < num_workers; i++) {
            printf("Enter capacity of worker %d: ", i+1);
            scanf("%d", &worker_capacity);
            total_daily_capacity += worker_capacity;
        }

        if (total_daily_capacity == 0) {
            printf("Project cannot be finished (no work capacity).\n");
        } else if (total_work <= total_daily_capacity) {
            printf("Project will finish within 1 day.\n");
        } else {
            days_needed = (total_work + total_daily_capacity - 1) / total_daily_capacity; 
            printf("Project will finish within %d days.\n", days_needed);
        }

        printf("\nEnter total work and number of workers: ");
    }

    return 0;
}
