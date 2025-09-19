/*
 * Purpose: Calculates the sum of an arithmetic series where the first term is 2 and the common difference is 4.
 * Topic: Arithmetic Progression, Series Summation, Loops
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char title[] = "Enter the number of terms (n) for the series (2, 6, 10, 14, ...): ";
    printf("%s", title);

    // Read number of terms until EOF or input error
    int num_terms;
    while (scanf("%d", &num_terms) == 1) {
        // Validate input: number of terms should be non-negative
        if (num_terms < 0) {
            fprintf(stderr, "Number of terms cannot be negative. Please try again.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        // Reset sum and current_term for each new input 'n'
        int sum = 0;
        int current_term = 2; // Reset to first term

        // Calculate sum using loop
        for (int term_index = 0; term_index < num_terms; ++term_index) {
            sum += current_term;
            current_term += 4; // The common difference is 4
        }

        printf("The sum of the first %d terms is: %d\n", num_terms, sum);

        printf("\n%s", title); // Prompt for the next input
    }

    // Check if loop terminated due to error
    if (ferror(stdin)) {
        perror("Error reading input");
        return 0;
    }

    printf("Exiting program.\n");
    return 0;
}
