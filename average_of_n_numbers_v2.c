/*
 * Purpose: Reads a sequence of double values until a non-numeric value is entered,
 *          then calculates and prints the average of the entered numbers.
 * Topic: Loops, Input Handling, Floating-Point Numbers, Average Calculation
*/

#include <stdio.h>

int main() {
    double current_value; // Current input value
    double sum_of_values = 0.0; // Sum of valid numbers
    int count = 0; // Count of valid entries

    printf("Enter a sequence of double values.\n");
    printf("Enter a non-numeric value to finish and see the average.\n");
    while (1) {
        printf("Enter value: "); // Prompt for input
        if (scanf("%lf", &current_value) != 1) {
            // Non-numeric input detected, terminate input loop
            while (getchar() != '\n'); // Clear input buffer
            break;
        } // Update count and sum
        count++;
        sum_of_values += current_value;
    }

    if (count > 0) {
        double average = sum_of_values / count;
        printf("The average of the entered numbers is: %.2f\n", average); // Print average with 2 decimal places
    } else {
        printf("No valid numbers were entered.\n");
    }

    return 0; // Indicate successful execution
}
