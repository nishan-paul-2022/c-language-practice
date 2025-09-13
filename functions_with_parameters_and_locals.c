/*
 * Purpose: Demonstrates functions operating on parameters and local variables, avoiding global variables.
 * Topic: Functions, Parameters, Local Variables, Scope, Global Variables (avoidance)
 */

#include <stdio.h>

int add_numbers(int num1, int num2) {
    return num1 + num2;
}

int calculate_product(int multiplier, int addend) {
    const int CONSTANT_MULTIPLIER = 10;
    return multiplier * CONSTANT_MULTIPLIER + addend;
}

void display_results(int number1, int number2, int sum_result, int product_result) {
    printf("Sum of %d and %d is: %d\n", number1, number2, sum_result);
    printf("Result of calculation is: %d\n", product_result);
}

int main(void) {
    int number1 = 5;
    int number2 = 12;

    int sum_result = add_numbers(number1, number2);
    int product_result = calculate_product(number2, sum_result);

    display_results(number1, number2, sum_result, product_result);

    return 0;
}
