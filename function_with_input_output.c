/*
 * Purpose: Demonstrates a function that takes arguments, reads input, performs a calculation, prints output, and returns a character.
 * Topic: Functions, Parameters, Input/Output, Return Values
 */

#include <stdio.h>

char process_numbers_and_return_char(int num1, int num2) {
    int multiplier;
    int sum = num1 + num2;
    int product;

    printf("Enter an integer to multiply with the sum: ");
    if (scanf("%d", &multiplier) != 1) {
        fprintf(stderr, "Invalid input for multiplier.\n");
        return '?';
    }
    while (getchar() != '\n');

    product = sum * multiplier;

    printf("Product of (sum * multiplier) is: %d\n", product);

    return 'D';
}

int main(void) {
    int number1, number2;
    char returned_char;

    printf("Enter two integers separated by a comma (e.g., 5, 10): ");
    if (scanf("%d, %d", &number1, &number2) != 2) {
        fprintf(stderr, "Invalid input format. Please enter two integers separated by a comma.\n");
        return 0;
    }
    while (getchar() != '\n');

    returned_char = process_numbers_and_return_char(number1, number2);

    printf("Character returned by the function: %c\n", returned_char);

    return 0;
}
