/*
 * Purpose: Demonstrates behavior of logical AND (&&) operator in C.
 * Topic: Operators (Relational, Logical)
 */

#include <stdio.h>

int evaluate_logical_expression(void) {
    return 5 >= 8 && 6 == 5; // false && false = false
}

void display_result(int result) {
    printf("The result of (5 >= 8 && 6 == 5) is: %d\n", result);
}

int main(void) {
    int result;

    result = evaluate_logical_expression();
    display_result(result);

    return 0;
}
