/*
 * Purpose: Demonstrates definition and usage of simple macro.
 * Topic: Preprocessor Directives, Macros
 */

#include <stdio.h>

#define X 2

void print_macro_value() {
    printf("%d\n", X);
}

int main(void) {
    print_macro_value();
    
    printf("%d\n", X);

    return 0;
}
