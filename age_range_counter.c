/*
 * Purpose: Counts how many entered ages fall within a specific range (50-60).
 * Topic: Input/Output, Loops, Conditional Statements
 */

#include <stdio.h>

int main() {
    int age;
    int countInRange;

    printf("Enter ages to count those between 50 and 60 (inclusive).\n");
    printf("Enter 0 to process the current batch and start a new one.\n");
    printf("Ctrl+D to exit the program.\n\n");

    // Outer loop to allow multiple batches of input
    while (1) {
        countInRange = 0; // Reset count for each new batch

        printf("--- New Batch ---\n");
        while (scanf("%d", &age) == 1) {
            if (age == 0) {
                break; // End of current batch, process and print count
            }

            if (age >= 50 && age <= 60) {
                countInRange++;
            }
        }

        // If scanf failed (e.g., non-numeric input or EOF), break the outer loop
        if (feof(stdin) || ferror(stdin)) {
            printf("\nExiting program.\n");
            break;
        }

        printf("Number of ages in range 50-60: %d\n\n", countInRange);

        // Clear input buffer for the next iteration, if any
        while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
    }

    return 0;
}
