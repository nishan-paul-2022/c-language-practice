/*
 * Purpose: Converts alphabetic characters in a string to their corresponding digits on a phone keypad.
 * Topic: Strings, Character Manipulation, Conditional Statements (if-else if), Loops, Input/Output
 */

#include <stdio.h>
#include <string.h> // For strlen()
#include <ctype.h> // For isalpha(), isdigit()

int main()
{
    char title[] = "Enter an alphanumeric string (max 30 chars, containing A-Z).\n";
    char inputString[31]; // Increased size to 31 for null terminator, original was 30
    int i;

    printf("%s", title);

    // Read input until EOF or invalid input
    while (scanf("%30[A-Z0-1-]s", inputString) == 1) { // Read up to 30 characters matching the set
        // Consume the rest of the line, including the newline character
        // This is important if the input string was shorter than 30 chars or if there were other characters after the valid ones.
        int c;

        while ((c = getchar()) != '\n' && c != EOF);

        int length = strlen(inputString);

        for (i = 0; i < length; i++) {
            char currentChar = inputString[i];

            if (currentChar >= 'A' && currentChar <= 'C') {
                inputString[i] = '2';
            }
            else if (currentChar >= 'D' && currentChar <= 'F') {
                inputString[i] = '3';
            }
            else if (currentChar >= 'G' && currentChar <= 'I') {
                inputString[i] = '4';
            }
            else if (currentChar >= 'J' && currentChar <= 'L') {
                inputString[i] = '5';
            }
            else if (currentChar >= 'M' && currentChar <= 'O') {
                inputString[i] = '6';
            }
            else if (currentChar >= 'P' && currentChar <= 'S') {
                inputString[i] = '7';
            }
            else if (currentChar >= 'T' && currentChar <= 'V') {
                inputString[i] = '8';
            }
            else if (currentChar >= 'W' && currentChar <= 'Z') {
                inputString[i] = '9';
            }
        }

        printf("Converted: %s\n\n", inputString);
        printf("%s", title);
    }

    printf("\nExiting program.\n");
    return 0;
}
