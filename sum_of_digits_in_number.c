/*
 * Purpose: Calculates the sum of the digits of a given integer.
 * Topic: Integer Manipulation, Loops
 */

#include <stdio.h>
#include <stdlib.h>

int calculate_digit_sum(int n) {
    int sum = 0;
    n = abs(n);

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main(void) {
    int number;

    printf("Enter an integer (digits will be summed): ");

    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    int digit_sum = calculate_digit_sum(number);

    printf("Sum of the digits in %d: %d\n", number, digit_sum);

    return 0;
}
