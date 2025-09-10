/*
 * Purpose: Converts alphabetic characters in a string to their corresponding digits on a phone keypad.
 * Topic: Strings, Character Manipulation, Conditional Statements (if-else if), Loops, Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char title[] = "Enter an alphanumeric string (max 30 chars, containing A-Z).\n";
    char input_string[31]; // Increased size to 31 for null terminator, original was 30
    int i;

    printf("%s", title);

    // Read input until EOF or invalid input
    while (scanf("%30[A-Z0-1-]s", input_string) == 1) { // Read up to 30 characters matching the set
        // Consume the rest of the line, including the newline character
        // This is important if the input string was shorter than 30 chars or if there were other characters after the valid ones.
        int c;

        while ((c = getchar()) != '\n' && c != EOF);

        int length = strlen(input_string);

        for (i = 0; i < length; i++) {
            char current_char = input_string[i];

            if (current_char >= 'A' && current_char <= 'C') {
                input_string[i] = '2';
            }
            else if (current_char >= 'D' && current_char <= 'F') {
                input_string[i] = '3';
            }
            else if (current_char >= 'G' && current_char <= 'I') {
                input_string[i] = '4';
            }
            else if (current_char >= 'J' && current_char <= 'L') {
                input_string[i] = '5';
            }
            else if (current_char >= 'M' && current_char <= 'O') {
                input_string[i] = '6';
            }
            else if (current_char >= 'P' && current_char <= 'S') {
                input_string[i] = '7';
            }
            else if (current_char >= 'T' && current_char <= 'V') {
                input_string[i] = '8';
            }
            else if (current_char >= 'W' && current_char <= 'Z') {
                input_string[i] = '9';
            }
        }

        printf("Converted: %s\n\n", input_string);
        printf("%s", title);
    }

    printf("\nExiting program.\n");
    return 0;
}
