/*
 * Purpose: Demonstrates definition and usage of simple macro in C.
 * Topic: Preprocessor Directives, Macros
 */

#include <stdio.h>

#define X 2

void print_macro_value(void) {
    printf("%d\n", X);
}

int main(void) {
    print_macro_value();
    printf("%d", X);

    return 0;
}
