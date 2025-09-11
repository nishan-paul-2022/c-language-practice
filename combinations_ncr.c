/*
 * Purpose: Calculates the number of combinations (nCr) using an iterative approach.
 * Topic: Loops, Arithmetic Operations, Combinatorics
 */

#include <stdio.h>

// Unused function - calculate_factorial is not actually used in the program
long long int calculate_factorial(int num) {
    long long int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

int main(void) {
    int num_test_cases; // Number of test cases
    int case_number = 1; // Test case counter

    // Get number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &num_test_cases);

    // Process each test case
    while (num_test_cases > 0) {
        int n, r; // n and r values for nCr calculation
        long long int numerator_part = 1; // Numerator: n * (n-1) * ... * (n-r+1)
        long long int denominator_r_factorial = 1; // Denominator: r!

        // Get n and r for current test case
        printf("Enter n and r for Case %d (e.g., 5 2): ", case_number);
        scanf("%d %d", &n, &r);

        // Validate input for combinations
        if (r < 0 || r > n) {
            printf("Case %d: Invalid input for combinations (r must be between 0 and n).\n", case_number);
            num_test_cases--;
            case_number++;
            continue;
        }

        // Optimization: C(n, r) = C(n, n-r) to reduce computation
        if (r > n / 2) {
            r = n - r;
        }

        // Calculate nCr using iterative multiplication and division
        for (int i = 0; i < r; i++) {
            numerator_part *= (n - i);
            denominator_r_factorial *= (i + 1);
        }

        // Print result for current test case
        printf("Case %d: %lld\n", case_number, numerator_part / denominator_r_factorial);

        num_test_cases--;
        case_number++;
    }

    return 0;
}
