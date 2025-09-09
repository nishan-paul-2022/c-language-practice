/*
 * Purpose: Continuously reads three integers and determines both the largest and smallest among them.
 * Topic: Loops, Conditional Operator (Ternary), Basic I/O
 */

#include <stdio.h>

int main() {
    int num1, num2, num3; // Three integer numbers to compare
    int largest_val;      // Stores the largest number
    int smallest_val;     // Stores the smallest number

    // Loop to continuously read three numbers until scanf fails (e.g., EOF or invalid input)
    printf("Enter three integers separated by spaces (e.g., 10 20 5). Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to stop.\n");
    while (scanf("%d %d %d", &num1, &num2, &num3) == 3) { // Check if 3 items were successfully read
        // Find the largest number using nested ternary operators
        largest_val = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

        // Find the smallest number using nested ternary operators
        smallest_val = (num1 < num2) ? ((num1 < num3) ? num1 : num3) : ((num2 < num3) ? num2 : num3);

        // Print the largest and smallest numbers found
        printf("\nThe largest number is: %d\n", largest_val);
        printf("The smallest number is: %d\n\n", smallest_val);
    }

    printf("Input stopped or invalid input received.\n");

    return 0;
}
