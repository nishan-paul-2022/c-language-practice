/*
 * Purpose: Reads an integer and prints the remainders when divided by increasing powers of 10,
 *          up to the largest power of 10 less than the input number.
 * Topic: Loops, Modulo Operator, Powers of 10, Input Validation
 */

#include <stdio.h>
#include <math.h>

int read_input_value(void) {
    int input_value;
    printf("Enter an integer value: ");
    if (scanf(" %d", &input_value) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    if (input_value <= 0) {
        printf("Input value must be positive.\n");
        return 0;
    }
    
    return input_value;
}

void calculate_and_print_remainders(int input_value) {
    long long power_of_10 = 10;
    int remainder;

    while (power_of_10 < input_value) {
        remainder = input_value % power_of_10;
        printf("Remainder when divided by %lld: %d\n", power_of_10, remainder);

        if (__builtin_mul_overflow(power_of_10, 10, &power_of_10)) {
            break;
        }
    }
}

int main(void) {
    int input_value = read_input_value();
    
    if (input_value == 0) {
        return 0;
    }

    calculate_and_print_remainders(input_value);
    printf("Original value: %d\n", input_value);

    return 0;
}