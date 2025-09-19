/*
 * Purpose: Demonstrates character conversion to uppercase and lowercase, and retrieving ASCII values using ctype.h functions.
 * Topic: Character Manipulation, ctype.h Functions, ASCII Values
 */

#include <stdio.h>
#include <ctype.h>

void consume_newline(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void lowercase_to_uppercase() {
    printf("\nEnter any character (lowercase): ");

    char input_char = getchar();
    char upper_char = toupper(input_char);
    int input_ascii_val = toascii(input_char);
    int upper_input_ascii_val = toascii(upper_char);

    printf("Uppercase of '%c' is '%c'\n", input_char, upper_char);

    printf("ASCII values:\n");
    printf("'%c' = %d\n", input_char, input_ascii_val);
    printf("'%c' = %d\n", upper_char, upper_input_ascii_val);

    consume_newline();
}

void uppercase_to_lowercase() {
    printf("\nEnter any character (uppercase): ");

    char input_char = getchar();
    char lower_char = tolower(input_char);
    int input_ascii_val = toascii(input_char);
    int lower_ascii_val = toascii(lower_char);

    printf("Lowercase of '%c' is '%c'\n", input_char, lower_char);

    printf("ASCII values:\n");
    printf("'%c' = %d\n", input_char, input_ascii_val);
    printf("'%c' = %d\n", lower_char, lower_ascii_val);
}

int main(void) {
    lowercase_to_uppercase();
    uppercase_to_lowercase();

    return 0;
}
