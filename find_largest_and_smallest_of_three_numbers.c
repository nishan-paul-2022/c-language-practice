/*
 * Purpose: Continuously reads three integers and determines both the largest and smallest among them.
 * Topic: Loops, Conditional Operator (Ternary), Basic I/O
 */

#include <stdio.h>

// Finds the largest of three integers.
int find_largest(int a, int b, int c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

// Finds the smallest of three integers.
int find_smallest(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int main(void) {
    int num1, num2, num3;

    printf("Enter three integers separated by spaces (e.g., 10 20 5).\n");
    printf("Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to stop.\n");

    // Continuously read three numbers until scanf fails.
    while (scanf("%d %d %d", &num1, &num2, &num3) == 3) {
        int largest_val = find_largest(num1, num2, num3);
        int smallest_val = find_smallest(num1, num2, num3);

        printf("\nLargest number: %d\n", largest_val);
        printf("Smallest number: %d\n\n", smallest_val);
    }

    printf("Input stopped or invalid input received.\n");

    return 0;
}