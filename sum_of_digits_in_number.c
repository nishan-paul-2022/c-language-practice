/*
 * Purpose: Calculates the sum of the digits of a given integer.
 * Topic: Integer Manipulation, Loops
 */

#include <stdio.h>
#include <stdlib.h>

// Calculate sum of digits of an integer
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
    printf("Enter an integer (digits will be summed): ");
    int number;
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    int digit_sum = calculate_digit_sum(number);
    printf("The sum of the digits of %d is: %d\n", number, digit_sum);

    return 0;
}
