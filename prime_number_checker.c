/*
 * Purpose: Checks if a given positive integer is a prime number.
 * Topic: Loops, Conditional Statements, Mathematical Functions (sqrt), Primality Test
 */

#include <stdio.h>
#include <math.h>

int main() {
    int number; // The integer number to check for primality
    int i;
    int is_prime = 1; // Flag: 1 means prime, 0 means not prime

    // Prompt user for input
    printf("Enter a positive integer to check if it's prime: ");
    scanf("%d", &number);

    // Handle edge cases for primality:
    // Numbers less than or equal to 1 are not prime.
    if (number <= 1) {
        is_prime = 0; // Not prime
    }
    // 2 is the only even prime number
    else if (number == 2) {
        is_prime = 1; // Prime
    }
    // Even numbers greater than 2 are not prime
    else if (number % 2 == 0) {
        is_prime = 0; // Not prime
    }
    // For odd numbers, check divisibility from 3 up to the square root of the number,
    // incrementing by 2 (to check only odd divisors)
    else {
        // Loop from 3 up to sqrt(number), checking only odd divisors
        for (i = 3; i * i <= number; i += 2) {
            if (number % i == 0) {
                is_prime = 0; // Found a divisor, so it's not prime
                break;        // Exit the loop
            }
        }
    }

    // Print the result based on the is_prime flag
    if (is_prime == 1) {
        printf("%d is a Prime number.\n", number);
    } else {
        printf("%d is Not a Prime number.\n", number);
    }

    return 0;
}
