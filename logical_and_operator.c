/*
 * Purpose: Demonstrates the behavior of the logical AND (&&) operator in C.
 * Topic: Operators (Relational, Logical)
 */

#include <stdio.h> // Required for printf

int main() {
    int result; // Variable to store the boolean result of the logical expression

    // Evaluate the logical expression: (5 >= 8) && (6 == 5)
    // (5 >= 8) is false (0)
    // (6 == 5) is false (0)
    // false && false evaluates to false (0)
    result = 5 >= 8 && 6 == 5;

    // Print the integer value of the result (0 for false, 1 for true)
    printf("The result of (5 >= 8 && 6 == 5) is: %d\n", result);

    return 0; // Indicate successful execution
}
