/*
 * Purpose: Calculates and prints Fibonacci numbers using recursion, along with their sum.
 * Topic: Recursion, Fibonacci Sequence, Basic Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate nth Fibonacci number (F(0)=0, F(1)=1)
int calculate_fibonacci_recursive(int n) {
    if (n <= 0) return 0; // F(0)=0
    if (n == 1) return 1; // F(1)=1
    return calculate_fibonacci_recursive(n - 1) + calculate_fibonacci_recursive(n - 2); // F(n)=F(n-1)+F(n-2)
}

int main(void) {
    int input_number, nth_fib_value, sum_of_fibs = 0;

    printf("Enter a non-negative integer to calculate Fibonacci numbers up to that term: ");
    if (scanf("%d", &input_number) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 0;
    }

    if (input_number < 0) {
        fprintf(stderr, "Input must be non-negative.\n");
        return 0;
    }

    nth_fib_value = calculate_fibonacci_recursive(input_number);

    printf("Fibonacci sequence up to term %d:\n", input_number);
    for (int i = 1; i <= input_number; ++i) {
        int current_fib = calculate_fibonacci_recursive(i);
        printf("%d ", current_fib);
        sum_of_fibs += current_fib;
    }
    printf("\n");

    printf("Fibonacci number F(%d) is: %d\n", input_number, nth_fib_value);
    printf("Sum of Fibonacci numbers from F(1) to F(%d) is: %d\n", input_number, sum_of_fibs);

    return 0;
}
