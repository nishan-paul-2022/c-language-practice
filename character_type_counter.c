/*
 * Purpose: Reads a line of text and counts the occurrences of vowels, consonants, digits, spaces, and other characters.
 * Topic: String Manipulation, Loops, Conditional Statements, Character Handling (ctype.h)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_string[100]; // Input string buffer
    int vowels = 0;         // Vowel counter
    int consonants = 0;     // Consonant counter
    int digits = 0;         // Digit counter
    int spaces = 0;         // Space counter
    int others = 0;         // Other characters counter
    int i;

    // Get input line
    printf("Enter a line of text: ");
    // Use fgets to safely read line including spaces
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    // Remove trailing newline character
    input_string[strcspn(input_string, "\n")] = '\0';

    // Process each character
    for (i = 0; input_string[i] != '\0'; i++) {
        char current_char = input_string[i];

        // Convert to lowercase for vowel/consonant check
        char lower_char = tolower(current_char);

        if (isalpha(lower_char)) { // Alphabet character
            if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(current_char)) { // Digit
            digits++;
        } else if (isspace(current_char)) { // Whitespace
            spaces++;
        } else { // Other character
            others++;
        }
    }

    // Print counts
    printf("Counts:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Others: %d\n", others);

    return 0;
}
