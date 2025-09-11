/*
 * Purpose: Calculates the factorial of a non-negative integer and counts its trailing zeros.
 * Topic: Factorial, Trailing Zeros, Loops, Integer Arithmetic
 */

#include <stdio.h>

// Function to calculate factorial. Using unsigned long long to handle larger values.
unsigned long long calculate_factorial(int num) {
    unsigned long long factorial = 1;
    // Factorial is not defined for negative numbers
    // For 0!, the result is 1
    if (num < 0) {
        return 0; // Indicate an error or undefined state
    }
    if (num == 0) {
        return 1;
    }
    for (int i = 1; i <= num; i++) {
        // Check for potential overflow before multiplication
        if (__builtin_mul_overflow(factorial, i, &factorial)) {
            printf("Warning: Factorial calculation may have overflowed for %d!\n", num);
            return 0; // Indicate overflow
        }
    }
    return factorial;
}

// Function to count trailing zeros in a number
int count_trailing_zeros(unsigned long long num) {
    int count = 0;
    // Trailing zeros are formed by factors of 10

    // If the number is 0, it has no trailing zeros in this context.
    if (num == 0) {
        return 0;
    }

    // Count trailing zeros by repeatedly dividing by 10
    while (num > 0 && num % 10 == 0) {
        count++;
        num /= 10;
    }
    return count;
}

int main(void) {
    int number;
    unsigned long long factorial_result;
    int trailing_zeros_count;

    printf("Enter a non-negative integer to calculate its factorial and count trailing zeros: ");
    // Read the number from user input and validate
    if (scanf("%d", &number) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Calculate factorial
    factorial_result = calculate_factorial(number);

    if (factorial_result == 0 && number != 0) { // Check for error/overflow from calculate_factorial
        printf("Could not calculate factorial or it resulted in zero (possibly due to overflow or negative input).\n");
        return 0;
    }

    // Print the factorial result
    printf("Factorial of %d is: %llu\n", number, factorial_result);

    // Count trailing zeros in the factorial result
    trailing_zeros_count = count_trailing_zeros(factorial_result);

    // Print the count of trailing zeros
    printf("Number of trailing zeros in %d! is: %d\n", number, trailing_zeros_count);

    return 0;
}
