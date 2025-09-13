/*
 * Purpose: Checks if a given positive integer is a prime number.
 * Topic: Loops, Conditional Statements, Mathematical Functions (sqrt), Primality Test
 */

#include <stdio.h>

int is_prime(int number) {
    if (number <= 1) {
        return 0;
    }
    if (number == 2) {
        return 1;
    }
    if (number % 2 == 0) {
        return 0;
    }

    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    printf("Enter a positive integer to check if it's prime: ");
    int number;
    scanf("%d", &number);

    printf("%d is %sprime.\n", number, is_prime(number) ? "" : "not ");

    return 0;
}
