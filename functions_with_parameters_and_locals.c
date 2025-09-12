/*
 * Purpose: Demonstrates functions operating on parameters and local variables, avoiding global variables.
 * Topic: Functions, Parameters, Local Variables, Scope, Global Variables (avoidance)
 */

#include <stdio.h>
#include <stdlib.h>

// Adds two integers and returns the sum.
int add_numbers(int num1, int num2) {
    return num1 + num2;
}

// Calculates (multiplier * 10) + addend.
int calculate_product(int multiplier, int addend) {
    const int CONSTANT_MULTIPLIER = 10;
    int result = multiplier * CONSTANT_MULTIPLIER + addend;
    return result;
}

int main(void) {
    int number1 = 5;
    int number2 = 12;

    // Calculate the sum of number1 and number2.
    int sum_result = add_numbers(number1, number2);

    // Calculate the product using number2 and the sum.
    int product_result = calculate_product(number2, sum_result);

    printf("Sum of %d and %d is: %d\n", number1, number2, sum_result);
    printf("Result of calculation is: %d\n", product_result);

    return 0;
}
