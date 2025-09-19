/*
 * Purpose: Demonstrates the use of various bitwise operators.
 * Topic: Bitwise Operators
 */

#include <stdio.h>

int main(void) {
    int a = 10; // 0000 1010
    int b = 20; // 0001 0100
    int c = -60; // 1100 0100

    printf("Demonstrating Bitwise Operators:\n");

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n\n", c);

    printf("a & b   : %d\n", a & b); // Bitwise AND
    printf("a | b   : %d\n", a | b); // Bitwise OR
    printf("~c      : %d\n", ~c); // Bitwise NOT
    printf("a ^ b   : %d\n", a ^ b); // Bitwise XOR
    printf("a >> 1  : %d\n", a >> 1); // Right Shift
    printf("a << 1  : %d\n", a << 1); // Left Shift

    return 0;
}
