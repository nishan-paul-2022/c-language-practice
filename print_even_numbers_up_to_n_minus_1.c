/*
 * Purpose: Demonstrates printing even numbers up to a user-defined limit (n-1).
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int limit_value; // Variable to store the user-defined limit
    int current_even_number = 0; // Variable to store and print even numbers, initialized to 0

    // Prompt user for input
    printf("Enter an integer value: ");
    scanf("%d", &limit_value);

    // Loop to print even numbers, incrementing by 2 in each step
    // The loop continues as long as current_even_number is less than limit_value - 1
    while (current_even_number < limit_value - 1) {
        current_even_number += 2; // Increment by 2 to get the next even number
        printf("%d\n", current_even_number); // Print the current even number
    }

    return 0;
}
