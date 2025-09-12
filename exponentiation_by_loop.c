/*
 * Purpose: Calculates 'base' raised to the power of 'exponent' (base^exponent) using a loop.
 *          Handles positive, zero, and negative integer exponents.
 * Topic: Exponentiation, Loops, Floating-Point Arithmetic
 */

#include <stdio.h>
#include <math.h>

int get_base_and_exponent(double *base, int *exponent) {
    printf("Enter the base (a double) and the exponent (an integer), separated by a comma (e.g., 2.5, 3): ");
    
    if (scanf("%lf, %d", base, exponent) != 2) {
        printf("Invalid input format. Please enter in the format: base, exponent\n");
        return -1;
    }

    return 0;
}

double calculate_power(double base, int exponent) {
    double result = 1.0;
    
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else {
        if (base == 0.0) {
            printf("Error: Division by zero is not allowed (0 raised to a negative power).\n");
            return 0.0;
        }
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        result = 1.0 / result;
    }
    
    return result;
}

void display_result(double base, int exponent, double result) {
    if (result || (base == 0.0 && exponent >= 0)) {
        printf("%.2f ^ %d = %f\n", base, exponent, result);
    }
}

int main(void) {
    double base;
    int exponent;
    
    if (get_base_and_exponent(&base, &exponent) == -1) {
        return 0;
    }
    
    double result = calculate_power(base, exponent);
    display_result(base, exponent, result);
    
    return 0;
}
