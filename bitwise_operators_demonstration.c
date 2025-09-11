/*
 * Purpose: Demonstrates the use of various bitwise operators in C.
 * Topic: Bitwise Operators
 */

#include <stdio.h>

int main(void) {
    int a = 10; // 0000 1010
    int b = 20; // 0001 0100
    char c = -60; // For demonstrating bitwise NOT

    printf("Demonstrating Bitwise Operators:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d (signed char)\n\n", c);

    // Bitwise AND
    printf("a & b (AND): %d\n", a & b);

    // Bitwise OR
    printf("a | b (OR): %d\n", a | b);

    // Bitwise NOT
    printf("~c (NOT): %d\n", ~c);

    // Bitwise XOR
    printf("a ^ b (XOR): %d\n", a ^ b);

    // Right Shift
    printf("a >> 1 (Right Shift): %d\n", a >> 1);

    // Left Shift
    printf("a << 1 (Left Shift): %d\n", a << 1);

    return 0;
}
