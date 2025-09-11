/*
 * Purpose: Demonstrates passing multiple pointers to a function to modify multiple variables in the caller's scope, with corrected signature and type issues.
 * Topic: Pointers, Functions, Pass-by-Reference, Multiple Variable Modification, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>

// Function to perform arithmetic operations on two doubles.
// Takes two doubles (values) and four double pointers (for results).
// Modifies the values pointed to by p, q, r, s.
// Includes error handling for division by zero.
void perform_arithmetic_operations_via_pointers(double num1, double num2,
                                                double *sum_ptr,
                                                double *diff_ptr,
                                                double *prod_ptr,
                                                double *div_ptr) {
    // Check for NULL pointers to ensure safety
    if (sum_ptr == NULL || diff_ptr == NULL || prod_ptr == NULL || div_ptr == NULL) {
        fprintf(stderr, "Error: NULL pointer passed to perform_arithmetic_operations_via_pointers.\n");
        return; // Exit if pointers are invalid
    }

    // Perform calculations and store results via pointers
    *sum_ptr = num1 + num2;
    *diff_ptr = num1 - num2;
    *prod_ptr = num1 * num2;

    // Check for division by zero
    if (num2 == 0.0) {
        fprintf(stderr, "Error: Division by zero attempted.\n");
        *div_ptr = 0.0; // Assign a default value or error indicator
    } else {
        *div_ptr = num1 / num2;
    }
}

int main(void) {
    double value1, value2;
    double result_sum, result_diff, result_prod, result_div;

    // Get two double values from the user
    printf("Enter two double values separated by a comma (e.g., 10.5, 5.2): ");
    if (scanf("%lf, %lf", &value1, &value2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two double values separated by a comma.\n");
        return 0;
    }
    // Consume any remaining characters on the line after the second double, including the newline
    while (getchar() != '\n');

    // Call the function, passing the addresses of the result variables.
    // This allows the function to modify these variables directly.
    perform_arithmetic_operations_via_pointers(value1, value2,
                                             &result_sum,
                                             &result_diff,
                                             &result_prod,
                                             &result_div);

    // Print the results
    printf("Sum: %.2lf\n", result_sum);
    printf("Difference: %.2lf\n", result_diff);
    printf("Product: %.2lf\n", result_prod);
    // Check if division was successful before printing
    if (value2 != 0.0) { // Check original input value for division by zero
        printf("Division: %.2lf\n", result_div);
    } else {
        printf("Division: Error (division by zero).\n");
    }

    return 0;
}
