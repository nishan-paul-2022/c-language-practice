#include <stdio.h>
#include <string.h> // For strlen
#include <ctype.h>  // For toupper and tolower

// Purpose: Reads a string and capitalizes the first letter of each word,
//          converting other letters to lowercase.
// Topic: Strings, Character Manipulation, Loops, Input/Output
int main() {
    char str[100]; // Increased buffer size for safety
    int i;
    int len;

    // Prompt user for input
    printf("Enter any string: ");
    // Use fgets for safe string input
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Indicate an error
    }

    // Remove trailing newline character if present from fgets
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--; // Update length
    }

    // Process the string to capitalize first letter of each word
    for (i = 0; i < len; i++) {
        // Check if the current character is the start of a word
        // (either it's the first character or preceded by a space)
        if (i == 0 || str[i - 1] == ' ') {
            // If it's a lowercase letter, convert it to uppercase
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = toupper(str[i]);
            }
        } else {
            // If it's not the start of a word, convert to lowercase
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = tolower(str[i]);
            }
        }
    }

    // Print the modified string
    printf("Modified string: %s\n", str);

    return 0; // Indicate successful execution
}
