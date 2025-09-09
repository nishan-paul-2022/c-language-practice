/*
 * Purpose: Continuously reads three integers and determines the largest among them.
 * Topic: Loops, Conditional Operator (Ternary), Basic I/O
 */

#include <stdio.h>

int main() {
    int num1, num2, num3; // Three integer numbers to compare
    int largest_of_two;   // Stores the largest of the first two numbers
    int largest_number;   // Stores the overall largest number

    // Loop to continuously read three numbers until scanf fails (e.g., EOF or invalid input)
    printf("Enter three integers separated by spaces (e.g., 10 20 5). Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to stop.\n");
    while (scanf("%d %d %d", &num1, &num2, &num3) == 3) { // Check if 3 items were successfully read
        // Find the largest of the first two numbers using the ternary operator
        largest_of_two = (num1 > num2) ? num1 : num2;

        // Compare the largest of the first two with the third number to find the overall largest
        largest_number = (largest_of_two > num3) ? largest_of_two : num3;

        // Print the largest number found
        printf("\nThe largest number is: %d\n\n", largest_number);
    }

    printf("Input stopped or invalid input received.\n");

    return 0;
}
