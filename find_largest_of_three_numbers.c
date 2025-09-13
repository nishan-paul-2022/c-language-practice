/*
 * Purpose: Continuously reads three integers and determines the largest among them.
 * Topic: Loops, Conditional Operator (Ternary), Basic I/O
 */

#include <stdio.h>

int find_largest(int a, int b, int c) {
    int max = (a > b) ? a : b;
    return (max > c) ? max : c;
}

int main(void) {
    int num1, num2, num3;

    printf("Enter three integers. Press Ctrl+D/Ctrl+Z to stop.\n");

    while (scanf("%d %d %d", &num1, &num2, &num3) == 3) {
        printf("The largest number is: %d\n\n", find_largest(num1, num2, num3));
    }

    printf("Input stopped.\n");

    return 0;
}
