/*
 * Purpose: Demonstrates the use of the sizeof operator to find the memory size of various data types.
 * Topic: Data Types, Memory Management, sizeof Operator, Functions
 */

#include <stdio.h>

// Displays the memory size of character types
void display_char_type_sizes() {
    printf("--- Character Types ---\n");
    printf("Size of char: %zu byte(s)\n", sizeof(char));
    printf("Size of signed char: %zu byte(s)\n", sizeof(signed char));
    printf("Size of unsigned char: %zu byte(s)\n\n", sizeof(unsigned char));
}

// Displays the memory size of integer types
void display_integer_type_sizes() {
    printf("--- Integer Types ---\n");
    printf("Size of short int: %zu byte(s)\n", sizeof(short int));
    printf("Size of unsigned short int: %zu byte(s)\n", sizeof(unsigned short int));
    printf("Size of int: %zu byte(s)\n", sizeof(int));
    printf("Size of unsigned int: %zu byte(s)\n", sizeof(unsigned int));
    printf("Size of long int: %zu byte(s)\n", sizeof(long int));
    printf("Size of unsigned long int: %zu byte(s)\n", sizeof(unsigned long int));
    printf("Size of long long int: %zu byte(s)\n", sizeof(long long int));
    printf("Size of unsigned long long int: %zu byte(s)\n\n", sizeof(unsigned long long int));
}

// Displays the memory size of floating-point types
void display_floating_point_type_sizes() {
    printf("--- Floating-Point Types ---\n");
    printf("Size of float: %zu byte(s)\n", sizeof(float));
    printf("Size of double: %zu byte(s)\n", sizeof(double));
    printf("Size of long double: %zu byte(s)\n\n", sizeof(long double));
}

// Displays the memory size of pointer types
void display_pointer_type_sizes() {
    printf("--- Pointer Types ---\n");
    printf("Size of char pointer: %zu byte(s)\n", sizeof(char*));
    printf("Size of int pointer: %zu byte(s)\n", sizeof(int*));
    printf("Size of double pointer: %zu byte(s)\n", sizeof(double*));
}

int main(void) {
    printf("--- Memory Size of C Data Types ---\n\n");
    display_char_type_sizes();
    display_integer_type_sizes();
    display_floating_point_type_sizes();
    display_pointer_type_sizes();
    return 0;
}