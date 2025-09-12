/*
 * Purpose: Generates and prints the Fibonacci sequence up to the Nth term using a recursive function.
 *          The sequence starts with F(1)=0, F(2)=1, F(3)=1, F(4)=2, and so on.
 * Topic: Recursion, Loops, Fibonacci Sequence
 */

#include <stdio.h>

// Calculate the Nth Fibonacci number
int calculate_fibonacci_recursive(int n) {
    if (n <= 0) {
        return 0; // F(0) = 0
    } else if (n == 1) {
        return 0; // F(1) = 0
    } else if (n == 2) {
        return 1; // F(2) = 1
    } else {
        return calculate_fibonacci_recursive(n - 1) + calculate_fibonacci_recursive(n - 2);
    }
}

int main(void) {
    int num_terms;

    printf("Enter the number of Fibonacci terms to generate: "); // Input prompt
    scanf("%d", &num_terms);

    if (num_terms < 0) {
        printf("Error: Number of terms cannot be negative.\n");
        return 0;
    }

    printf("Fibonacci Sequence (up to %d terms):\n", num_terms); // Output title
    for (int i = 1; i <= num_terms; i++) {
        printf("%d ", calculate_fibonacci_recursive(i));
    }
    printf("\n");

    return 0;
}
