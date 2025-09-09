/*
 * Purpose: Demonstrates character conversion to uppercase and lowercase, and retrieving ASCII values using ctype.h functions.
 * Topic: Character Manipulation, ctype.h Functions, ASCII Values
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    char input_char1, input_char2; // Characters to read from input
    char upper_char, lower_char;   // Characters after conversion
    int ascii_val1, ascii_val_upper, ascii_val2, ascii_val_lower; // ASCII values

    // Prompt user for input
    printf("Enter two characters: ");

    // Read the first character
    input_char1 = getchar();
    // Read the second character
    input_char2 = getchar();

    // Convert the first character to uppercase
    upper_char = toupper(input_char1);
    // Convert the first character to lowercase
    lower_char = tolower(input_char1);

    // Get ASCII values
    ascii_val1 = toascii(input_char1);       // ASCII value of the first input character
    ascii_val_upper = toascii(upper_char);   // ASCII value of the uppercase version of the first character
    ascii_val2 = toascii(input_char2);       // ASCII value of the second input character
    ascii_val_lower = toascii(lower_char);   // ASCII value of the lowercase version of the first character

    // Print the converted characters
    printf("Uppercase of first char: %c\n", upper_char);
    printf("Lowercase of first char: %c\n", lower_char);

    // Print the ASCII values
    printf("ASCII values: Original1=%d, Upper1=%d, Original2=%d, Lower1=%d\n",
           ascii_val1, ascii_val_upper, ascii_val2, ascii_val_lower);

    return 0;
}
