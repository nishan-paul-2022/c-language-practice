/*
 * Purpose: Demonstrates the use of various bitwise operators in C.
 * Topic: Bitwise Operators
 */

#include <stdio.h>

int main()
{
    int a = 10; // Binary: 0000 1010
    int b = 20; // Binary: 0001 0100
    char c = -60; // Example for bitwise NOT on a signed char

    printf("Demonstrating Bitwise Operators:\n");
    printf("a = %d (binary: 0...01010)\n", a);
    printf("b = %d (binary: 0...10100)\n", b);
    printf("c = %d (signed char)\n\n", c);

    // Bitwise AND (&)
    // 0000 1010 (&) 0001 0100 = 0000 0000 (0)
    printf("a & b (AND): %d\n", a & b);

    // Bitwise OR (|)
    // 0000 1010 (|) 0001 0100 = 0001 1110 (30)
    printf("a | b (OR): %d\n", a | b);

    // Bitwise NOT (~)
    // For ~c, it depends on the exact binary representation of -60 (two's complement).
    // For a 8-bit signed char, -60 is 11000100. ~(-60) would be 00111011 (59).
    // For an int, it will be ~(-60) as an int.
    printf("~c (NOT): %d\n", ~c);

    // Bitwise XOR (^)
    // 0000 1010 (^) 0001 0100 = 0001 1110 (30)
    printf("a ^ b (XOR): %d\n", a ^ b);

    // Right Shift (>>)
    // a >> 1 (10 >> 1) = 0000 0101 (5)
    printf("a >> 1 (Right Shift): %d\n", a >> 1);

    // Left Shift (<<)
    // a << 1 (10 << 1) = 0001 0100 (20)
    printf("a << 1 (Left Shift): %d\n", a << 1);

    return 0;
}
