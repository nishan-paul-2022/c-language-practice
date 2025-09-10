/*
 * Purpose: Determines and prints the type of a single character input by the user
 *          (uppercase, lowercase, digit, punctuation, or whitespace).
 * Topic: Character Manipulation, Conditional Statements (if-else if), Input/Output
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    char input_char;

    printf("Enter a single character: ");
    // Read character from standard input
    input_char = getchar();

    // Determine character type using ctype.h functions
    if (isalpha(input_char)) { // Alphabet character
        if (isupper(input_char)) { // Uppercase letter
            printf("UPPER CASE\n");
        } else { // Lowercase letter
            printf("LOWER CASE\n");
        }
    } else if (isdigit(input_char)) { // Digit (0-9)
        printf("DIGIT\n");
    } else if (ispunct(input_char)) { // Punctuation character
        printf("PUNCTUATION MARK\n");
    } else if (isspace(input_char)) { // Whitespace character
        printf("WHITE SPACE\n");
    } else {
        printf("OTHER CHARACTER\n"); // Other character types
    }

    return 0;
}