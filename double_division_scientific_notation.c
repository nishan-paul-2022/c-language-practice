/*
 * Purpose: Reads two double-precision floating-point numbers separated by a slash and prints their quotient in scientific notation.
 * Topic: Input/Output, Floating-Point Numbers, Basic Arithmetic
 */

#include <stdio.h>

int get_numbers(double *numerator, double *denominator) {
    printf("Enter two numbers separated by a slash (e.g., 10.0/3.0): ");
    if (scanf("%lf/%lf", numerator, denominator) != 2) {
        printf("Invalid input format. Please enter two numbers separated by a slash.\n");
        return -1;
    }
    return 0;
}

int check_division_by_zero(double denominator) {
    if (denominator == 0.0) {
        printf("Error: Division by zero is not allowed.\n");
        return -1;
    }
    return 0;
}

void display_result(double numerator, double denominator) {
    printf("Result in scientific notation: %e\n", numerator / denominator);
}

int main(void) {
    double numerator, denominator;
    
    if (get_numbers(&numerator, &denominator) == -1) {
        return 0;
    }
    
    if (check_division_by_zero(denominator) == -1) {
        return 0;
    }
    
    display_result(numerator, denominator);
    
    return 0;
}
