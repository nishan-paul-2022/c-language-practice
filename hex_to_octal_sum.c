/*
 * Purpose: Demonstrates adding two hexadecimal numbers and printing the sum in octal format.
 * Topic: Number Bases (Hexadecimal, Octal), printf Formatting
 */

#include <stdio.h>
#include <stdlib.h>

void display_number_formats(int hex_value1, int hex_value2, int sum) {
    printf("Hexadecimal Value 1: 0x%X (%d decimal, %o octal)\n", hex_value1, hex_value1, hex_value1);
    printf("Hexadecimal Value 2: 0x%X (%d decimal, %o octal)\n", hex_value2, hex_value2, hex_value2);
    printf("Sum in Octal: %o\n", sum);
}

int main(void) {
    int hex_value1;
    int hex_value2;
    int sum;

    hex_value1 = 0x987; // Represents 2439 in decimal
    hex_value2 = 0x123987; // Represents 1194471 in decimal

    sum = hex_value1 + hex_value2;

    display_number_formats(hex_value1, hex_value2, sum);

    return 0;
}
