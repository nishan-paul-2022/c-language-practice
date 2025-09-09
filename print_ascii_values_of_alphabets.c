/*
 * Purpose: Prints the ASCII (or integer) values of lowercase English alphabets from 'a' to 'z'.
 * Topic: Loops, Character Handling, ASCII Values
 */

#include <stdio.h>

int main() {
    int char_code; // Loop variable to iterate through character codes

    // Loop from 'a' to 'z'. In C, characters are internally represented by their ASCII values,
    // so arithmetic operations on characters work based on these integer values.
    for (char_code = 'a'; char_code <= 'z'; char_code++) {
        // Print the integer (ASCII) value of the current character
        printf("Character '%c' has ASCII value: %d\n", (char)char_code, char_code);
    }

    return 0;
}
