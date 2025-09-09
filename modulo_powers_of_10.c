#include <stdio.h>
#include <math.h> // For pow, though we'll use iterative multiplication for powers of 10

/*
 * Purpose: Reads an integer and prints the remainders when divided by increasing powers of 10,
 *          up to the largest power of 10 less than the input number.
 * Topic: Loops, Modulo Operator, Powers of 10, Input Validation
 */
int main() {
    int input_value;
    int remainder;
    long long current_power_of_10 = 10; // Start with 10^1

    // Prompt user for input
    printf("Enter an integer value: ");
    // Use " %d" to consume any leading whitespace, including newlines
    if (scanf(" %d", &input_value) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Handle non-positive input gracefully
    if (input_value <= 0) {
        printf("Input value must be positive.\n");
        return 0;
    }

    // Loop to find powers of 10 less than input_value
    // and calculate the remainder.
    // The loop continues as long as the current power of 10 is less than or equal to input_value.
    // We want to find powers of 10 that are *less than* input_value for the modulo operation.
    // The original code's loop condition was `i < x`, so we'll stick to that logic.
    // However, the original code's loop structure was flawed.
    // Let's refine the logic: we want to find powers of 10 that are *less than* input_value.
    // For example, if input_value is 150, powers of 10 less than it are 10 and 100.
    // If input_value is 50, power of 10 less than it is 10.

    // The original loop was `for(i=10; i<x; i=i*10) ;`
    // This means `i` would become 10, 100, 1000, etc.
    // The modulo operation `x % i` would be performed *after* the loop.
    // This implies the loop was meant to find the *largest* power of 10 less than x.
    // Let's re-implement that logic correctly.

    // Find the largest power of 10 that is less than input_value
    long long power_of_10 = 10;
    while (power_of_10 < input_value) {
        // Calculate the remainder for the current power of 10
        remainder = input_value % power_of_10;
        printf("Remainder when divided by %lld: %d\n", power_of_10, remainder);

        // Move to the next power of 10
        // Check for potential overflow before multiplying
        if (__builtin_mul_overflow(power_of_10, 10, &power_of_10)) {
            // If overflow occurs, break the loop
            break;
        }
    }

    // Print the original input value as in the original code
    printf("Original value: %d\n", input_value);

    return 0;
}
