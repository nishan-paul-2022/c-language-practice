#include <stdio.h>

int main(void) {
    // Declare variables of different data types
    short int short_int_var = 12345;          // A short integer
    long int long_int_var = 1234567891;       // A long integer
    double double_var = 123.123456789;       // A double-precision floating-point number

    // Print the values using appropriate printf format specifiers
    // %hd: format specifier for short int
    // %ld: format specifier for long int
    // %5.9lf: format specifier for double with width 5 and 9 decimal places
    printf("%hd %ld %5.9lf\n", short_int_var, long_int_var, double_var);

    return 0;
}
