/*
 * Purpose: Generates and prints the Fibonacci sequence up to the Nth term using a recursive function.
 *          The sequence starts with F(1)=0, F(2)=1, F(3)=1, F(4)=2, and so on.
 * Topic: Recursion, Loops, Fibonacci Sequence
 */

#include <stdio.h> // Required for printf and scanf

// Recursive function to calculate the Nth Fibonacci number
// n: the term number in the Fibonacci sequence
int calculate_fibonacci_recursive(int n) {
    // Base cases:
    if (n <= 0) {
        return 0; // F(0) is defined as 0
    } else if (n == 1) {
        return 0; // F(1) is defined as 0 in this specific sequence
    } else if (n == 2) {
        return 1; // F(2) is defined as 1 in this specific sequence
    }
    // Recursive step: F(n) = F(n-1) + F(n-2)
    else {
        return calculate_fibonacci_recursive(n - 1) + calculate_fibonacci_recursive(n - 2);
    }
}

int main() {
    int num_terms; // Number of Fibonacci terms to generate
    int i;         // Loop counter

    // Prompt user for input
    printf("Enter the number of Fibonacci terms to generate: ");
    scanf("%d", &num_terms);

    // Validate input
    if (num_terms < 0) {
        printf("Error: Number of terms cannot be negative.\n");
        return 0;
    }

    printf("Fibonacci Sequence (up to %d terms):\n", num_terms);
    // Loop to print each term of the Fibonacci sequence
    for (i = 1; i <= num_terms; i++) {
        printf("%d ", calculate_fibonacci_recursive(i));
    }
    printf("\n");

    return 0;
}
