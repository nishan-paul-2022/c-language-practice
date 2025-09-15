/*
 * Purpose: Finds the smallest integer 'k' such that the sum of integers from 1 to 'k' (the k-th triangular number) is greater than or equal to a given target sum 'n'.
 * Topic: Number Theory, Summation, Loops, Integer Arithmetic
 */

#include <stdio.h>

long long read_target_sum(void) {
    printf("Enter target sum: ");
    long long n;
    if (scanf("%lld", &n) != 1) {
        printf("Invalid input.\n");
        return -1;
    }
    return n;
}

long long find_smallest_k(long long target) {
    long long sum = 0;
    long long k = 1;
    while (sum < target) {
        sum += k;
        if (sum >= target) {
            break;
        }
        k++;
    }
    return k;
}

long long process_test_case(void) {
    long long target = read_target_sum();
    if (target < 0) {
        return -1;
    }
    long long k = find_smallest_k(target);
    printf("Smallest k: %lld\n", k);
    return k;
}

int main(void) {
    printf("Enter number of test cases: ");
    int num_cases;
    if (scanf("%d", &num_cases) != 1 || num_cases < 1) {
        return 0;
    }

    for (int i = 0; i < num_cases; i++) {
        printf("\nTest case %d: \n", i + 1);
        process_test_case();
    }

    return 0;
}
