/*
 * Purpose: Demonstrates behavior of logical AND (&&) operator in C.
 * Topic: Operators (Relational, Logical)
 */

#include <stdio.h>

int main() {
    int result; // Variable to store boolean result of logical expression

    // Evaluate logical expression: (5 >= 8) && (6 == 5)
    // (5 >= 8) is false (0)
    // (6 == 5) is false (0)
    // false && false evaluates to false (0)
    result = 5 >= 8 && 6 == 5;

    // Print integer value of result (0 for false, 1 for true)
    printf("The result of (5 >= 8 && 6 == 5) is: %d\n", result);

    return 0;
}
