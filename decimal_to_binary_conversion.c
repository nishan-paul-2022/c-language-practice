/*
 * Purpose: Converts a decimal integer to its binary representation.
 * Topic: Loops, Arithmetic Operations, Number Systems, Arrays
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal_number;
    int binary_digits[32]; // Array to store binary digits (sufficient for 32-bit int)
    int i;

    printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
    while (scanf("%d", &decimal_number) == 1) {
        if (decimal_number < 0) {
            printf("Please enter a non-negative integer.\n");
            printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
            continue;
        }

        if (decimal_number == 0) {
            printf("Binary: 0\n");
            printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
            continue;
        }

        i = 0;
        while (decimal_number > 0) {
            binary_digits[i] = decimal_number % 2;
            decimal_number = decimal_number / 2;
            i++;
        }

        printf("Binary: ");
        // Print binary digits in reverse order
        for (int j = i - 1; j >= 0; j--) {
            printf("%d", binary_digits[j]);
        }
        printf("\n\n");

        printf("Enter a non-negative decimal integer (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return EXIT_SUCCESS;
}