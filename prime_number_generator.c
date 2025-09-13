/*
 * Purpose: Generates and prints prime numbers within a specified range.
 * Topic: Prime Numbers, Loops, Conditional Statements, Functions
 */

#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void print_primes_in_range(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(void) {
    int start_num, end_num;

    printf("Enter the start and end of the range (e.g., 1 100): ");
    if (scanf("%d %d", &start_num, &end_num) != 2) {
        printf("Error: Invalid input. Please enter two integers.\n");
        return 0;
    }

    printf("\nPrime numbers between %d and %d are:\n", start_num, end_num);
    print_primes_in_range(start_num, end_num);

    return 0;
}
