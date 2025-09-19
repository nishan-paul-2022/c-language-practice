/*
 * Purpose: Demonstrates the behavior of static variables within functions.
 * Topic: Functions, Static Variables, Scope
 */

#include <stdio.h>

int increment_static_value() {
    static int counter = 10;
    counter++;
    return counter;
}

int main(void) {
    printf("=== Demonstrating static variable behavior ===\n");

    for (int i = 1; i <= 6; i++) {
        printf("Call %d: %d\n", i, increment_static_value());
    }

    return 0;
}
