/*
 * Purpose: Reads a string and capitalizes the first letter of each word,
 *          converting other letters to lowercase.
 * Topic: Strings, Character Manipulation, Loops, Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100]; // Buffer for input string
    int i;
    int len;

    // Prompt user for input
    printf("Enter any string: ");
    // Use fgets for safe string input
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    // Remove trailing newline from fgets
    len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--; // Update length
    }

    // Capitalize first letter of each word
    for (i = 0; i < len; i++) {
        // Check if current character is start of word
        // (first character or preceded by space)
        if (i == 0 || str[i - 1] == ' ') {
            // Convert lowercase to uppercase
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] = toupper(str[i]);
            }
        } else {
            // Convert uppercase to lowercase
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = tolower(str[i]);
            }
        }
    }

    // Print result
    printf("Modified string: %s\n", str);

    return 0;
}
