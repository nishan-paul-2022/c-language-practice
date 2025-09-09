/*
 * Purpose: Reads a sequence of floating-point numbers from the user and calculates their sum.
 *          The input process stops when the user enters 0.
 * Topic: Floating-Point Input, Summation, Sentinel Value, Loops
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    double input_number;     // Variable to store each floating-point number entered by the user.
    double current_sum = 0.0; // Variable to accumulate the sum of the numbers.

    printf("Enter floating-point numbers (enter 0 to stop):\n");

    // Loop indefinitely until a 0 is entered.
    while (1) {
        // Read a floating-point number from standard input.
        if (scanf("%lf", &input_number) != 1) {
            // Handle cases where input is not a valid double.
            printf("Invalid input. Please enter a valid floating-point number or 0 to exit.\n");
            // Clear the input buffer to prevent infinite loops on bad input.
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue; // Skip to the next iteration.
        }

        // Check if the entered number is the sentinel value (0).
        if (input_number == 0.0) {
            break; // Exit the loop if 0 is entered.
        }

        // Add the valid input number to the current sum.
        current_sum += input_number;
    }

    // Print the final calculated sum.
    // Using %.2lf to display the sum with two decimal places for better readability.
    printf("\nThe total sum of the entered numbers is: %.2lf\n", current_sum);

    return 0;
}
