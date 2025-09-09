// Purpose: Demonstrates using hexadecimal integer literals, performing addition, and printing the result in octal format.
// Topic: Data Types, Number Bases, Input/Output

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    // Declare variables with descriptive names
    int hex_val1;
    int hex_val2;
    int sum_decimal;
    int sum_octal;

    // Initialize variables with hexadecimal literals
    hex_val1 = 0x987; // Decimal: 2439
    hex_val2 = 0x123987; // Decimal: 1294375

    // Perform addition
    sum_decimal = hex_val1 + hex_val2; // Decimal sum: 1296814

    // Print the sum in octal format
    // The %o format specifier is used for octal output.
    printf("Hexadecimal value 1: 0x%X (Decimal: %d)\n", hex_val1, hex_val1);
    printf("Hexadecimal value 2: 0x%X (Decimal: %d)\n", hex_val2, hex_val2);
    printf("Sum in decimal: %d\n", sum_decimal);
    printf("Sum in octal: %o\n", sum_decimal);

    return 0;
}
