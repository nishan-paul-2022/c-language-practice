/*
 * Purpose: Demonstrates the use of the standard C library's pow() function for exponentiation.
 * Topic: Mathematical Functions, pow(), Loops
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    while (1) {
        int base, exponent;

        printf("Enter the base and exponent (or Ctrl+D to exit): ");

        if (scanf("%d %d", &base, &exponent) == -1) {
            printf("\nInvalid input.\n");
            return 0;
        }

        int result = pow(base, exponent);
        
        printf("Result: %.d\n\n", result);
    }

    return 0;
}
