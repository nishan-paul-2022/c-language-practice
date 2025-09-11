/*
 * Purpose: Calculates the integer square root of a non-negative integer using Newton's method.
 * Topic: Algorithms, Newton's Method, Integer Math
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    int number;
    printf("Enter a non-negative integer to find its square root (0 to exit): ");
    while (scanf("%d", &number) == 1 && number >= 0) {
        if (number == 0) {
            printf("Exiting.\n");
            break;
        }
        if (number == 1) {
            printf("Integer square root of %d is %d\n", number, 1);
            printf("Enter a non-negative integer to find its square root (0 to exit): ");
            continue;
        }

        // Initial guess for Newton's method
        // ceil(number / 2.0) ensures reasonable starting point
        // especially for smaller numbers, avoids division by zero if number is 0
        // For number = 1, ceil(1/2.0) = 1
        // For number = 4, ceil(4/2.0) = 2
        // For number = 5, ceil(5/2.0) = 3
        int current_guess = (int)ceil(number / 2.0);
        int previous_guess;

        // Newton's method iteration
        // Loop continues until guess converges (current_guess is stable or decreases)
        // or until current_guess * current_guess <= number
        // and (current_guess + 1) * (current_guess + 1) > number
        while (1) {
            previous_guess = current_guess;
            // Core of Newton's method for square root: x_new = (x_old + N/x_old) / 2
            current_guess = (int)floor((previous_guess + (double)number / previous_guess) / 2.0);

            // If guess has converged or gone past actual root, break
            // Condition `current_guess >= previous_guess` indicates convergence
            // or oscillation around integer square root
            if (current_guess >= previous_guess) {
                break;
            }
        }
        printf("Integer square root of %d is %d\n", number, previous_guess);
        printf("Enter a non-negative integer to find its square root (0 to exit): ");
    }
    return 0;
}
