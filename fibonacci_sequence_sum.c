/*
 * Purpose: Calculates and prints the first 'n' terms of the Fibonacci sequence and their sum.
 * Topic: Recursion, Loops, Basic I/O
 */
    
#include <stdio.h>

int calculate_fibonacci_term(int n) {
    if (n <= 0) {
        return 0; 
    }
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    
    return calculate_fibonacci_term(n - 1) + calculate_fibonacci_term(n - 2);
}

int get_term_count(void) {
    int n;
    printf("Enter the number of Fibonacci terms to calculate and sum: ");
    scanf("%d", &n);
    return n;
}

long long int calculate_and_print_fibonacci_sum(int n) {
    long long int total_sum = 0;
    
    for (int current_term_index = 1; current_term_index <= n; current_term_index++) {
        int fib_term = calculate_fibonacci_term(current_term_index);
        printf("%d ", fib_term);
        total_sum += fib_term;
    }
    
    return total_sum;
}

void display_sum(long long int total_sum) {
    printf("\n\n%lld\n", total_sum);
}

int main(void) {
    int n = get_term_count();
    long long int total_sum = calculate_and_print_fibonacci_sum(n);
    
    display_sum(total_sum);
    
    return 0;
}
