/*
 * Purpose: Reads floating-point numbers and calculates their sum. Input ends when a non-numeric character is entered.
 * Topic: Floating-Point Input, Summation, Input Validation, Loops
 */

#include <stdio.h>

double compute_sum() {
    double input_number, sum = 0.0;

    printf("Enter floating-point numbers (Ctrl+D to exit):\n");

    while (scanf("%lf", &input_number) != -1) {
        sum += input_number;
    }

    return sum;
}

int main(void) {
    double total = compute_sum();

    printf("\nSum of entered numbers: %.2lf\n", total);

    return 0;
}
