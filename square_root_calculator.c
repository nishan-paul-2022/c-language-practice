/*
 * Purpose: Calculates the square root of a non-negative number, repeatedly prompting for input.
 * Topic: Input/Output, Math Functions, Loops
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    double number;

    while (1) {
        printf("Enter a non-negative number (or Ctrl+D to exit): ");

        if (scanf("%lf", &number) != 1) {
            printf("\nExiting program.\n");
            break;
        }

        if (number < 0) {
            printf("Cannot calculate square root of a negative number.\n\n");
            continue;
        }

        double sqrt_result = sqrt(number);
        printf("Square root of %.2lf is %.4lf\n\n", number, sqrt_result);
    }

    return 0;
}
