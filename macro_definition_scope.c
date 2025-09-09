/*
 * Purpose: Demonstrates the definition and usage of a simple macro in C.
 * Topic: Preprocessor Directives, Macros
 */

#include <stdio.h>

// Define a macro 'x' with a value of 2.
// Macros are simple text substitutions performed by the preprocessor.
#define x 2

// Function 'f' that prints the value of the macro 'x'.
// The preprocessor replaces 'x' with '2' before compilation.
void f() {
    printf("%d\n", x);
}

int main() {
    // Call function 'f', which will print the value of 'x'.
    f();

    // Print the value of macro 'x' directly in main.
    // The preprocessor replaces 'x' with '2' here as well.
    printf("%d", x);

    return 0;
}
