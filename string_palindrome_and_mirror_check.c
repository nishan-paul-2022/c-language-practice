// Purpose: Checks if a string is a palindrome, a mirrored string, or a mirrored palindrome.
// Topic: Strings, Conditionals, Character Handling

#include <stdio.h>
#include <string.h>
#include <math.h> // For ceil function

// Function to check if a character has a mirrored counterpart and if it matches
char get_mirrored_char(char c) {
    switch (c) {
        case 'A': return 'A';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'W': return 'W';
        case 'X': return 'X';
        case 'Y': return 'Y';
        case '1': return '1';
        case '8': return '8';
        case 'E': return '3';
        case '3': return 'E';
        case '5': return 'Z';
        case 'L': return 'J';
        case 'J': return 'L';
        case 'S': return '2';
        case '2': return 'S';
        case 'Z': return '5'; // Added 'Z' to '5' mapping for completeness based on original code
        default: return '\0'; // No mirrored counterpart or invalid character
    }
}

int main() {
    char input_string[10000];
    int string_length;
    int is_palindrome;
    int is_mirrored;
    int i;

    // Read strings until EOF
    while (scanf("%s", input_string) != EOF) {
        // Consume the newline character left by scanf("%s")
        getchar();

        is_palindrome = 1; // Assume it's a palindrome
        is_mirrored = 1;   // Assume it's a mirrored string
        string_length = strlen(input_string);

        // Check for palindrome property
        for (i = 0; i < string_length / 2; i++) {
            if (input_string[i] != input_string[string_length - 1 - i]) {
                is_palindrome = 0; // Not a palindrome
                break;
            }
        }

        // Check for mirrored string property
        for (i = 0; i <= (string_length - 1) / 2; i++) { // Iterate up to the middle character (inclusive for odd length)
            char mirrored_char_left = get_mirrored_char(input_string[i]);
            char mirrored_char_right = get_mirrored_char(input_string[string_length - 1 - i]);

            if (mirrored_char_left == '\0' || mirrored_char_right == '\0' || mirrored_char_left != input_string[string_length - 1 - i] || mirrored_char_right != input_string[i]) {
                is_mirrored = 0; // Not a mirrored string
                break;
            }
        }

        // Output the result based on palindrome and mirrored properties
        if (is_palindrome && is_mirrored) {
            printf("%s -- is a mirrored palindrome.\n\n", input_string);
        } else if (is_palindrome && !is_mirrored) {
            printf("%s -- is a regular palindrome.\n\n", input_string);
        } else if (!is_palindrome && is_mirrored) {
            printf("%s -- is a mirrored string.\n\n", input_string);
        } else {
            printf("%s -- is not a palindrome.\n\n", input_string);
        }
    }

    return 0;
}
