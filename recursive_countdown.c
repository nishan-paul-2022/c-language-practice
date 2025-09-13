/*
 * Purpose: Demonstrates recursion by printing numbers in descending order.
 * Topic: Recursion, Static Variables, Function Calls
 */

#include <stdio.h>

// Recursive function to print numbers from 5 down to 1
void print_countdown_recursive(void) {
    static int counter = 0; // Keep track across recursive calls

    counter++; // Increment counter

    if (counter > 5) return; // Base case

    print_countdown_recursive(); // Recursive call

    printf("%d\n", counter); // Print after recursion to get descending order
}

int main(void) {
    printf("Starting countdown...\n");
    print_countdown_recursive(); // Start recursion
    printf("Countdown finished.\n");
    return 0;
}
