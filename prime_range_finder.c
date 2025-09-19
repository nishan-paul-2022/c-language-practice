/*
 * Purpose: Finds and prints all prime numbers within a specified range.
 * Topic: Prime Numbers, Loops, Conditional Statements, Input Parsing
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

int main(void) {
    int start_range, end_range;

    printf("Enter the start and end of the range (e.g., 1 100): ");
    if (scanf("%d %d", &start_range, &end_range) != 2) {
        printf("Invalid input format. Please enter two integers.\n");
        return 0;
    }

    printf("\nPrime numbers between %d and %d are:\n", start_range, end_range);
    for (int i = start_range; i <= end_range; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
