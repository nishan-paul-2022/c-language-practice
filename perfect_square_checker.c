/*
 * Purpose: Checks if a given non-negative integer is a perfect square.
 * Topic: Number Theory, Math Functions (sqrt), Integer Arithmetic, Conditional Logic
 */

#include <stdio.h>
#include <math.h>

int main() {
    int num_test_cases; // Number of test cases
    int case_num;       // Current test case number

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Process each test case
    for (case_num = 1; case_num <= num_test_cases; case_num++) {
        long long int number_to_check; // The number to check for perfect square property
        long long int integer_sqrt;    // The integer part of the square root

        // Read the number
        scanf("%lld", &number_to_check);

        // Handle negative numbers (not perfect squares by definition here)
        if (number_to_check < 0) {
            printf("Case %d: NO\n", case_num);
            continue;
        }

        // Calculate the integer part of the square root
        integer_sqrt = (long long int)sqrt(number_to_check);

        // Check if the square of the integer square root equals the original number
        // This is a robust way to check for perfect squares, avoiding float precision issues.
        if (integer_sqrt * integer_sqrt == number_to_check) {
            printf("Case %d: YES\n", case_num);
        } else {
            printf("Case %d: NO\n", case_num);
        }
    }

    return 0;
}
