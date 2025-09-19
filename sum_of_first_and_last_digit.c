/*
 * Purpose: Calculates the sum of the first and last digits of a given integer.
 * Topic: Number Manipulation, Digits
 */

#include <stdio.h>
#include <stdlib.h>

int get_first_digit(int n) {
    n = abs(n);
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

int get_last_digit(int n) {
    return abs(n % 10);
}

int sum_of_first_and_last_digit(int n) {
    return get_first_digit(n) + get_last_digit(n);
}

int main(void) {
    int number;

    printf("Enter an integer: ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    int result = sum_of_first_and_last_digit(number);
    printf("Sum of the first and last digit of %d is: %d\n", number, result);

    return 0;
}
