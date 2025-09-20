/*
 * Purpose: Demonstrates how to fix infinite recursion by adding a base case.
 * Topic: Recursion, Base Case, Function Calls
 */

#include <stdio.h>

void safe_recursive_function(int depth) {
    if (depth <= 0) {
        printf("Recursion depth reached zero. Stopping.\n");
        return;
    }

    printf("Calling recursively with depth: %d\n", depth);

    safe_recursive_function(depth - 1);

    printf("Returning from depth: %d\n", depth);
}

int main(void) {
    printf("Starting safe recursive function...\n");

    safe_recursive_function(5);

    printf("Safe recursive function finished.\n");
    
    return 0;
}
