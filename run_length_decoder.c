/*
 * Purpose: Decodes a custom run-length encoded string, where digits indicate repetition counts, 'b' indicates spaces, and '!' indicates a newline.
 * Topic: Strings, Character Processing, Loops, Conditional Statements (switch), Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char encoded_string[100001]; // Buffer for input string, +1 for null terminator
    int repetition_count;
    int i;

    printf("Enter encoded strings (digits 1-9 for repetition, 'b' for space, '!' for newline).\n");
    printf("Example: 3A2b!5X\n");
    printf("Press Ctrl+D to exit.\n");

    // Use fgets for safer input reading
    while (fgets(encoded_string, sizeof(encoded_string), stdin) != NULL) {
        // Remove trailing newline character if present (fgets includes it)
        int len = strlen(encoded_string);
        if (len > 0 && encoded_string[len - 1] == '\n') {
            encoded_string[len - 1] = '\0';
        }

        repetition_count = 0; // Reset repetition count for each new line

        for (i = 0; encoded_string[i] != '\0'; i++) {
            char current_char = encoded_string[i];

            if (current_char >= '1' && current_char <= '9') {
                // Accumulate repetition count from digits
                repetition_count += (current_char - '0');
            } else {
                // Process characters based on accumulated repetition_count
                if (repetition_count == 0) {
                    // If no digit was encountered, default to 1 repetition for the character
                    repetition_count = 1;
                }

                if (current_char == '!') {
                    printf("\n"); // Print a newline
                } else if (current_char == 'b') {
                    for (int m = 0; m < repetition_count; m++) {
                        printf(" "); // Print spaces
                    }
                } else {
                    for (int m = 0; m < repetition_count; m++) {
                        printf("%c", current_char); // Print the character
                    }
                }
                repetition_count = 0; // Reset count after processing the character
            }
        }
        printf("\n"); // Ensure a newline after each processed line
    }

    printf("\nExiting program.\n");
    return 0;
}