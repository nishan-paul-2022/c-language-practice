/*
 * Purpose: Reads a line of text and counts the occurrences of vowels, consonants, digits, spaces, and other characters.
 * Topic: String Manipulation, Loops, Conditional Statements, Character Handling (ctype.h)
 */

#include <stdio.h>  // Required for printf, scanf
#include <string.h> // Required for string functions (e.g., strlen, though not directly used here)
#include <ctype.h>  // Required for tolower, isalpha, isdigit, isspace

int main() {
    char input_string[100]; // Buffer to store the input string
    int vowels = 0;         // Counter for vowels
    int consonants = 0;     // Counter for consonants
    int digits = 0;         // Counter for digits
    int spaces = 0;         // Counter for spaces
    int others = 0;         // Counter for other characters
    int i;                  // Loop counter

    // Prompt user for input and read the entire line
    printf("Enter a line of text: ");
    // Use fgets to safely read a line of text, including spaces
    // stdin is the standard input stream
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Indicate an error
    }

    // Remove the trailing newline character if fgets read it
    input_string[strcspn(input_string, "\n")] = '\0';

    // Iterate through each character in the string
    for (i = 0; input_string[i] != '\0'; i++) {
        char current_char = input_string[i];

        // Convert character to lowercase for easier vowel/consonant check
        char lower_char = tolower(current_char);

        if (isalpha(lower_char)) { // Check if it's an alphabet character
            if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(current_char)) { // Check if it's a digit
            digits++;
        } else if (isspace(current_char)) { // Check if it's a whitespace character
            spaces++;
        } else { // Otherwise, it's another type of character
            others++;
        }
    }

    // Print the counts
    printf("Counts:\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Others: %d\n", others);

    return 0; // Indicate successful execution
}
