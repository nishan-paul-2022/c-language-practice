/*
 * Purpose: Calculates a sum by repeatedly adding a value and then dividing it by a divisor until it becomes zero.
 * Topic: Loops, Integer Division, Accumulation, Input Validation
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int current_value, divisor;
    int sum = 0;
    int loop_counter = 0; // To track loop iterations, though not strictly necessary for the calculation itself

    printf("Enter two integers (value divisor): ");

    // Read the initial value and the divisor
    if (scanf("%d %d", &current_value, &divisor) != 2) {
        fprintf(stderr, "Error: Invalid input. Please enter two integers separated by a space.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return EXIT_FAILURE;
    }

    // Check for division by zero to prevent runtime errors
    if (divisor == 0) {
        fprintf(stderr, "Error: Division by zero is not allowed.\n");
        return EXIT_FAILURE;
    }

    // Loop as long as the current_value is not zero
    // The loop terminates when current_value becomes 0 after integer division.
    while (current_value != 0) {
        sum += current_value; // Add the current value to the sum
        current_value /= divisor; // Update current_value by dividing it by the divisor
        loop_counter++;
    }

    // Print the final calculated sum
    printf("The calculated sum is: %d\n", sum);

    return 0;
}
