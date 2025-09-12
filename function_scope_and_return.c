/*
 * Purpose: Demonstrates variable scope (local vs. function-local) and how to capture and use a function's return value.
 * Topic: Functions, Scope, Return Values, Basic Output
 */

#include <stdio.h>
#include <stdlib.h>

// Demonstrates that local variables in different scopes don't interfere
int get_fixed_value() {
    int local_value = 20; // Local to this function
    return local_value;
}

int main(void) {
    int local_value = 10; // Local to main
    int function_result;

    // Display local_value in main before function call
    printf("Value of local_value in main (before function call): %d\n", local_value);

    // Call function and capture return value
    function_result = get_fixed_value();

    // Display local_value in main after function call
    printf("Value of local_value in main (after function call): %d\n", local_value);

    // Display value returned by function
    printf("Value returned by get_fixed_value(): %d\n", function_result);

    return 0;
}
