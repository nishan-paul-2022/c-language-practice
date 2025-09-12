/*
 * Purpose: Finds and prints all positive divisors of a given integer.
 * Topic: Loops, Conditional Statements, Mathematical Functions (sqrt)
 */

#include <stdio.h>

// Function to find and print all positive divisors of a given integer.
void find_and_print_divisors(int number) {
    if (number <= 0) {
        printf("Input must be a positive integer.\n");
        return;
    }

    printf("Divisors of %d are: ", number);

    for (int i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            printf("%d ", i); // Print the smaller divisor
            if (i * i != number) {
                printf("%d ", number / i); // Print the larger divisor
            }
        }
    }
    printf("\n");
}

int main(void) {
    int number;

    printf("Enter a positive integer: ");
    scanf("%d", &number);

    find_and_print_divisors(number);

    return 0;
}
