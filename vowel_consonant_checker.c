/*
 * Purpose: Reads a single character and determines if it is a lowercase vowel or a consonant.
 * Topic: Character Handling, Conditional Statements, Logical Operators
 */

#include <stdio.h> // Required for getchar and printf
#include <ctype.h> // Required for tolower() (to handle uppercase input)

int main() {
    char input_char; // Variable to store the character input by the user

    // Prompt user for input
    printf("Enter a single alphabet character: ");
    input_char = getchar(); // Read a single character from standard input

    // Convert the character to lowercase to simplify the check
    input_char = tolower(input_char);

    // Check if the character is a lowercase vowel
    if (input_char == 'a' || input_char == 'e' || input_char == 'i' || input_char == 'o' || input_char == 'u') {
        printf("Vowel\n");
    }
    // Check if it's a lowercase alphabet and not a vowel, then it's a consonant
    else if (input_char >= 'a' && input_char <= 'z') {
        printf("Consonant\n");
    }
    // If it's not an alphabet, print an appropriate message
    else {
        printf("Not an alphabet character.\n");
    }

    return 0;
}
