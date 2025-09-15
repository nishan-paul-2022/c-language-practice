/*
 * Purpose: Demonstrates string formatting using printf with width and precision.
 * Topic: String Formatting
 */

#include <stdio.h>

int main(void) {
    char str[] = "UC Berkeley";

    // Print the string with minimum width 2 and max precision 100
    printf("%2.100s\n", str);

    return 0;
}
