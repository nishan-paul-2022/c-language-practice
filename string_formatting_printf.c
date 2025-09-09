/*
 * Purpose: Demonstrates string formatting using printf with width and precision specifiers.
 * Topic: String Formatting, Input/Output
 */

#include <stdio.h>

int main(void) {
    // Define a string with some spaces.
    char str[] = "NISHAN  PAUL";

    // Print the string using printf with format specifiers:
    // %2s: Pad with spaces on the left to a minimum width of 2 characters.
    // .100s: Truncate the string to a maximum of 100 characters (if it were longer).
    // Since the string is shorter than 100 characters, it will be padded to the width specified by '2'.
    // The actual output will be the string "NISHAN  PAUL" padded with spaces to a total width of 100 characters.
    printf("%2.100s\n", str);

    return 0;
}
