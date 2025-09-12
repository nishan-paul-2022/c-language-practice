/*
 * Purpose: Reads two numbers, divides them, and prints the integer and fractional parts of the result.
 * Topic: Floating-Point Arithmetic, Input/Output, Math Functions
 */

#include <stdio.h>
#include <math.h>

// Function to get user input for two double-precision numbers
void get_numbers(double *numerator, double *denominator) {
    printf("Enter numerator and denominator (e.g., 15.75, 4): ");
    scanf("%lf, %lf", numerator, denominator);
}

// Function to calculate and display the integer and fractional parts
void display_parts(double numerator, double denominator) {
    if (denominator == 0.0) {
        fprintf(stderr, "Error: Cannot divide by zero.\n");
        return;
    }

    double quotient = numerator / denominator;
    double fractional_part, integer_part;

    // Use modf to separate the integer and fractional components
    fractional_part = modf(quotient, &integer_part);

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