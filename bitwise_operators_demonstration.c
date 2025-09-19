/*
 * Purpose: Demonstrates the use of various bitwise operators.
 * Topic: Bitwise Operators
 */

#include <stdio.h>

int main(void) {
    int a = 10; 
    int b = 20; 
    int c = -60; 

    printf("Demonstrating Bitwise Operators:\n");

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n\n", c);

    printf("a & b   : %d\n", a & b); 
    printf("a | b   : %d\n", a | b); 
    printf("~c      : %d\n", ~c); 
    printf("a ^ b   : %d\n", a ^ b); 
    printf("a >> 1  : %d\n", a >> 1); 
    printf("a << 1  : %d\n", a << 1); 

    return 0;
}
