/*
 * Purpose: Demonstrates using hexadecimal integer literals, performing addition, and printing the result in octal format.
 * Topic: Data Types, Number Bases, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

void display_values(int hex_val1, int hex_val2, int sum_decimal) {
    printf("Hexadecimal value 1: 0x%X (Decimal: %d)\n", hex_val1, hex_val1);
    printf("Hexadecimal value 2: 0x%X (Decimal: %d)\n", hex_val2, hex_val2);
    printf("Sum in decimal: %d\n", sum_decimal);
    printf("Sum in octal: %o\n", sum_decimal);
}

int main(void) {
    int hex_val1;
    int hex_val2;
    int sum_decimal;

    hex_val1 = 0x987; 
    hex_val2 = 0x123987; 

    sum_decimal = hex_val1 + hex_val2;

    display_values(hex_val1, hex_val2, sum_decimal);

    return 0;
}
