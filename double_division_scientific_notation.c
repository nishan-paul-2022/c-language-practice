/*
 * Purpose: Reads two double-precision floating-point numbers separated by a slash and prints their quotient in scientific notation.
 * Topic: Input/Output, Floating-Point Numbers, Basic Arithmetic
 */

#include <stdio.h>

int main(void) {
    double numerator;
    double denominator;

    printf("Enter two numbers separated by a slash (e.g., 10.0/3.0): ");
    if (scanf("%lf/%lf", &numerator, &denominator) != 2) {
        printf("Invalid input format. Please enter two numbers separated by a slash.\n");
        return 0;
    }

    if (denominator == 0.0) {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }

    printf("Result in scientific notation: %e\n", numerator / denominator);

    return 0;
}
