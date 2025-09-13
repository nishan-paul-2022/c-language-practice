/*
 * Purpose: Calculates and prints the first N Fibonacci numbers using a recursive approach,
 *          and measures the time taken for the computation.
 * Topic: Recursion, Fibonacci Sequence, Time Measurement, Clock Function
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Recursive function to calculate nth Fibonacci number (f(1)=0, f(2)=1)
int calculate_fibonacci_recursive(int n) {
    if (n <= 0) return 0; // Base case: F(0)=0
    if (n == 1) return 0; // F(1)=0
    if (n == 2) return 1; // F(2)=1
    return calculate_fibonacci_recursive(n - 1) + calculate_fibonacci_recursive(n - 2); // Recursive step
}

int main(void) {
    int num_terms, i;
    clock_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of Fibonacci terms to compute: ");
    if (scanf("%d", &num_terms) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    while (getchar() != '\n'); // Clear input buffer

    start_time = clock(); // Start timing

    printf("Fibonacci sequence up to term %d:\n", num_terms);
    for (i = 1; i <= num_terms; i++) {
        printf("%d ", calculate_fibonacci_recursive(i));
    }
    printf("\n");

    end_time = clock(); // End timing
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Time taken for computation: %lf seconds\n", elapsed_time);

    return 0;
}
