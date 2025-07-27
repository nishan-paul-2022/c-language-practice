// Purpose: Calculates the sum of an arithmetic series where the first term is 2 and the common difference is 4.
// Topic: Arithmetic Progression, Series Summation, Loops
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    int num_terms;
    int term_index;
    int sum = 0;
    int current_term = 2; // The first term of the series

    printf("Enter the number of terms (n) for the series (2, 6, 10, 14, ...):\n");
    printf("Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to exit.\n");

    // Read the number of terms until EOF is encountered or an input error occurs
    while (scanf("%d", &num_terms) == 1) {
        // Validate input: number of terms should be non-negative
        if (num_terms < 0) {
            fprintf(stderr, "Error: Number of terms cannot be negative. Please try again.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue; // Ask for input again
        }

        // Reset sum and current_term for each new input 'n'
        sum = 0;
        current_term = 2; // First term is 2

        // Calculate the sum of the series using a loop
        for (term_index = 0; term_index < num_terms; ++term_index) {
            sum += current_term;
            current_term += 4; // The common difference is 4
        }

        // Print the calculated sum
        printf("The sum of the first %d terms is: %d\n", num_terms, sum);

        // Prompt for the next input
        printf("Enter the next number of terms (or EOF to exit): ");
    }

    // Check if the loop terminated due to an error rather than EOF
    if (ferror(stdin)) {
        perror("Error reading input");
        return EXIT_FAILURE; // Indicate failure
    }

    printf("Exiting program.\n");
    return 0; // Indicate success
}
