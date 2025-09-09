/*
 * Purpose: Finds and prints all prime numbers within a specified range.
 * Topic: Prime Numbers, Loops, Conditional Statements, Input Parsing
 */

#include <stdio.h>
#include <math.h>

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
    int start_range, end_range;

    printf("Enter the start and end of the range (e.g., 1 to 100): ");
    // Read the range from user input in "start to end" format and validate
    // scanf returns the number of successfully matched and assigned input items.
    // We expect 2 integers to be read.
    if (scanf("%d to %d", &start_range, &end_range) != 2) {
        printf("Error: Invalid input format. Please use 'start to end' format (e.g., 1 to 100).\n");
        return 0;
    }

    printf("\nPrime numbers between %d and %d are:\n", start_range, end_range);

    // Iterate through the range and print prime numbers
    for (int i = start_range; i <= end_range; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n"); // Print a newline at the end for better formatting

    return 0;
}
