/*
 * Purpose: Demonstrates reading a string and a character safely.
 * Topic: String input, character input, input buffer handling
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void clear_input_buffer() {
    while (getchar() != '\n');
}

int read_string_input(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        printf("\nError reading input string.\n");
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = 0;

    return 0;
}

int read_character_input(const char *prompt, char *ch) {
    printf("%s", prompt);

    if (scanf(" %c", ch) != 1) {
        printf("\nError reading input character.\n");
        return -1;
    }

    clear_input_buffer();
    
    return 0;
}

void display_results(const char *string, char character) {
    printf("\n--- Input Results ---\n");
    printf("String entered: %s\n", string);
    printf("Character entered: %c\n", character);
}

int main(void) {
    char input_string[BUFFER_SIZE];
    char input_char;

    if (read_string_input("Enter a string: ", input_string, BUFFER_SIZE) == -1) {
        return 0;
    }

    if (read_character_input("Enter a character: ", &input_char) == -1) {
        return 0;
    }

    display_results(input_string, input_char);

    if (read_string_input("\nEnter 2nd string: ", input_string, BUFFER_SIZE) == -1) {
        return 0;
    }

    printf("String entered (2nd): %s\n", input_string);

    return 0;
}
