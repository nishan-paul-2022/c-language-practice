/*
 * Purpose: Checks if a given positive integer is an Armstrong number.
 *          An Armstrong number is a number that is the sum of its own digits,
 *          each raised to the power of the number of digits.
 * Topic: Loops, Arithmetic Operations, String Conversion, Digit Manipulation
 */

#include <stdio.h>
#include <string.h>


long long int integer_power(int base, int exponent) {
    long long int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}


int count_digits(int number) {
    char num_as_string[20];
    sprintf(num_as_string, "%d", number);
    return strlen(num_as_string);
}


int is_armstrong(int number) {
    if (number < 0) {
        return 0; 
    }

    if (number == 0) {
        return 1; 
    }

    int temp_number = number;
    int num_digits = count_digits(number);
    long long int sum_of_powers = 0;

    while (temp_number > 0) {
        int digit = temp_number % 10;
        sum_of_powers += integer_power(digit, num_digits);
        temp_number /= 10;
    }

    return (sum_of_powers == number);
}

int main(void) {
    int original_number;
    printf("Enter a positive integer to check if it's an Armstrong number: ");
    scanf("%d", &original_number);

    if (original_number < 0) {
        printf("%d is not a positive integer.\n", original_number);
        return 0;
    }

    if (is_armstrong(original_number)) {
        printf("%d is an Armstrong number.\n", original_number);
    } else {
        printf("%d is Not an Armstrong number.\n", original_number);
    }

    return 0;
}
