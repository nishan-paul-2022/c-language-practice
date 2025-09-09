// Purpose: Determines if a given positive integer is a prime number.
// Topic: Number Theory, Loops, Conditional Logic, Math Functions (sqrt)

#include <stdio.h>
#include <math.h> // For sqrt function

int main() {
    long long int num_test_cases; // Number of test cases
    long long int i;

    // Read the number of test cases
    scanf("%lld", &num_test_cases);

    // Process each test case
    while (num_test_cases > 0) {
        long long int number_to_check; // The number to test for primality
        int is_prime = 1;              // Flag to indicate if the number is prime

        // Read the number to check
        scanf("%lld", &number_to_check);

        // Handle special cases for primality
        if (number_to_check <= 1) {
            is_prime = 0; // 0 and 1 are not prime
        } else if (number_to_check == 2 || number_to_check == 3) {
            is_prime = 1; // 2 and 3 are prime
        } else if (number_to_check % 2 == 0) {
            is_prime = 0; // Even numbers greater than 2 are not prime
        } else {
            // Check for divisibility by odd numbers from 3 up to sqrt(number_to_check)
            for (i = 3; i <= sqrt(number_to_check); i += 2) {
                if (number_to_check % i == 0) {
                    is_prime = 0; // Found a divisor, so not prime
                    break;
                }
            }
        }

        // Print the result
        if (is_prime) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }

        num_test_cases--; // Decrement test case counter
    }

    return 0;
}
