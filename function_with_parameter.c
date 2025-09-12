/*
 * Purpose: Demonstrates passing a value to a function and returning a result.
 * Topic: Functions, Parameters, Return Values, Basic Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function to double a given number
double double_value(double input_val) {
    return 2.0 * input_val; // Return doubled value
}

int main(void) {
    double input_value;
    double doubled_value;

    printf("Enter a double value: "); // Prompt user
    if (scanf("%lf", &input_value) != 1) { // Validate input
        fprintf(stderr, "Error: Invalid input. Please enter a valid double.\n");
        return 0;
    }

    doubled_value = double_value(input_value); // Call function

    printf("Original value: %lf\n", input_value); // Display results
    printf("Doubled value:  %lf\n", doubled_value);

    return 0;
}
