/*
 * Purpose: Calculates the square root of a non-negative number, repeatedly prompting for input.
 * Topic: Input/Output, Math Functions, Loops
 */

#include <stdio.h>
#include <math.h>

int main() {
    double number;
    double result;

    while (1) { // Infinite loop, broken by explicit return
        printf("Enter a non-negative number (or Ctrl+D to exit): ");
        if (scanf("%lf", &number) != 1) {
            // Handle end-of-file or invalid input
            printf("\nExiting program.\n");
            break;
        }

        if (number < 0) {
            printf("Error: Cannot calculate square root of a negative number. Please try again.\n\n");
            continue; // Ask for input again
        }

        result = sqrt(number);
        printf("The square root of %.2lf is %.4lf\n\n", number, result);
    }

    return 0;
}
