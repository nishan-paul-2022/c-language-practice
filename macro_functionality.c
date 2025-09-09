// Purpose: Demonstrates the use of macros with arguments and the ternary operator.
// Topic: Preprocessor Directives, Macros with Arguments, Ternary Operator

#include <stdio.h> // Required for printf()

// Macro 'x' takes one argument 'i' and prints it as a float.
#define PRINT_FLOAT(i) printf("%f\n", (double)(i))

// Macro 'y' takes one argument 'i', squares it, and prints the result as a float.
// It's good practice to enclose macro arguments in parentheses to avoid side effects.
#define PRINT_SQUARED_FLOAT(i) printf("%f\n", (double)(i) * (double)(i))

// Macro 'z' takes two arguments 'a' and 'b' and returns the larger one using the ternary operator.
// Parentheses around the entire expression and arguments are crucial for correct expansion.
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    // Call macro 'PRINT_FLOAT' with a float literal.
    PRINT_FLOAT(2.6);

    // Call macro 'PRINT_SQUARED_FLOAT' with a float literal.
    PRINT_SQUARED_FLOAT(3.8);

    // Call macro 'PRINT_FLOAT' with the result of macro 'MAX'.
    // Macro 'MAX' finds the larger of 30.56 and 30.89, which is 30.89.
    // Then PRINT_FLOAT prints this value.
    PRINT_FLOAT(MAX(30.56, 30.89));

    return 0;
}
