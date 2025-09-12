/*
 * Purpose: Continuously reads three integers and determines the largest among them.
 * Topic: Loops, Conditional Operator (Ternary), Basic I/O
 */

#include <stdio.h>

// Returns the largest of three integer values.
int find_largest(int a, int b, int c) {
    int max = (a > b) ? a : b; // Find the largest between a and b
    return (max > c) ? max : c; // Compare with c to find the overall largest
}

int main(void) {
    int num1, num2, num3;

    // Prompt for user input.
    printf("Enter three integers (e.g., 10 20 5). Press Ctrl+D/Ctrl+Z to stop.\n");

    // Loop until input fails or EOF is reached.
    while (scanf("%d %d %d", &num1, &num2, &num3) == 3) {
        // Find and display the largest number.
        printf("The largest number is: %d\n\n", find_largest(num1, num2, num3));
    }

    printf("Input stopped.\n");

    return 0;
}
