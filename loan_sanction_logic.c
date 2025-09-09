/*
 * Purpose: Implements a specific, albeit unusual, logic for loan sanctioning based on input values.
 * Topic: Input Processing, Conditional Logic, Financial Calculations (simplified/custom)
 */
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS, EXIT_FAILURE

int main() {
    double input1, input2, input3;
    double sanctioned_amount;

    printf("Enter two numbers (e.g., '10000 20000'):\n");

    // Read the first two numbers
    if (scanf("%lf, %lf", &input1, &input2) != 2) {
        fprintf(stderr, "Error: Invalid input for the first two numbers.\n");
        while (getchar() != '\n'); // Clear buffer
        return EXIT_FAILURE;
    }

    // --- Unusual Condition Check ---
    // The original condition simplifies to:
    // (input2 == 0 && input1 < 50000) || (input1 == 0 && input2 < 50000)
    // This checks if one of the first two inputs is zero and the other is less than 50000.
    // This logic might be intended to represent a specific scenario or is a simplified example.
    if ((input1 == 0.0 && input2 < 50000.0) || (input2 == 0.0 && input1 < 50000.0)) {

        printf("Enter a third number:\n");
        // Read the third number
        if (scanf("%lf", &input3) != 1) {
            fprintf(stderr, "Error: Invalid input for the third number.\n");
            while (getchar() != '\n'); // Clear buffer
            return EXIT_FAILURE;
        }

        // Check if the third number is less than 50000
        if (input3 < 50000.0) {
            // Calculate the sanctioned loan amount based on a custom rule.
            // If the sum of all three inputs exceeds 50000, the sanctioned amount
            // is capped at 50000 minus the sum of the first two inputs.
            // Otherwise, the sanctioned amount is the third input itself.
            if ((input1 + input2 + input3) > 50000.0) {
                sanctioned_amount = 50000.0 - input1 - input2;
                // Ensure sanctioned amount is not negative if inputs were large
                if (sanctioned_amount < 0) sanctioned_amount = 0;
            } else {
                sanctioned_amount = input3;
            }
            printf("SANCTIONED LOAN %.2lf\n", sanctioned_amount);
        } else {
            // If the third number is 50000 or greater, no loan is sanctioned.
            printf("NO LOAN\n");
        }
    } else {
        // If the initial condition (one of the first two inputs is zero and the other < 50000) is not met, no loan is sanctioned.
        printf("NO LOAN\n");
    }

    return 0;
}
