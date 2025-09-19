/*
 * Purpose: Demonstrates the use of the sizeof operator to determine the size of various data types.
 * Topic: Data Types, sizeof Operator
 */

#include <stdio.h>

int main(void) {
    printf("Size of various data types:\n");
    printf("The size of 'char' is: %zu bytes\n", sizeof(char));
    printf("The size of 'int' is: %zu bytes\n", sizeof(int));
    printf("The size of 'float' is: %zu bytes\n", sizeof(float));
    printf("The size of 'double' is: %zu bytes\n", sizeof(double));
    printf("The size of 'long double' is: %zu bytes\n", sizeof(long double));
    printf("The size of 'short int' is: %zu bytes\n", sizeof(short int));
    printf("The size of 'long int' is: %zu bytes\n", sizeof(long int));
    printf("The size of 'long long int' is: %zu bytes\n", sizeof(long long int));
    
    return 0;
}
