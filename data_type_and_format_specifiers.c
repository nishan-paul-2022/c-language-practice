/*
 * Purpose: Demonstrates the use of various C data types and their corresponding printf format specifiers.
 * Topic: Data Types, Format Specifiers, Functions
 */

#include <stdio.h>

void display_char_types() {
    char char_var = 'A';
    signed char signed_char_var = -10;
    unsigned char unsigned_char_var = 250;

    printf("--- Character Types ---\n");
    printf("char: '%c'\n", char_var);
    printf("signed char: %d\n", signed_char_var);
    printf("unsigned char: %u\n\n", unsigned_char_var);
}

void display_integer_types() {
    short int short_int_var = 32767;
    unsigned short int unsigned_short_int_var = 65535;
    int int_var = 2147483647;
    unsigned int unsigned_int_var = 4294967295U;
    long int long_int_var = 2147483647L;
    unsigned long int unsigned_long_int_var = 4294967295UL;
    long long int long_long_int_var = 9223372036854775807LL;
    unsigned long long int unsigned_long_long_int_var = 18446744073709551615ULL;

    printf("--- Integer Types ---\n");
    printf("short int: %hd\n", short_int_var);
    printf("unsigned short int: %hu\n", unsigned_short_int_var);
    printf("int: %d\n", int_var);
    printf("unsigned int: %u\n", unsigned_int_var);
    printf("long int: %ld\n", long_int_var);
    printf("unsigned long int: %lu\n", unsigned_long_int_var);
    printf("long long int: %lld\n", long_long_int_var);
    printf("unsigned long long int: %llu\n\n", unsigned_long_long_int_var);
}

void display_floating_point_types() {
    float float_var = 3.14159f;
    double double_var = 3.141592653589793;
    long double long_double_var = 3.14159265358979323846L;

    printf("--- Floating-Point Types ---\n");
    printf("float: %f\n", float_var);
    printf("double: %lf\n", double_var);
    printf("long double: %Lf\n", long_double_var);
}

int main(void) {
    display_char_types();
    display_integer_types();
    display_floating_point_types();
    return 0;
}