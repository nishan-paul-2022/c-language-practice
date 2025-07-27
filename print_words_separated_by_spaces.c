// Purpose: Demonstrates reading a string and printing words separated by spaces.
// Topic: String manipulation, input/output, loops.

#include <stdio.h>
#include <string.h> // For strlen and strcspn

#define BUFFER_SIZE 256 // Define a reasonable buffer size for input strings

int main() {
    char input_string[BUFFER_SIZE];
    int i, j;

    printf("Enter a string: ");
    // Use fgets for safe input. It reads up to BUFFER_SIZE-1 characters
    // and appends a null terminator. It also reads the newline character if space permits.
    if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\\n");
        return 1; // Indicate an error
    }

    // Remove the trailing newline character if it exists
    input_string[strcspn(input_string, "\\n")] = 0;

    printf("Words in the string:\\n");

    // Iterate through the string to print words.
    // A word is considered a sequence of characters separated by spaces or the end of the string.
    for (i = 0; input_string[i] != '\\0'; ) {
        // Skip leading spaces
        while (input_string[i] == ' ') {
            i++;
        }

        // If we reached the end of the string after skipping spaces, break
        if (input_string[i] == '\\0') {
            break;
        }

        // Find the end of the current word (either a space or the null terminator)
        j = i;
        while (input_string[j] != ' ' && input_string[j] != '\\0') {
            j++;
        }

        // Print the word
        for (int k = i; k < j; k++) {
            printf("%c", input_string[k]);
        }
        printf("\\n"); // Print each word on a new line

        // Move the index 'i' to the position after the current word (which is 'j')
        i = j;
    }

    return 0; // Indicate successful execution
}
