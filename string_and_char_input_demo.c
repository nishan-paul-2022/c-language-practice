// Purpose: Demonstrates reading a string and a character using scanf and fgets.
// Topic: String input, character input, input buffer handling.

#include <stdio.h>
#include <string.h> // For strcspn
#include <stdlib.h> // For exit()

#define BUFFER_SIZE 256 // Define a reasonable buffer size for input strings

int main(void) {
    char input_string[BUFFER_SIZE];
    char input_char;

    printf("Enter a string followed by a character (e.g., 'hello world!'):\\n");

    // Use scanf to read a string (%s stops at whitespace) and then a character (%c).
    // The %c format specifier in scanf will consume any whitespace characters
    // (including newlines) before reading the actual character.
    // If the input is "hello world!", scanf("%s", input_string) reads "hello".
    // Then, scanf("%c", &input_char) would read the space character.
    // If the input is "hello\nworld!", scanf("%s", input_string) reads "hello".
    // The newline after "hello" is still in the buffer.
    // Then, scanf("%c", &input_char) would read that newline.
    // To correctly read the character after the string, we need to be careful.
    // A common pattern is to consume leading whitespace for %c.
    // Let's try reading the string first, then the character.

    printf("Enter a string: ");
    if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input string.\\n");
        return 1;
    }
    // Remove trailing newline from fgets
    input_string[strcspn(input_string, "\\n")] = 0;

    printf("Enter a character: ");
    // Read the character. The space before %c in scanf("%c", ...) is important
    // to consume any leftover whitespace (like the newline from previous input)
    // before reading the actual character.
    if (scanf(" %c", &input_char) != 1) { // Note the space before %c
        printf("Error reading input character.\\n");
        return 1;
    }

    // Consume any remaining characters on the line after the character, including the newline
    while (getchar() != '\\n');

    printf("\\n--- Input Results ---\\n");
    printf("String entered: %s\\n", input_string);
    printf("Character entered: %c\\n", input_char);

    // Demonstrate reading a string again using fgets for safety
    printf("\\nEnter another string: ");
    if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading second input string.\\n");
        return 1;
    }
    input_string[strcspn(input_string, "\\n")] = 0;

    printf("Second string entered: %s\\n", input_string);

    return 0; // Indicate successful execution
}
