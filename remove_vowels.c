// Purpose: Reads a string, converts it to lowercase, and prints it without vowels.
// Topic: String Manipulation, Character Handling, Loops, Input Safety

#include <stdio.h>
#include <string.h>
#include <ctype.h> // Required for tolower()

int main() {
    char input_string[100]; // Buffer to store the input string
    int string_length;      // Length of the input string
    int char_index;         // Index for iterating through the string

    printf("Enter a string: ");
    
    // Use fgets for safer string input to prevent buffer overflows.
    // fgets reads up to sizeof(input_string) - 1 characters or until a newline is encountered.
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input string.\n");
        return 1; // Indicate an error
    }

    // Remove the trailing newline character if fgets read one
    input_string[strcspn(input_string, "\n")] = 0;

    // Convert the entire string to lowercase using tolower()
    string_length = strlen(input_string);
    for (char_index = 0; char_index < string_length; char_index++) {
        input_string[char_index] = tolower(input_string[char_index]);
    }

    printf("String without vowels: ");
    // Iterate through the string and print characters that are not vowels
    for (char_index = 0; char_index < string_length; char_index++) {
        // Check if the current character is NOT a vowel
        if (!(input_string[char_index] == 'a' || input_string[char_index] == 'e' || 
              input_string[char_index] == 'i' || input_string[char_index] == 'o' || 
              input_string[char_index] == 'u')) {
            printf("%c", input_string[char_index]);
        }
    }
    printf("\n"); // Print a newline at the end of the output

    return 0;
}
