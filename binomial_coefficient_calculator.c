/*
 * Purpose: Calculates and prints binomial coefficients (nCr) for a given n and r.
 * Topic: Combinatorics, Mathematical Functions
 */

#include <stdio.h>

// Function to calculate nCr using the formula C(n, k) = C(n, k-1) * (n - k + 1) / k
// This iterative approach avoids large intermediate factorial calculations.
long long calculate_ncr(int n, int r)
{
    // Base cases and error handling
    if (r < 0 || r > n)
    {
        return -1; // Indicate an error or invalid input
    }
    if (r == 0 || r == n)
    {
        return 1; // C(n, 0) = 1, C(n, n) = 1
    }
    // Optimization: C(n, r) = C(n, n-r)
    if (r > n / 2)
    {
        r = n - r;
    }

    long long result = 1;
    for (int i = 1; i <= r; ++i)
    {
        // Calculate C(n, i) from C(n, i-1)
        // result = result * (n - i + 1) / i;
        // To prevent overflow, perform multiplication before division,
        // but ensure intermediate results fit in long long.
        // A safer way is to use properties of combinations or BigInt for very large numbers.
        // For typical integer inputs, this should be sufficient.
        if (__builtin_mul_overflow(result, (n - i + 1), &result))
        {
            return -2; // Indicate overflow
        }
        result /= i;
    }
    return result;
}

int main(void)
{
    int n, r;

    // Prompt user for input
    printf("Enter the values for n and r (e.g., '10 5' for C(10, 5)): ");

    // Read input. Using "%d %d" for space-separated input.
    if (scanf("%d %d", &n, &r) != 2)
    {
        printf("Invalid input format. Please enter two integers separated by a space.\n");
       return 0;
    }

    // Calculate and print the binomial coefficient
    long long ncr= calculate_ncr(n, r);

    if (ncr == -1)
    {
        printf("Error: Invalid input (n or r out of bounds).\n");
    }
    else if (ncr == -2)
    {
        printf("Error: Calculation resulted in overflow.\n");
    }
    else
    {
        printf("C(%d, %d) = %lld\n", n, r, ncr);
    }

    return 0;
}
