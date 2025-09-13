/*
 * Purpose: Continuously reads three integers and determines both the largest and smallest among them.
 * Topic: Loops, Conditional Operator (Ternary), Basic I/O
 */

#include <stdio.h>

int find_largest(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int find_smallest(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int main(void) {
    int num1, num2, num3;

    printf("Enter three integers separated by spaces.\n");
    printf("Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to stop.\n");

    while (scanf("%d %d %d", &num1, &num2, &num3) == 3) {
        int largest_val = find_largest(num1, num2, num3);
        int smallest_val = find_smallest(num1, num2, num3);

        printf("\nLargest number: %d\n", largest_val);
        printf("Smallest number: %d\n\n", smallest_val);
    }

    printf("Input stopped or invalid input received.\n");

    return 0;
}
