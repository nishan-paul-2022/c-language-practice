/*
 * Purpose: Demonstrates a function that takes arguments, reads input, performs a calculation, prints output, and returns a character.
 * Topic: Functions, Parameters, Input/Output, Return Values
 */

#include <stdio.h>

// Process two integers and return a character
char process_numbers_and_return_char(int num1, int num2) {
    int multiplier;
    int sum = num1 + num2;
    int product;

    printf("Enter an integer to multiply with the sum: "); // Prompt for multiplier
    if (scanf("%d", &multiplier) != 1) {
        fprintf(stderr, "Error: Invalid input for multiplier.\n");
        return '?'; // Error indicator
    }
    while (getchar() != '\n'); // Clear input buffer

    product = sum * multiplier; // Calculate product

    printf("Product of (sum * multiplier) is: %d\n", product); // Show result

    return 'D'; // Return character
}

int main(void) {
    int number1, number2;
    char returned_char;

    printf("Enter two integers separated by a comma (e.g., 5, 10): "); // Prompt for input
    if (scanf("%d, %d", &number1, &number2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two integers separated by a comma.\n");
        return 0; // Exit on input error
    }
    while (getchar() != '\n'); // Clear input buffer

    returned_char = process_numbers_and_return_char(number1, number2); // Process numbers

    printf("Character returned by the function: %c\n", returned_char); // Show returned character

    return 0;
}
