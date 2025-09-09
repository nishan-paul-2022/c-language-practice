/*
 * Purpose: Calculates and prints Fibonacci numbers using recursion, along with their sum.
 * Topic: Recursion, Fibonacci Sequence, Basic Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the nth Fibonacci number using recursion.
// Standard definition: F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2) for n > 1.
// Note: Recursive Fibonacci is highly inefficient due to repeated calculations (exponential time complexity).
// For larger inputs, an iterative approach or memoization would be significantly faster.
int calculate_fibonacci_recursive(int n) {
    // Base cases for the standard Fibonacci sequence
    if (n <= 0) {
        return 0; // F(0) = 0
    } else if (n == 1) {
        return 1; // F(1) = 1
    } else {
        // Recursive step: F(n) = F(n-1) + F(n-2)
        return calculate_fibonacci_recursive(n - 1) + calculate_fibonacci_recursive(n - 2);
    }
}

int main() {
    int input_number;
    int nth_fib_value;
    int sum_of_fibs = 0;

    // Get input from the user
    printf("Enter a non-negative integer to calculate Fibonacci numbers up to that term: ");
    if (scanf("%d", &input_number) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Handle non-positive input (although the function handles n<=0, it's good practice to validate user input)
    if (input_number < 0) {
        fprintf(stderr, "Error: Input must be a non-negative integer.\n");
        return 0;
    }

    // Calculate the Fibonacci number for the input 'n' (i.e., F(input_number))
    nth_fib_value = calculate_fibonacci_recursive(input_number);

    printf("Fibonacci sequence up to term %d:\n", input_number);
    // Loop from 1 to input_number to print F(1) to F(input_number)
    for (int i = 1; i <= input_number; ++i) {
        int current_fib = calculate_fibonacci_recursive(i);
        printf("%d ", current_fib);
        sum_of_fibs += current_fib;
    }

    // Print the nth Fibonacci number and the sum of the sequence up to n
    printf("\nFibonacci number F(%d) is: %d\n", input_number, nth_fib_value);
    printf("Sum of Fibonacci numbers from F(1) to F(%d) is: %d\n", input_number, sum_of_fibs);

    return 0;
}
