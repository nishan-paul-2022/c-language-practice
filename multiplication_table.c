// Purpose: Prints the multiplication table for a given number up to 10.
// Topic: Multiplication Table, Loops, Input/Output

#include <stdio.h>

int main() {
    int number;
    int multiplier;
    int result;

    printf("Enter an integer to see its multiplication table: ");
    // Read the number from user input and validate
    if (scanf("%d", &number) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    printf("\nMultiplication table for %d:\n", number);

    // Loop from 1 to 10 to generate the multiplication table
    for (multiplier = 1; multiplier <= 10; multiplier++) {
        result = number * multiplier;
        printf("%d X %d = %d\n", number, multiplier, result);
    }

    return 0;
}
