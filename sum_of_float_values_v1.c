/*
 * Purpose: Continuously reads floating-point numbers and calculates their sum. Input ends when a non-numeric character is entered.
 * Topic: Floating-Point Input, Summation, Input Validation, Loops
 */

#include <stdio.h>

double compute_sum(void) {
    double input_number, sum = 0.0;

    printf("Enter floating-point numbers (non-numeric input to stop):\n");

    while (scanf("%lf", &input_number) != -1) {
        sum += input_number;
    }

    return sum;
}

int main(void) {
    double total = compute_sum();
    printf("\nThe total sum of the entered numbers is: %.2lf\n", total);
    return 0;
}
