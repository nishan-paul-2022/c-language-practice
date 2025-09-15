/*
 * Purpose: Demonstrates reading a string and a character safely.
 * Topic: String input, character input, input buffer handling
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(void) {
    char input_string[BUFFER_SIZE];
    char input_char;

    printf("Enter a string: ");
    if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input string.\n");
        return 0;
    }
    input_string[strcspn(input_string, "\n")] = 0;

    printf("Enter a character: ");
    if (scanf(" %c", &input_char) != 1) {
        printf("Error reading input character.\n");
        return 0;
    }
    while (getchar() != '\n');

    printf("\n--- Input Results ---\n");
    printf("String entered: %s\n", input_string);
    printf("Character entered: %c\n", input_char);

    printf("\nEnter another string: ");
    if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading second input string.\n");
        return 0;
    }
    input_string[strcspn(input_string, "\n")] = 0;

    printf("Second string entered: %s\n", input_string);

    return 0;
}
