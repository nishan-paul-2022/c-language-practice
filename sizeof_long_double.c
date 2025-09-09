/*
 * Purpose: Demonstrates how to determine the size of a long double data type.
 * Topic: Pointers, Data Types, Sizeof Operator, Type Casting
 */

#include <stdio.h>
#include <stddef.h> // For ptrdiff_t

// Function to calculate and print the size of a long double
void print_sizeof_long_double(long double *ptr) {
    // Use ptrdiff_t to store the difference between two pointers.
    // Adding 1 to a pointer moves it by the size of the data type it points to.
    // Casting to char* ensures we are dealing with byte differences.
    ptrdiff_t diff = (char*)ptr + sizeof(long double) - (char*)ptr;

    printf("The size of a long double on this system is: %td bytes\n", diff);
}

int main() {
    long double sample_value; // A sample variable of type long double

    printf("Calculating the size of long double...\n");
    print_sizeof_long_double(&sample_value); // Pass the address of the sample variable

    return 0;
}
