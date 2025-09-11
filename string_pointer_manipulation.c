/*
 * Purpose: Demonstrates string manipulation using pointers and the strrev function.
 * Topic: Pointers, Strings, String Manipulation
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100] = "BANGLADESH"; // Declare and initialize a character array (string)
    char *str_ptr;                // Declare a pointer to a character

    // Assign the base address of the string to the pointer.
    // 'str' decays to a pointer to its first element ('B').
    str_ptr = str;

    // Print substrings starting from different positions using pointer arithmetic.
    // %s format specifier prints a null-terminated string.
    // str_ptr points to the start of "BANGLADESH".
    // (str_ptr + 1) points to the second character ('A'), so it prints "ANGLADESH".
    // (str_ptr + 2) points to the third character ('N'), so it prints "NGLADESH".
    printf("Original string: %s\n", str_ptr);
    printf("Substring starting from 2nd char: %s\n", (str_ptr + 1));
    printf("Substring starting from 3rd char: %s\n", (str_ptr + 2));

    // Demonstrate string reversal and substring operation.
    // 1. strrev(str) reverses "BANGLADESH" to "HCSELGNA B".
    // 2. strrev(str) + 3 points to the 4th character of the reversed string ("ELGNA B").
    // 3. The outer strrev reverses this substring "ELGNA B" to "B ANGLE".
    // Note: The original string 'str' is modified by the first strrev call.
    printf("Reversed string starting from 4th char of reversed string: %s\n", strrev(strrev(str) + 3));

    return 0;
}
