/*
 * Purpose: Calculates the integer square root of a non-negative integer using Newton's method.
 * Topic: Algorithms, Newton's Method, Integer Math
 */

#include <stdio.h>
#include <math.h>

int calculate_newton_sqrt(int number) {
    if (number == 0) {
        return 0;
    }
    if (number == 1) {
        return 1;
    }

    int current_guess = (int)ceil(number / 2.0);
    int previous_guess;

    while (1) {
        previous_guess = current_guess;
        current_guess = (int)floor((previous_guess + (double)number / previous_guess) / 2.0);

        if (current_guess >= previous_guess) {
            break;
        }
    }
    return previous_guess;
}

void process_newton_sqrt_requests() {
    int number;
    printf("Enter non-negative integer (0 to exit): ");
    
    while (scanf("%d", &number) == 1 && number >= 0) {
        if (number == 0) {
            printf("Exiting.\n");
            break;
        }

        int result = calculate_newton_sqrt(number);
        printf("Integer square root of %d is %d\n", number, result);
        printf("Enter non-negative integer (0 to exit): ");
    }
}

int main(void) {
    process_newton_sqrt_requests();
    return 0;
}
