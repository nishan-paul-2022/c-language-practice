/*
 * Purpose: Reads a line of text and counts the frequency of each lowercase alphabet character within it.
 * Topic: String Manipulation, Loops, Character Handling (ctype.h), Arrays (for frequency counting)
 */

#include <stdio.h> // Required for printf, fgets
#include <string.h> // Required for strcspn
#include <ctype.h> // Required for tolower, isalpha

int main() {
    char input_string[100]; // Buffer to store the input string
    int frequency[26] = {0}; // Array to store frequency of 'a' through 'z', initialized to 0
    int i; // Loop counter

    // Prompt user for input and read the entire line safely
    printf("Enter a line of text: ");
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Indicate an error
    }

    // Remove the trailing newline character if fgets read it
    input_string[strcspn(input_string, "\n")] = '\0';

    // Iterate through each character in the input string
    for (i = 0; input_string[i] != '\0'; i++) {
        char current_char = input_string[i];
        char lower_char = tolower(current_char); // Convert to lowercase

        // If the character is a lowercase alphabet, increment its frequency count
        if (lower_char >= 'a' && lower_char <= 'z') {
            frequency[lower_char - 'a']++;
        }
    }

    // Print the frequency of each alphabet that appeared
    printf("Alphabet Frequencies:\n");
    for (i = 0; i < 26; i++) {
        if (frequency[i] > 0) { // Only print if the character appeared at least once
            printf("%c - %d\n", (char)('a' + i), frequency[i]);
        }
    }

    return 0; // Indicate successful execution
}
