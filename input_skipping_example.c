#include <stdio.h>

/*
 * Purpose: Demonstrates reading multiple integers from input, including skipping one.
 * Topic: Input/Output (scanf), Format Specifiers, Variable Declaration
 */
int main(void) {
    int num1, num2, skipped_value;
    int items_read;

    // Prompt user for three integers
    printf("Enter three integers (e.g., 10 20 30): ");

    // Read two integers and skip the third one using %*d
    // scanf returns number of successfully matched and assigned input items
    items_read = scanf("%d %d %*d", &num1, &num2);

    // Check if scanf successfully read the two required integers
    if (items_read == 2) {
        // Calculate and print the product of the two read integers
        printf("You entered: %d and %d\n", num1, num2);
        printf("The product of %d and %d is: %d\n", num1, num2, num1 * num2);
    } else {
        // Handle cases where input was not as expected
        printf("Invalid input. Please ensure you enter three integers separated by spaces.\n");
        // scanf failed to read num1 and num2 due to non-integer input
        // or an incomplete input line
        return 0;
    }

    return 0;
}
