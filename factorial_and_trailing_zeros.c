/*
 * Purpose: Calculates the factorial of a non-negative integer and counts its trailing zeros.
 * Topic: Factorial, Trailing Zeros, Loops, Integer Arithmetic
 */

#include <stdio.h>


unsigned long long calculate_factorial(int num) {
    unsigned long long factorial = 1;
    if (num < 0) {
        return 0; 
    }
    if (num == 0) {
        return 1; 
    }
    for (int i = 1; i <= num; i++) {
        
        if (__builtin_mul_overflow(factorial, i, &factorial)) {
            printf("Factorial calculation may have overflowed for %d!\n", num);
            return 0; 
        }
    }
    return factorial;
}


int count_trailing_zeros(unsigned long long num) {
    int count = 0;
    if (num == 0) {
        return 0;
    }

    
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

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    factorial_result = calculate_factorial(number);

    if (factorial_result == 0 && number) { 
        printf("Could not calculate factorial (possibly due to overflow or negative input).\n");
        return 0;
    }

    printf("Factorial of %d is: %llu\n", number, factorial_result);

    trailing_zeros_count = count_trailing_zeros(factorial_result);

    printf("Number of trailing zeros in %d! is: %d\n", number, trailing_zeros_count);

    return 0;
}
