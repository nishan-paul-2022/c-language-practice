/*
 * Purpose: Reads two numbers, divides them, and prints the integer and fractional parts of the result.
 * Topic: Floating-Point Arithmetic, Input/Output, Math Functions
 */

#include <stdio.h>
#include <math.h>

void get_numbers(double *numerator, double *denominator) {
    printf("Enter numerator and denominator (e.g., 15.75, 4): ");
    scanf("%lf, %lf", numerator, denominator);
}

void display_parts(double numerator, double denominator) {
    double quotient = numerator / denominator;
    double integer_part;
    double fractional_part = modf(quotient, &integer_part);

    printf("\n--- Division Result ---\n");
    printf("Integer Part: %.0f\n", integer_part);
    printf("Fractional Part: %.2lf\n", fractional_part);
}

int main(void) {
    double numerator, denominator;

    get_numbers(&numerator, &denominator);
    display_parts(numerator, denominator);

    return 0;
}