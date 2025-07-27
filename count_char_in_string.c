// Purpose: Counts the occurrences of a specific character within a string.
// Topic: Strings, Arrays, Functions, Character Counting, Input/Output

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // For strlen, strcspn

#define MAX_STRING_LENGTH 1000 // Define a maximum buffer size

// Function to count the occurrences of a specific character within a string.
// Takes the string (char array) and its length as input.
// Reads a character from standard input to search for.
// Returns the count of the character in the string.
int count_character_occurrences(const char str[], int length) {
    char char_to_find;
    int count = 0;
    int i;

    // Check for invalid inputs
    if (str == NULL || length <= 0) {
        fprintf(stderr, "Error: Invalid string or length passed to count_character_occurrences.\n");
        return -1; // Indicate an error
    }

    // Prompt user for the character to search for
    printf("Enter the character to count in the string: ");
    // Read the character, consuming any leftover newline from previous input
    if (scanf(" %c", &char_to_find) != 1) { // Space before %c consumes whitespace
        fprintf(stderr, "Error: Invalid input for character.\n");
        return -1; // Indicate an error
    }
    // Consume any remaining characters on the line after the character, including the newline
    while (getchar() != '\n');

    // Iterate through the string to count occurrences of the character
    for (i = 0; i < length; ++i) {
        if (str[i] == char_to_find) {
            count++;
        }
    }
    return count;
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    int string_length;
    int occurrence_count;

    // Get the string input from the user
    printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH - 1);
    // Use fgets for safe string input
    if (fgets(input_string, MAX_STRING_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read string input.\n");
        return 1; // Indicate an error
    }
    // Remove the trailing newline character from fgets if it exists
    input_string[strcspn(input_string, "\n")] = 0;

    // Get the length of the string
    string_length = strlen(input_string);

    // Call the function to count character occurrences
    occurrence_count = count_character_occurrences(input_string, string_length);

    // Check if the function call resulted in an error
    if (occurrence_count == -1) {
        fprintf(stderr, "Character counting failed.\n");
        return 1; // Indicate an error
    }

    // Print the final count
    printf("The character occurred %d times in the string.\n", occurrence_count);

    return 0; // Indicate successful execution
}
