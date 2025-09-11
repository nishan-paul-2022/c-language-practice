/*
 * Purpose: Demonstrates the use of the sizeof operator to determine the size of the float data type.
 * Topic: Data Types, sizeof Operator
 */

#include <stdio.h>

int main(void) {
    // Print the size of the float data type in bytes
    printf("The size of the 'float' data type is: %zu bytes\n", sizeof(float));
    // Using %zu for sizeof result is good practice as sizeof returns size_t

    return 0;
}
