// Purpose: Demonstrates a function that takes arguments, reads input, performs a calculation, prints output, and returns a character.
// Topic: Functions, Parameters, Input/Output, Return Values

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function that takes two integers, reads another integer from input,
// calculates the product of their sum and the read integer, prints the product,
// and returns a character.
char process_numbers_and_return_char(int num1, int num2) {
    int multiplier;
    int sum = num1 + num2;
    int product;

    // Read an additional integer from standard input within the function
    printf("  (Inside function) Enter an integer to multiply with the sum: ");
    if (scanf("%d", &multiplier) != 1) {
        fprintf(stderr, "  (Inside function) Error: Invalid input for multiplier.\n");
        // In a real application, you might want to handle this error more gracefully,
        // perhaps by returning an error code or a specific character.
        // For this example, we'll return a default error character.
        return '?'; // Indicate an error
    }
    // Consume any remaining characters on the line after the multiplier, including the newline
    while (getchar() != '\n');

    // Calculate the product
    product = sum * multiplier;

    // Print the product from within the function
    printf("  (Inside function) Product of (sum * multiplier) is: %d\n", product);

    // Return a character
    return 'D'; // Returning a fixed character as in the original code
}

int main() {
    int number1, number2;
    char returned_char;

    // Get two integers from the user in main
    printf("Enter two integers separated by a comma (e.g., 5, 10): ");
    if (scanf("%d, %d", &number1, &number2) != 2) {
        fprintf(stderr, "Error: Invalid input format. Please enter two integers separated by a comma.\n");
        return 1; // Indicate an error
    }
    // Consume any remaining characters on the line after the second integer, including the newline
    while (getchar() != '\n');

    // Call the function, passing the two integers.
    // The function will prompt for more input and print its own output.
    returned_char = process_numbers_and_return_char(number1, number2);

    // Print the character returned by the function
    printf("Character returned by the function: %c\n", returned_char);

    return 0;
}
