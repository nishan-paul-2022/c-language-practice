/*
 * Purpose: Demonstrates variable scope (local vs. function-local) and how to capture and use a function's return value.
 * Topic: Functions, Scope, Return Values, Basic Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function that returns a fixed integer value.
// It defines its own local variable, demonstrating that it does not affect
// variables with the same name in other scopes.
int get_fixed_value() {
    int local_value = 20; // A local variable within this function
    return local_value;
}

int main() {
    int local_value = 10; // A local variable within main
    int function_result;

    // Display the value of the local variable in main
    printf("Value of local_value in main (before function call): %d\n", local_value);

    // Call the function and capture its return value in function_result
    function_result = get_fixed_value();

    // Display the value of the local variable in main again
    // It remains unchanged because the function operated on its own local variable
    // and did not modify main's local_value
    printf("Value of local_value in main (after function call): %d\n", local_value);

    // Display the value returned by the function
    printf("Value returned by get_fixed_value(): %d\n", function_result);

    return 0;
}
