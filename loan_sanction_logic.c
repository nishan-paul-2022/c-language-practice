/*
 * Purpose: Implements specific logic for loan sanctioning based on input values.
 * Topic: Input Processing, Conditional Logic, Financial Calculations (simplified/custom)
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double input1, input2, input3;
    double sanctioned_amount;

    printf("Enter two numbers (e.g., '10000 20000'):\n");

    // Read first two numbers
    if (scanf("%lf, %lf", &input1, &input2) != 2) {
        fprintf(stderr, "Error: Invalid input for the first two numbers.\n");
        while (getchar() != '\n'); // Clear buffer
        return 0;
    }

    // --- Unusual Condition Check ---
    // Original condition simplifies to:
    // (input2 == 0 && input1 < 50000) || (input1 == 0 && input2 < 50000)
    // Checks if one of first two inputs is zero and other is less than 50000
    // Logic might represent specific scenario or simplified example
    if ((input1 == 0.0 && input2 < 50000.0) || (input2 == 0.0 && input1 < 50000.0)) {

        printf("Enter a third number:\n");
        // Read third number
        if (scanf("%lf", &input3) != 1) {
            fprintf(stderr, "Error: Invalid input for the third number.\n");
            while (getchar() != '\n'); // Clear buffer
            return 0;
        }

        // Check if third number is less than 50000
        if (input3 < 50000.0) {
            // Calculate sanctioned loan amount based on custom rule
            // If sum of all three inputs exceeds 50000, sanctioned amount
            // is capped at 50000 minus sum of first two inputs
            // Otherwise, sanctioned amount is third input itself
            if ((input1 + input2 + input3) > 50000.0) {
                sanctioned_amount = 50000.0 - input1 - input2;
                // Ensure sanctioned amount is not negative if inputs were large
                if (sanctioned_amount < 0) sanctioned_amount = 0;
            } else {
                sanctioned_amount = input3;
            }
            printf("SANCTIONED LOAN %.2lf\n", sanctioned_amount);
        } else {
            // If third number is 50000 or greater, no loan is sanctioned
            printf("NO LOAN\n");
        }
    } else {
        // If initial condition (one of first two inputs is zero and other < 50000) is not met, no loan is sanctioned
        printf("NO LOAN\n");
    }

    return 0;
}
