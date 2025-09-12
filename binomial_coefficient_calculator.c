/*
 * Purpose: Calculates and prints binomial coefficients (nCr) for a given n and r.
 * Topic: Combinatorics, Mathematical Functions
 */

#include <stdio.h>

// Calculate nCr using iterative approach to avoid large factorials
long long calculate_ncr(int n, int r) {
    // Handle invalid inputs
    if (r < 0 || r > n) {
        return -1;
    }
    if (r == 0 || r == n) {
        return 1; // Base cases: C(n, 0) = C(n, n) = 1
    }
    // Optimize by using symmetry property: C(n, r) = C(n, n-r)
    if (r > n / 2) {
        r = n - r;
    }

    long long result = 1;
    for (int i = 1; i <= r; ++i) {
        // Multiply by (n - i + 1) and divide by i to get C(n, i) from C(n, i-1)
        // Check for overflow during multiplication
        if (__builtin_mul_overflow(result, (n - i + 1), &result)) {
            return -2; // Error code for overflow
        }
        result /= i;
    }
    
    return result;
}

int main(void) {
    int n, r;

    printf("Enter the values for n and r (e.g., '10 5' for C(10, 5)): ");

    if (scanf("%d %d", &n, &r) != 2) {
        printf("Invalid input format. Please enter two integers separated by a space.\n");
        return 0;
    }

    long long ncr= calculate_ncr(n, r);

    if (ncr == -1) {
        printf("Error: Invalid input (n or r out of bounds).\n");
    }
    else if (ncr == -2) {
        printf("Error: Calculation resulted in overflow.\n");
    }
    else {
        printf("C(%d, %d) = %lld\n", n, r, ncr);
    }

    return 0;
}
