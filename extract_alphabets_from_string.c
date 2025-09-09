/*
 * Purpose: Reads a line of text and prints only the lowercase alphabet characters from it.
 * Topic: String Manipulation, Loops, Character Handling (ctype.h)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_string[100]; // Buffer to store the input string
    int i;

    // Prompt user for input and read the entire line safely
    printf("Enter a string (e.g., 'Hello World 123!'): ");
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    // Remove the trailing newline character if fgets read it
    input_string[strcspn(input_string, "\n")] = '\0';

    printf("Extracted lowercase alphabets: ");
    // Iterate through each character in the string
    for (i = 0; input_string[i] != '\0'; i++) {
        char current_char = input_string[i];
        char lower_char = tolower(current_char); // Convert to lowercase

        // Check if the character is a lowercase alphabet
        if (lower_char >= 'a' && lower_char <= 'z') {
            printf("%c", lower_char); // Print the lowercase alphabet character
        }
    }
    printf("\n");

    return 0;
}
