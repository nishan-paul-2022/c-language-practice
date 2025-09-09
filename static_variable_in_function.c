/*
 * Purpose: Demonstrates the behavior of static variables within functions, showing that they retain their value between calls.
 * Topic: Functions, Static Variables, Scope, Initialization
 */

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function demonstrating the use of a static variable.
// The static variable 'counter' is initialized only once when the program starts.
// Each time the function is called, 'counter' retains its previous value and is incremented.
int increment_static_value() {
    static int counter = 10; // Initialized only on the first call (or program start)
    counter++; // Increment the static variable
    return counter; // Return the incremented value
}

int main() {
    int result;

    printf("Demonstrating static variable behavior:\n");

    // Call the function multiple times and print the returned value.
    // Each call increments the static variable 'counter' within the function.
    printf("Call 1: %d\n", increment_static_value()); // Expected: 11
    printf("Call 2: %d\n", increment_static_value()); // Expected: 12
    printf("Call 3: %d\n", increment_static_value()); // Expected: 13
    printf("Call 4: %d\n", increment_static_value()); // Expected: 14
    printf("Call 5: %d\n", increment_static_value()); // Expected: 15
    printf("Call 6: %d\n", increment_static_value()); // Expected: 16

    return 0;
}
