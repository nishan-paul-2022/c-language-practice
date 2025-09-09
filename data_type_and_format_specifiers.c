#include <stdio.h>

int main() {
    // Declare variables of different data types
    short int short_int_var = 12345;          // A short integer
    long int long_int_var = 1234567891;       // A long integer
    double double_var = 123.123456789;      // A double-precision floating-point number

    // Print the values using appropriate printf format specifiers:
    // %hd: for printing a short int.
    // %ld: for printing a long int.
    // %5.9lf: for printing a double.
    //        '5' specifies a minimum field width of 5 characters.
    //        '.9' specifies a precision of 9 digits after the decimal point.
    //        'lf' is the correct specifier for 'double' with printf.
    printf("%hd %ld %5.9lf\n", short_int_var, long_int_var, double_var);

    return 0;
}
