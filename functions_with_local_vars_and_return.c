// Purpose: Demonstrates functions performing arithmetic operations using parameters and returning results, avoiding global variables.
// Topic: Functions, Parameters, Return Values, Arithmetic Operations, Global Variables (avoidance), Structs

#include <stdio.h>
#include <stdlib.h> // For exit()

// Structure to hold multiple results from a function
typedef struct {
    double sum;
    double difference;
    double product;
    double division;
} CalculationResults;

// Function to perform arithmetic operations on two doubles.
// Takes two doubles as input.
// Returns a struct containing the sum, difference, product, and division.
// Includes error handling for division by zero.
CalculationResults perform_arithmetic_operations(double num1, double num2) {
    CalculationResults results;

    // Perform calculations
    results.sum = num1 + num2;
    results.difference = num1 - num2;
    results.product = num1 * num2;

    // Check for division by zero
    if (num2 == 0.0) {
        fprintf(stderr, "Error: Division by zero attempted.\n");
        results.division = 0.0; // Or some other indicator of error, like NaN if available
    } else {
        results.division = num1 / num2;
    }

    return results;
}

int main() {
    double value1, value2;
    CalculationResults calculation_results;

    // Get two double values from the user
    printf("Enter two double values separated by a comma (e.g., 10.5, 5.2): ");
    if (scanf("%lf, %lf", &value1, &value2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two double values separated by a comma.\n");
        return 1; // Indicate an error
    }
    // Consume any remaining characters on the line after the second double, including the newline
    while (getchar() != '\n');

    // Call the function to perform calculations
    calculation_results = perform_arithmetic_operations(value1, value2);

    // Print the results
    printf("Sum: %.2lf\n", calculation_results.sum);
    printf("Difference: %.2lf\n", calculation_results.difference);
    printf("Product: %.2lf\n", calculation_results.product);
    // Check if division was successful before printing
    if (value2 != 0.0) { // Check original input value for division by zero
        printf("Division: %.2lf\n", calculation_results.division);
    } else {
        printf("Division: Error (division by zero).\n");
    }

    return 0;
}
