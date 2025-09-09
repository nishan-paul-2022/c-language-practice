// Purpose: Demonstrates functions operating on parameters and local variables, avoiding global variables.
// Topic: Functions, Parameters, Local Variables, Scope, Global Variables (avoidance)

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function to add two integers.
// Takes two integers as parameters and returns their sum.
int add_numbers(int num1, int num2) {
    int sum = num1 + num2; // Local variable for the sum
    return sum;
}

// Function to calculate (multiplier_val * CONSTANT_MULTIPLIER) + value_to_add.
// Takes the value to multiply and the value to add as parameters.
// Uses a constant for the multiplier.
int calculate_product(int multiplier_val, int value_to_add) {
    const int CONSTANT_MULTIPLIER = 10; // Represents the original global 'g'
    int result = multiplier_val * CONSTANT_MULTIPLIER + value_to_add;
    return result;
}

int main() {
    int number1 = 5;
    int number2 = 12;
    int sum_result;
    int product_result;

    // Call the add function
    // It takes number1 and number2, calculates their sum, and returns it.
    sum_result = add_numbers(number1, number2);

    // Call the calculate_product function.
    // The original mul(a) used 'a' and 'g' (global 10) and 'h' (global, result of add).
    // So, mul(12) was intended to be 12 * 10 + (result of add).
    // The result of add(5, 12) is 17.
    // Thus, mul(12) should be 12 * 10 + 17 = 120 + 17 = 137.
    // We call calculate_product with number2 (12) and sum_result (17).
    product_result = calculate_product(number2, sum_result);

    // Print the results
    printf("Sum of %d and %d is: %d\n", number1, number2, sum_result);
    printf("Result of calculation (value * 10 + sum) is: %d\n", product_result);

    return 0;
}
