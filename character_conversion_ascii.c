/*
 * Purpose: Demonstrates character conversion to uppercase and lowercase, and retrieving ASCII values using ctype.h functions.
 * Topic: Character Manipulation, ctype.h Functions, ASCII Values
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    char input_char1, input_char2; // Input characters
    char upper_char, lower_char;   // Converted characters
    int ascii_val1, ascii_val_upper, ascii_val2, ascii_val_lower; // ASCII values

    // Get user input
    printf("Enter two characters (e.g., 'a' and 'B'): ");
    input_char1 = getchar();
    input_char2 = getchar();

    // Convert first character
    upper_char = toupper(input_char1);
    lower_char = tolower(input_char1);

    // Get ASCII values
    ascii_val1 = toascii(input_char1);       // First input character
    ascii_val_upper = toascii(upper_char);   // Uppercase version
    ascii_val2 = toascii(input_char2);       // Second input character
    ascii_val_lower = toascii(lower_char);   // Lowercase version

    // Print converted characters
    printf("Uppercase of '%c' is '%c'\n", input_char1, upper_char);
    printf("Lowercase of '%c' is '%c'\n", input_char1, lower_char);

    // Print ASCII values
    printf("ASCII values:\n");
    printf("  '%c' = %d\n", input_char1, ascii_val1);
    printf("  '%c' = %d\n", upper_char, ascii_val_upper);
    printf("  '%c' = %d\n", input_char2, ascii_val2);
    printf("  '%c' = %d\n", lower_char, ascii_val_lower);

    return 0;
}
