/*
 * Purpose: Generates the Fibonacci sequence up to a specified number of terms using an iterative approach.
 * Topic: Iteration, Sequences, Basic Arithmetic
 */

#include <stdio.h>

int get_num_terms() {
    int num_terms;
    printf("Enter number of Fibonacci terms: ");
    if (scanf(" %d", &num_terms) != 1 || num_terms <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }
    return num_terms;
}

void generate_fibonacci(int num_terms) {
    long long first_term = 0, second_term = 1;
    long long next_term;
    int i;

    printf("Fibonacci Sequence:\n");

    if (num_terms >= 1) {
        printf("%lld", first_term);
    }
    if (num_terms >= 2) {
        printf(", %lld", second_term);
    }

    for (i = 3; i <= num_terms; i++) {
        next_term = first_term + second_term;
        printf(", %lld", next_term);
        first_term = second_term;
        second_term = next_term;
    }
    printf("\n");
}

int main(void) {
    int num_terms = get_num_terms();
    if (num_terms > 0) {
        generate_fibonacci(num_terms);
    }
    return 0;
}
