/*
 * Purpose: Calculates the number of combinations (nCr) using an iterative approach.
 * Topic: Loops, Arithmetic Operations, Combinatorics
 */

#include <stdio.h>

int main(void) {
    int num_test_cases;
    int case_number = 1;

    printf("=== Combinations Calculator (nCr) ===\n");
    printf("This program calculates nCr (n choose r) for given values.\n\n");
    
    printf("Enter the number of test cases: ");
    scanf("%d", &num_test_cases);

    while (num_test_cases > 0) {
        int n, r;
        long long int numerator = 1; // Product of n*(n-1)*...*(n-r+1)
        long long int denominator = 1; // r factorial

        printf("Enter n and r for Case %d (format: n r): ", case_number);
        scanf("%d %d", &n, &r);

        if (r < 0 || r > n) {
            printf("Case %d: Error - r must be between 0 and n.\n\n", case_number);
            num_test_cases--;
            case_number++;
            continue;
        }

        // Use symmetry property: C(n,r) = C(n,n-r)
        if (r > n / 2) {
            r = n - r;
        }

        // Calculate nCr efficiently
        for (int i = 0; i < r; i++) {
            numerator *= (n - i);
            denominator *= (i + 1);
        }

        printf("Case %d: C(%d,%d) = %lld\n\n", case_number, n, r, numerator / denominator);

        num_test_cases--;
        case_number++;
    }

    printf("Thank you for using the Combinations Calculator!\n");
    return 0;
}
