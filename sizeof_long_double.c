/*
 * Purpose: Demonstrates how to determine the size of a long double data type.
 * Topic: Pointers, Data Types, Sizeof Operator
 */

#include <stdio.h>
#include <stddef.h>

void print_sizeof_long_double(long double *ptr) {
    ptrdiff_t diff = (char*)ptr + sizeof(long double) - (char*)ptr;
    printf("The size of 'long double' is: %td bytes\n", diff);
}

int main(void) {
    long double sample;
    print_sizeof_long_double(&sample);
    return 0;
}
