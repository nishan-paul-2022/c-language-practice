/*
 * Purpose: Determines and prints the type of a single character input by the user
 *          (uppercase, lowercase, digit, punctuation, or whitespace).
 * Topic: Character Manipulation, Conditional Statements (if-else if), Input/Output
 */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    printf("Enter a single character to check its type: ");
    char input_char = getchar();

    if (isalpha(input_char)) {
        if (isupper(input_char)) {
            printf("UPPER CASE LETTER\n");
        } else {
            printf("LOWER CASE LETTER\n");
        }
    } else if (isdigit(input_char)) {
        printf("DIGIT\n");
    } else if (ispunct(input_char)) {
        printf("PUNCTUATION MARK\n");
    } else if (isspace(input_char)) {
        printf("WHITE SPACE\n");
    } else {
        printf("OTHER CHARACTER\n");
    }

    return 0;
}
