/*
 * Purpose: Demonstrates the lifetime and behavior of static variables in C functions.
 * Topic: Variables, Scope, Lifetime, Static Keyword
 */

#include <stdio.h>

void demonstrate_static_variable(void) {
    int local_var = 10;
    static int static_var = 10;

    local_var++;
    static_var++;

    printf("Local variable: %d, Static variable: %d\n", local_var, static_var);
}

int main(void) {
    printf("Demonstrating static variable behavior:\n");

    for (int i = 0; i < 4; i++) {
        demonstrate_static_variable();
    }

    return 0;
}
