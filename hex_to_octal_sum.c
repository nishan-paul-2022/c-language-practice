/*
 * Purpose: Demonstrates adding two hexadecimal numbers and printing the sum in octal format.
 * Topic: Number Bases (Hexadecimal, Octal), printf Formatting
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int hex_value1;
    int hex_value2;
    int sum;

    // Assign hexadecimal values to variables
    hex_value1 = 0x987; // Represents 2439 in decimal
    hex_value2 = 0x123987; // Represents 1194471 in decimal

    // Calculate the sum of the two hexadecimal values
    sum = hex_value1 + hex_value2;

    // Print the sum in octal format
    // 0x987 (hex) = 2439 (dec) = 4547 (oct)
    // 0x123987 (hex) = 1194471 (dec) = 4444747 (oct)
    // Sum (dec) = 2439 + 1194471 = 1196910
    // Sum (oct) = 4547 + 4444747 = 4452276 (oct)
    printf("Hexadecimal Value 1: 0x%X (%d decimal, %o octal)\n", hex_value1, hex_value1, hex_value1);
    printf("Hexadecimal Value 2: 0x%X (%d decimal, %o octal)\n", hex_value2, hex_value2);
    printf("Sum in Octal: %o\n", sum);

    return 0;
}
