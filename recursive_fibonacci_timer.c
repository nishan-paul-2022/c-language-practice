/*
 * Purpose: Calculates and prints the first N Fibonacci numbers using a recursive approach,
 *          and measures the time taken for the computation.
 * Topic: Recursion, Fibonacci Sequence, Time Measurement, Clock Function
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Recursive function to calculate the nth Fibonacci number.
// Note: This recursive implementation is inefficient due to repeated calculations (exponential time complexity).
// For larger values of n, an iterative or memoized approach would be significantly faster.
int calculate_fibonacci_recursive(int n) {
    // Base cases for the recursion.
    if (n <= 0) {
        return 0; // Fibonacci of 0 is 0.
    } else if (n == 1) {
        return 0; // Fibonacci of 1 is 0 (as per the original code's f(1)=0).
                  // Standard Fibonacci sequence usually starts F(0)=0, F(1)=1.
                  // The original code's f(1)=0, f(2)=1, f(3)=1, f(4)=2 implies a shifted sequence.
                  // Let's stick to the original logic: f(1)=0, f(2)=1.
    } else if (n == 2) {
        return 1; // Fibonacci of 2 is 1.
    } else {
        // Recursive step: F(n) = F(n-1) + F(n-2)
        return calculate_fibonacci_recursive(n - 1) + calculate_fibonacci_recursive(n - 2);
    }
}

int main() {
    clock_t start_time, end_time; // Variables to store start and end times for measurement.
    int num_terms;                // The number of Fibonacci terms to compute.
    int i;

    printf("Enter the number of Fibonacci terms to compute: ");
    // Read the number of terms.
    if (scanf("%d", &num_terms) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Record the start time before computation.
    start_time = clock();

    // Compute and print the first 'num_terms' Fibonacci numbers.
    printf("Fibonacci sequence up to term %d:\n", num_terms);
    for (i = 1; i <= num_terms; i++) {
        printf("%d ", calculate_fibonacci_recursive(i));
    }
    printf("\n");

    // Record the end time after computation.
    end_time = clock();

    // Calculate the elapsed time in seconds.
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the elapsed time.
    printf("Time taken for computation: %lf seconds\n", elapsed_time);

    return 0;
}
