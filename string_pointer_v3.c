/*
 * Purpose: Demonstrates string manipulation using pointers and the strrev function.
 * Topic: Pointers, Strings, String Manipulation
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[100] = "BANGLADESH";
    char *ptr = str; // Pointer to first character

    printf("Original string: %s\n", ptr);
    printf("Substring from 2nd char: %s\n", ptr + 1);
    printf("Substring from 3rd char: %s\n", ptr + 2);

    // Reverse string and print substring starting from 4th char of reversed string
    printf("Reversed substring from 4th char: %s\n", strrev(strrev(str) + 3));

    return 0;
}
