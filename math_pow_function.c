/*
 * Purpose: Demonstrates the use of the standard C library's pow() function for exponentiation.
 * Topic: Mathematical Functions, pow(), Loops
 */

#include <stdio.h>
#include <math.h>

int read_base_and_exponent(double *base, double *exponent) {
    printf("Enter the base and exponent (or 0 for base to exit): ");
    if (scanf("%lf %lf", base, exponent) != 2) {
        printf("Invalid input. Please enter two numeric values.\n");
        while (getchar() != '\n');
        return -1;
    }
    return 0;
}

double calculate_power(double base, double exponent) {
    return pow(base, exponent);
}

void display_result(double result) {
    printf("Result: %.2lf\n\n", result);
}

int main(void) {
    double base, exponent, result;

    while (1) {
        if (read_base_and_exponent(&base, &exponent) == -1) {
            continue;
        }

        if (base == 0.0) {
            printf("Exiting program.\n");
            break;
        }

        result = calculate_power(base, exponent);
        display_result(result);
    }

    return 0;
}
