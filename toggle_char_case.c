#include <stdio.h>
#include <ctype.h>

int main() {
    char input_char; // Variable to store the input character

    // Read a single character from standard input
    input_char = getchar();

    // Check if the character is lowercase
    if (islower(input_char)) {
        // If it's lowercase, convert it to uppercase and print
        putchar(toupper(input_char));
    } else {
        // If it's not lowercase (i.e., uppercase or other character),
        // convert it to lowercase and print.
        // Note: tolower() on non-alphabetic characters usually returns the character unchanged.
        putchar(tolower(input_char));
    }

    // A newline character is often printed after the output for better formatting in terminals
    // but the original code did not include this, so I will omit it to stay true to the original behavior.
    // If desired, one could add: putchar('\n');

    return 0;
}
