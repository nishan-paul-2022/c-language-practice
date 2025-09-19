/*
 * Purpose: Calculates and prints binomial coefficients (nCr) for a given n and r.
 * Topic: Combinatorics, Mathematical Functions
 */

#include <stdio.h>

int calculate_ncr(int n, int r) {
    if (r < 0 || r > n) {
        return -1;
    }
    if (r == 0 || r == n) {
        return 1;
    }
    if (r > n / 2) {
        r = n - r;
    }

    int result = 1;
    for (int i = 1; i <= r; ++i) {
        result = result * (n - i + 1) / i;
    }
    
    return result;
}

int get_input_values(int *n, int *r) {
    printf("Enter the values for n and r (e.g., '10 5' for C(10, 5)): ");

    if (scanf("%d %d", n, r) != 2) {
        printf("Invalid input format. Please enter two integers separated by a space.\n");
        return -1;
    }
    
    return 0;
}

void display_result(int n, int r, int ncr) {
    if (ncr == -1) {
        printf("Invalid input (n or r out of bounds).\n");
    } else {
        printf("C(%d, %d) = %d\n", n, r, ncr);
    }
}

int main(void) {
    int n, r;
    if (get_input_values(&n, &r) == -1) {
        return 0;
    }
    
    int ncr = calculate_ncr(n, r);
    display_result(n, r, ncr);
    
    return 0;
}
