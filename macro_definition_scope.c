/*
 * Purpose: Demonstrates definition and usage of simple macro in C.
 * Topic: Preprocessor Directives, Macros
 */

#include <stdio.h>

// Define macro 'x' with value of 2
// Macros are simple text substitutions performed by preprocessor
#define x 2

// Function 'f' that prints value of macro 'x'
// Preprocessor replaces 'x' with '2' before compilation
void f() {
    printf("%d\n", x);
}

int main(void) {
    // Call function 'f', which will print value of 'x'
    f();

    // Print value of macro 'x' directly in main
    // Preprocessor replaces 'x' with '2' here as well
    printf("%d", x);

    return 0;
}
