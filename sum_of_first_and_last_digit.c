/*
 * Purpose: Calculates the sum of the first and last digits of a given integer.
 * Topic: Number Manipulation, Digits
 */

#include <stdio.h>
#include <stdlib.h>

// Function to find the first digit of an integer
int get_first_digit(int n) {
    n = abs(n);
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

// Function to find the last digit of an integer
int get_last_digit(int n) {
    return abs(n % 10);
}

// Function to calculate sum of first and last digits
int sum_first_last_digits(int n) {
    return get_first_digit(n) + get_last_digit(n);
}

int main(void) {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 1;
    }

    int result = sum_first_last_digits(number);
    printf("The sum of the first and last digits of %d is: %d\n", number, result);

    return 0;
}
