// Purpose: Demonstrates how to fix infinite recursion by adding a base case.
// Topic: Recursion, Base Case, Function Calls

#include <stdio.h>

// Recursive function with a base case to prevent infinite recursion
void safe_recursive_function(int depth) {
    // Base case: stop recursion when depth reaches a certain limit (e.g., 5)
    if (depth <= 0) {
        printf("Recursion depth reached zero. Stopping.\n");
        return;
    }

    printf("Calling recursively with depth: %d\n", depth);

    // Recursive call: call the function with a decremented depth
    safe_recursive_function(depth - 1);

    // This part of the code will execute after the recursive calls return
    printf("Returning from depth: %d\n", depth);
}

int main() {
    printf("Starting safe recursive function...\n");
    safe_recursive_function(5); // Start recursion with an initial depth of 5
    printf("Safe recursive function finished.\n");
    return 0; // Indicate successful execution
}
