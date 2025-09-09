/*
 * Purpose: Finds and prints all positive divisors of a given integer.
 * Topic: Loops, Conditional Statements, Mathematical Functions (sqrt)
 */

#include <stdio.h> // Required for printf and scanf
#include <math.h>  // Required for sqrt()

int main() {
    int number; // The integer number for which to find divisors
    int i;

    // Prompt user for input
    printf("Enter a positive integer to find its divisors: ");
    scanf("%d", &number);

    // Handle edge cases
    if (number <= 0) {
        printf("Divisors are typically defined for positive integers.\n");
        return 0;
    }

    printf("Divisors of %d are: ", number);

    // Iterate from 1 up to the square root of the number
    for (i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            // If 'i' is a divisor, print 'i'
            printf("%d", i);

            // If 'i' and 'number/i' are different, then 'number/i' is also a divisor
            // This avoids printing the same divisor twice for perfect squares (e.g., for 9, prints 3 only once)
            if (i * i != number) {
                printf(" %d", number / i);
            }
            printf(" "); // Add a space after each divisor or pair
        }
    }
    printf("\n");

    return 0;
}
