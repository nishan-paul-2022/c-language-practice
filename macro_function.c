/*
 * Purpose: Demonstrates use of macros with arguments and ternary operator.
 * Topic: Preprocessor Directives, Macros with Arguments, Ternary Operator
 */

#include <stdio.h>

#define PRINT_FLOAT(i) printf("%.2f\n", (double)(i))
#define PRINT_SQUARED_FLOAT(i) printf("%.2f\n", (double)(i) * (double)(i))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
    PRINT_FLOAT(2.6);
    PRINT_SQUARED_FLOAT(3.8);
    PRINT_FLOAT(MAX(30.56, 30.89));

    return 0;
}
