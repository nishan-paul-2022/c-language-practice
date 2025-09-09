#include <stdio.h>
#include <math.h> // For pow() function

// Purpose: Calculates the sum of a geometric series (x^0 + x^1 + ... + x^n).
// Topic: Series Summation, Loops, Math Functions, Input/Output
int main(void) {
    double base_x; // The base of the power
    int exponent_n; // The maximum exponent
    double sum_of_powers = 0.0;
    double current_term;
    int i;
    int input_status;

    // Loop to allow multiple calculations until user decides to exit
    while (1) {
        printf("Enter the base (x) and the maximum exponent (n), separated by a comma (e.g., 2.5, 5): ");
        
        // Read input for base and exponent
        input_status = scanf("%lf, %d", &base_x, &exponent_n);

        // Validate input
        if (input_status != 2) {
            printf("Invalid input format. Please enter values like '2.5, 5'.\n");
            // Clear the input buffer to prevent infinite loop on bad input
            while (getchar() != '\n'); 
            continue; // Ask for input again
        }

        if (exponent_n < 0) {
            printf("Exponent n cannot be negative.\n");
            continue; // Ask for input again
        }

        sum_of_powers = 0.0; // Reset sum for each new calculation

        // Calculate the sum of the series x^0 + x^1 + ... + x^n
        for (i = 0; i <= exponent_n; i++) {
            current_term = pow(base_x, i);

            // Check if the current term is very small (close to zero)
            // This condition was used in the original code to potentially break early.
            // We'll keep it for educational purposes, but note that for a fixed 'n',
            // this check might not be strictly necessary unless dealing with very large 'n'
            // or very small 'x' where terms become negligible.
            if (fabs(current_term) < 0.0001 && i > 0) { // Use fabs for absolute value of double
                printf("Term %d (%.5lf) is very small, stopping summation early.\n", i, current_term);
                // The original code used goto here. We'll break instead.
                break; 
            }
            
            sum_of_powers += current_term;
        }

        // Print the result
        // The original code had two different print statements based on goto labels.
        // We'll consolidate to one clear output.
        printf("The sum of the series up to x^%d is: %.5lf\n", exponent_n, sum_of_powers);
        
        // The original code had a goto mlf; here, which was effectively a no-op after the first print.
        // We'll remove the need for goto by structuring the loop correctly.

        // Ask if the user wants to perform another calculation
        char another_calculation;
        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &another_calculation); // Note the space before %c to consume any leftover newline
        if (another_calculation != 'y' && another_calculation != 'Y') {
            break; // Exit the while loop if user doesn't want to continue
        }
        printf("\n"); // Add a newline for better readability between calculations
    }

    return 0;
}
