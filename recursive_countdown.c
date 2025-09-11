/*
 * Purpose: Demonstrates recursion by printing numbers in descending order.
 * Topic: Recursion, Static Variables, Function Calls
 */

#include <stdio.h>

// Recursive function to print numbers from 5 down to 1
void print_countdown_recursive() {
    static int counter = 0; // Static variable to keep track of the count across calls

    counter++; // Increment the counter for each call

    // Base case: stop recursion when counter exceeds 5
    if (counter > 5) {
        return;
    }

    // Optional: Print the counter before the recursive call to see the call stack progression
    // printf("Before recursive call: %d\n", counter);

    // Recursive call: call the function again
    print_countdown_recursive();

    // After the recursive call returns, print the current value of the counter
    // This will print numbers in descending order as the call stack unwinds
    printf("%d\n", counter);
}

int main(void) {
    printf("Starting countdown...\n");
    print_countdown_recursive(); // Initiate the recursive process
    printf("Countdown finished.\n");
    return 0;
}
