/*
 * Purpose: Demonstrates variable scope (local vs. function-local) and how to capture and use a function's return value.
 * Topic: Functions, Scope, Return Values, Basic Output
 */

#include <stdio.h>

int get_fixed_value() {
    int local_value = 20;
    return local_value;
}

int main(void) {
    int local_value = 10;
    int function_result;

    printf("Value of local_value in main (before function call): %d\n", local_value);

    function_result = get_fixed_value();

    printf("Value of local_value in main (after function call): %d\n", local_value);
    printf("Value returned by get_fixed_value(): %d\n", function_result);

    return 0;
}
