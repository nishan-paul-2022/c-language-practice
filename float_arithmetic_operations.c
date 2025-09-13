/*
 * Purpose: Performs basic arithmetic operations (addition, subtraction, multiplication, division) on two floating-point numbers.
 * Topic: Input/Output, Floating-Point Numbers, Basic Arithmetic
 */

#include <stdio.h>

int get_input(float *num1, float *num2) {
    printf("Enter two floating-point numbers (e.g., 10.5 20.3): ");
    if (scanf("%f %f", num1, num2) != 2) {
        printf("Invalid input. Please enter two numbers.\n");
        return -1;
    }
    return 0;
}

void perform_operations(float num1, float num2) {
    printf("Results:\n");
    printf("Sum: %.2f\n", num1 + num2);
    printf("Difference: %.2f\n", num1 - num2);
    printf("Product: %.2f\n", num1 * num2);

    if (num2 != 0) {
        printf("Quotient: %.2f\n", num1 / num2);
    } else {
        printf("Quotient: Division by zero is not allowed.\n");
    }
}

int main(void) {
    float num1, num2;

    if (get_input(&num1, &num2) == 0) {
        perform_operations(num1, num2);
    }

    return 0;
}
