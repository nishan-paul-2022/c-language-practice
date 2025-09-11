/*
 * Purpose: Demonstrates functions using a global variable, performing calculations, and includes error handling for division by zero.
 * Topic: Global Variables, Functions, Arithmetic Operations, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>

// Global variable to be used by functions.
// It's generally better to pass such values as parameters, but we'll keep it global
// to match the original code's structure, adding comments about best practices.
int global_multiplier_divisor;

// Function to calculate the product of the sum of two integers and a global multiplier.
// Takes two integers as input.
int calculate_product_with_global(int num1, int num2) {
    // Uses the global variable 'global_multiplier_divisor'
    int sum = num1 + num2;
    int product = sum * global_multiplier_divisor;
    return product;
}

// Function to calculate the division of the sum of two integers by a global divisor.
// Takes two integers as input.
// Includes error handling for division by zero.
int calculate_division_with_global(int num1, int num2) {
    // Uses the global variable 'global_multiplier_divisor' as a divisor.
    int sum = num1 + num2;
    int result;

    // Check for division by zero before performing the operation.
    if (global_multiplier_divisor == 0) {
        fprintf(stderr, "Error: Division by zero attempted in calculate_division_with_global.\n");
        // Return a specific error value or handle as appropriate.
        // For this example, we'll return a sentinel value like -1.
        return -1; // Indicate division by zero error
    }

    result = sum / global_multiplier_divisor;
    return result;
}

int main(void) {
    int number1, number2;
    int product_result;
    int division_result;

    // Prompt user to enter the global multiplier/divisor value
    printf("Enter a global integer value to be used as a multiplier and divisor: ");
    // Read the global multiplier/divisor value and validate input
    if (scanf("%d", &global_multiplier_divisor) != 1) {
        fprintf(stderr, "Error: Invalid input for the global multiplier/divisor.\n");
        return 0;
    }
    // Consume any remaining characters on the line after the integer, including the newline
    while (getchar() != '\n');

    // Prompt user to enter two numbers
    printf("Enter two integers separated by a comma (e.g., 5, 12): ");
    // Read two integers separated by a comma and validate input
    if (scanf("%d, %d", &number1, &number2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two integers separated by a comma.\n");
        return 0;
    }
    // Consume any remaining characters on the line after the second integer, including the newline
    while (getchar() != '\n');

    // Call the functions to perform calculations
    product_result = calculate_product_with_global(number1, number2);
    division_result = calculate_division_with_global(number1, number2);

    // Display the product result
    printf("Product result: %d\n", product_result);
    // Check if division resulted in an error before printing
    if (division_result != -1) { // Assuming -1 is the error sentinel
        // Display the division result
        printf("Division result: %d\n", division_result);
    } else {
        printf("Division result: Error occurred (division by zero).\n");
    }

    return 0;
}
