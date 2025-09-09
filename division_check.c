// Purpose: Reads two floating-point numbers, performs division, and checks the integer part of the quotient.
// Topic: Floating-Point Input, Division, Integer Conversion, Switch Statement
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    float numerator, denominator;
    int quotient_int;

    printf("Enter two numbers separated by a comma (e.g., '15.5, 3.1'):\n");

    // Read the numerator and denominator
    // scanf returns the number of successfully matched and assigned input items.
    // We expect 2 items (numerator and denominator) to be successfully read.
    if (scanf("%f, %f", &numerator, &denominator) == 2) {

        // Check for division by zero before performing the division
        if (denominator == 0.0f) {
            fprintf(stderr, "Error: Division by zero is not allowed.\n");
            // Clear the input buffer in case of partial reads or invalid characters
            while (getchar() != '\n');
            return EXIT_FAILURE;
        }

        // Perform the division and get the integer part of the quotient
        quotient_int = (int)(numerator / denominator);

        // Check the integer part of the quotient against specific values
        switch (quotient_int) {
            case 5:
            case 3:
            case 10:
                printf("Result of division (integer part: %d) -> CAUGHT\n", quotient_int);
                break;
            default:
                printf("Result of division (integer part: %d) -> ERROR\n", quotient_int);
                break;
        }
        return 0;
    } else {
        // Handle cases where the input format is incorrect or EOF is reached prematurely
        fprintf(stderr, "Error: Invalid input format. Please use 'number, number'.\n");
        // Clear the input buffer in case of partial reads or invalid characters
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }
}
