#include <stdio.h> // For printf() and size_t

/*
 * Purpose: Demonstrates the use of the sizeof operator to find the memory size of various data types.
 * Topic: Data Types, Memory Management, sizeof Operator
 */
int main(void) {
    // Declare variables of different integer types
    short int short_var;
    int int_var;
    long int long_var;
    unsigned long long int ull_var;

    // Print the sizes of these data types using the sizeof operator.
    // %zu is the correct format specifier for size_t, which is the return type of sizeof.
    printf("Size of short int: %zu bytes\n", sizeof(short_var));
    printf("Size of int: %zu bytes\n", sizeof(int_var));
    printf("Size of long int: %zu bytes\n", sizeof(long_var));
    printf("Size of unsigned long long int: %zu bytes\n", sizeof(ull_var));

    return 0;
}
