// Purpose: Checks if a given integer is a prime number.
// Topic: Prime Numbers, Loops, Conditional Statements

#include <stdio.h>
#include <math.h> // For sqrt function

// Function to check if a number is prime
int is_prime(int num) {
    // Numbers less than 2 are not prime
    if (num < 2) {
        return 0; // Not prime
    }
    // 2 is the only even prime number
    if (num == 2) {
        return 1; // Prime
    }
    // Even numbers greater than 2 are not prime
    if (num % 2 == 0) {
        return 0; // Not prime
    }
    // Check for divisibility from 3 up to the square root of the number
    // We only need to check odd divisors
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    // If no divisors were found, the number is prime
    return 1; // Prime
}

int main() {
    int number;

    printf("Enter an integer: ");
    // Read the number from user input and validate
    if (scanf("%d", &number) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Check if the number is prime and print the result
    if (is_prime(number)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    return 0;
}
