// Purpose: Calculates the number of days required to complete a project based on total work and daily work capacity.
// Topic: Basic Arithmetic, Loops, Conditional Logic, Integer Division

#include <stdio.h>

int main() {
    int total_project_work; // Total work units required for the project
    int num_workers;        // Number of workers
    int worker_capacity;    // Individual worker's daily capacity
    int total_daily_capacity; // Sum of all workers' daily capacities
    int i;                  // Loop counter
    int days_needed;        // Calculated days to complete the project

    // Read total project work and number of workers until EOF
    while (scanf("%d %d", &total_project_work, &num_workers) != EOF) {
        total_daily_capacity = 0; // Reset total daily capacity for each new project

        // Read individual worker capacities and sum them up
        for (i = 0; i < num_workers; i++) {
            scanf("%d", &worker_capacity);
            total_daily_capacity += worker_capacity;
        }

        // Calculate days needed
        if (total_daily_capacity == 0) {
            // Avoid division by zero if no work can be done
            printf("Project cannot be finished (no work capacity).\n");
        } else if (total_project_work <= total_daily_capacity) {
            // If total work can be done within 1 day
            printf("Project will finish within 1 day.\n");
        } else {
            // Calculate days using integer ceiling division: (numerator + denominator - 1) / denominator
            days_needed = (total_project_work + total_daily_capacity - 1) / total_daily_capacity;
            printf("Project will finish within %d days.\n", days_needed);
        }
    }

    return 0;
}
