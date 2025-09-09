/*
 * Purpose: Demonstrates pointer arithmetic with various data types, showing how incrementing
 * a pointer moves it forward by the size of its base type.
 * Topic: Pointers, Pointer Arithmetic, Data Types, Memory Addresses
 */

#include <stdio.h>

int main(void) {
    // Declare variables of different data types.
    short int short_var;
    int int_var;
    long int long_var;
    long long long_long_var;
    char char_var;
    float float_var;
    double double_var;
    long double long_double_var;

    // Declare corresponding pointers and initialize them with the addresses of the variables.
    short int *ptr_to_short = &short_var;
    int *ptr_to_int = &int_var;
    long int *ptr_to_long = &long_var;
    long long *ptr_to_long_long = &long_long_var;
    char *ptr_to_char = &char_var;
    float *ptr_to_float = &float_var;
    double *ptr_to_double = &double_var;
    long double *ptr_to_long_double = &long_double_var;

    // Print the initial addresses of the pointers.
    // Using %p for printing addresses, and casting to (void *) for compatibility.
    printf("Initial addresses:\\n");
    printf("ptr_to_short: %p (size: %zu)\\n", (void *)ptr_to_short, sizeof(short int));
    printf("ptr_to_int: %p (size: %zu)\\n", (void *)ptr_to_int, sizeof(int));
    printf("ptr_to_long: %p (size: %zu)\\n", (void *)ptr_to_long, sizeof(long int));
    printf("ptr_to_long_long: %p (size: %zu)\\n", (void *)ptr_to_long_long, sizeof(long long));
    printf("ptr_to_char: %p (size: %zu)\\n", (void *)ptr_to_char, sizeof(char));
    printf("ptr_to_float: %p (size: %zu)\\n", (void *)ptr_to_float, sizeof(float));
    printf("ptr_to_double: %p (size: %zu)\\n", (void *)ptr_to_double, sizeof(double));
    printf("ptr_to_long_double: %p (size: %zu)\\n", (void *)ptr_to_long_double, sizeof(long double));
    printf("\\n");

    // Increment each pointer. The increment is by the size of the data type it points to.
    ptr_to_short++;
    ptr_to_int++;
    ptr_to_long++;
    ptr_to_long_long++;
    ptr_to_char++;
    ptr_to_float++;
    ptr_to_double++;
    ptr_to_long_double++;

    // Print the addresses after incrementing.
    // The difference between consecutive addresses should correspond to the size of the data type.
    printf("Addresses after incrementing each pointer:\\n");
    printf("ptr_to_short: %p\\n", (void *)ptr_to_short);
    printf("ptr_to_int: %p\\n", (void *)ptr_to_int);
    printf("ptr_to_long: %p\\n", (void *)ptr_to_long);
    printf("ptr_to_long_long: %p\\n", (void *)ptr_to_long_long);
    printf("ptr_to_char: %p\\n", (void *)ptr_to_char);
    printf("ptr_to_float: %p\\n", (void *)ptr_to_float);
    printf("ptr_to_double: %p\\n", (void *)ptr_to_double);
    printf("ptr_to_long_double: %p\\n", (void *)ptr_to_long_double);

    return 0;
}
