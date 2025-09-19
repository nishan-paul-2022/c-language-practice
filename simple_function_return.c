/*
 * Purpose: Demonstrates a basic function that takes an integer argument, performs a calculation, and returns the result.
 * Topic: Functions, Parameters, Return Values, Basic Arithmetic
 */

#include <stdio.h>

int multiply_by_ten(int num) {
    int result = num * 10;
    return result;
}

int main(void) {
    int input_num = 4;
    int result = multiply_by_ten(input_num);

    printf("The result of 'multiplying %d by 10' is %d\n", input_num, result);

    return 0;
}
