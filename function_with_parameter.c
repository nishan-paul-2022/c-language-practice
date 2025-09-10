/*
 * Purpose: Demonstrates passing a value to a function and returning a result.
 * Topic: Functions, Parameters, Return Values, Basic Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function to double a given number.
// It takes a double as input and returns the doubled value.
double double_value(double input_val) {
    // No side effects on global variables; operates solely on its parameter.
    return 2.0 * input_val;
}

int main() {
    double input_value;
    double doubled_value;

    // Prompt user to enter a double value
    printf("Enter a double value: ");
    // Read a double value and validate input
    if (scanf("%lf", &input_value) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter a valid double.\n");
        return 0;
    }

    // Call the function to double the input value
    doubled_value = double_value(input_value);

    // Display the original input value and the result
    printf("Original value: %lf\n", input_value);
    printf("Doubled value:  %lf\n", doubled_value);

    return 0;
}
