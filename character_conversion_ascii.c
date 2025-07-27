// Purpose: Demonstrates character conversion to uppercase and lowercase, and retrieving ASCII values using ctype.h functions.
// Topic: Character Manipulation, ctype.h Functions, ASCII Values

#include <stdio.h>
#include <ctype.h> // For toupper, tolower, toascii

int main() {
    char inputChar1, inputChar2; // Characters to read from input
    char upperChar, lowerChar;   // Characters after conversion
    int asciiVal1, asciiValUpper, asciiVal2, asciiValLower; // ASCII values

    // Prompt user for input
    printf("Enter two characters: ");

    // Read the first character
    inputChar1 = getchar();
    // Read the second character
    inputChar2 = getchar();

    // Convert the first character to uppercase
    upperChar = toupper(inputChar1);
    // Convert the first character to lowercase
    lowerChar = tolower(inputChar1);

    // Get ASCII values
    asciiVal1 = toascii(inputChar1);       // ASCII value of the first input character
    asciiValUpper = toascii(upperChar);   // ASCII value of the uppercase version of the first character
    asciiVal2 = toascii(inputChar2);       // ASCII value of the second input character
    asciiValLower = toascii(lowerChar);   // ASCII value of the lowercase version of the first character

    // Print the converted characters
    printf("Uppercase of first char: %c\n", upperChar);
    printf("Lowercase of first char: %c\n", lowerChar);

    // Print the ASCII values
    printf("ASCII values: Original1=%d, Upper1=%d, Original2=%d, Lower1=%d\n",
           asciiVal1, asciiValUpper, asciiVal2, asciiValLower);

    return 0; // Indicate successful execution
}
