#include <stdio.h>

// Function to calculate the n-th term of a Fibonacci-like sequence.
// The sequence starts with f(1)=0, f(2)=1, and f(n) = f(n-1) + f(n-2) for n > 2.
// This is equivalent to the standard Fibonacci sequence where f(n) = F_{n-1}.
// Note: Recursive calculation of Fibonacci numbers is inefficient due to repeated computations.
// For larger values of n, an iterative approach or memoization would be significantly faster.
int calculate_fibonacci_term(int n) {
    // Base cases for the sequence
    if (n <= 0) { // Handle non-positive input gracefully, though problem implies n >= 1
        return 0; 
    }
    if (n == 1) {
        return 0; // f(1) = 0
    }
    if (n == 2) {
        return 1; // f(2) = 1
    }
    
    // Recursive step: calculate the term by summing the two preceding terms
    // This is computationally expensive for large n.
    int term = calculate_fibonacci_term(n - 1) + calculate_fibonacci_term(n - 2);
    return term;
}

int main() {
    int n;                  // The number of terms to calculate and sum.
    int current_term_index; // Loop counter to iterate from 1 to n.
    int fib_term;           // Stores the calculated Fibonacci term.
    long long int total_sum = 0; // Stores the sum of the Fibonacci terms. Use long long for potentially large sums.

    // Read the number of terms 'n' from standard input.
    scanf("%d", &n);

    // Iterate from the 1st term up to the n-th term.
    for (current_term_index = 1; current_term_index <= n; current_term_index++) {
        // Calculate the Fibonacci term for the current index.
        fib_term = calculate_fibonacci_term(current_term_index);
        
        // Print the calculated term followed by a space.
        printf("%d ", fib_term);
        
        // Add the calculated term to the total sum.
        total_sum += fib_term;
    }

    // Print two newlines for formatting, then print the total sum.
    // %lld is used for printing long long int.
    printf("\n\n%lld\n", total_sum);

    return 0; // Indicate successful execution
}
