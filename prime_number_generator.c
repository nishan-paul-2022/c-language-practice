// Purpose: Generates and prints prime numbers within a specified range.
// Topic: Prime Numbers, Loops, Conditional Statements, Functions

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
    int start_num, end_num;

    printf("Enter the start and end of the range (e.g., 1 100): ");
    // Read the range from user input
    if (scanf("%d %d", &start_num, &end_num) != 2) {
        printf("Error: Invalid input. Please enter two integers.\n");
        return 1; // Indicate an error
    }

    printf("\nPrime numbers between %d and %d are:\n", start_num, end_num);

    // Iterate through the range and print prime numbers
    for (int i = start_num; i <= end_num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n"); // Print a newline at the end for better formatting

    return 0; // Indicate successful execution
}
