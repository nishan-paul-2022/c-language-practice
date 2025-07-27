// Purpose: Reads a sequence of double values until a sentinel value (1000.0) is entered,
// then calculates and prints the average of the entered numbers.
// Topic: Loops, Input Handling, Floating-Point Numbers, Average Calculation

#include <stdio.h>

int main() {
    double current_value;       // The current number read from input
    double sum_of_values = 0.0; // Accumulator for the sum of valid numbers entered
    int count = 0;              // Counts the number of valid entries (excluding the sentinel)
    const double SENTINEL_VALUE = 1000.0; // The value to terminate input

    printf("Enter a sequence of double values.\n");
    printf("Enter %.3f to finish and see the average.\n", SENTINEL_VALUE);
    printf("----------------------------------------\n");

    // Loop to read values until the sentinel value is entered
    while (1) {
        printf("Enter value: ");
        // Read the input value and check if scanf was successful
        if (scanf("%lf", &current_value) != 1) {
            fprintf(stderr, "Error: Invalid input. Please enter a valid double value.\n");
            // Clear the input buffer to prevent infinite loops on bad input
            while (getchar() != '\n'); 
            continue; // Skip to the next iteration
        }

        // Check if the entered value is the sentinel value
        if (current_value == SENTINEL_VALUE) {
            break; // Exit the loop if the sentinel value is entered
        }

        // Increment the count of valid numbers entered
        count++;
        // Add the current value to the sum
        sum_of_values += current_value;
    }

    printf("\n----------------------------------------\n");

    // Calculate and print the average if at least one valid number was entered
    if (count > 0) {
        double average = sum_of_values / count;
        printf("The average of the entered numbers is: %.6f\n", average); // Print average with 6 decimal places
    } else {
        printf("No valid numbers were entered before the sentinel value.\n");
    }

    return 0; // Indicate successful execution
}
