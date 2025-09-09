/*
 * Purpose: Counts the number of persons meeting specific criteria (weight < 50 and height > 170).
 * Topic: Input Processing, Loops, Conditional Statements, Counting
 */
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    int num_persons;
    int weight, height;
    int person_index;
    int countable_persons_count = 0;

    printf("Enter the number of persons: ");
    // Read the number of persons and validate input
    if (scanf("%d", &num_persons) != 1) {
        fprintf(stderr, "Error: Invalid input for the number of persons.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }

    // Validate that the number of persons is non-negative
    if (num_persons < 0) {
        fprintf(stderr, "Error: Number of persons cannot be negative.\n");
        return EXIT_FAILURE;
    }

    printf("Enter weight and height for each person (e.g., 'weight height'):\n");

    // Loop through each person to read their details and check criteria
    for (person_index = 0; person_index < num_persons; ++person_index) {
        printf("Person %d: ", person_index + 1);
        // Read weight and height, expecting space-separated values
        if (scanf("%d %d", &weight, &height) != 2) {
            fprintf(stderr, "\nError: Invalid input for weight and height for person %d.\n", person_index + 1);
            // Clear the input buffer
            while (getchar() != '\n');
            // Decide whether to continue or exit. For this example, we'll exit.
            return EXIT_FAILURE;
        }

        // Check if the person meets the criteria: weight < 50 and height > 170
        if (weight < 50 && height > 170) {
            printf("  -> Countable\n");
            countable_persons_count++;
        } else {
            printf("  -> Not countable\n");
        }
    }

    // Print the final count of countable persons
    printf("\nTotal number of countable persons: %d\n", countable_persons_count);

    return 0;
}
