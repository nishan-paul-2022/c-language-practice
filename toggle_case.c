/*
 * Purpose: Demonstrates reading a character, toggling its case (upper to lower, lower to upper),
 * and printing the result. Includes a mechanism to exit the loop.
 * Topic: Characters, ASCII Values, Conditional Statements, Loops, Input Handling
 */

#include <stdio.h>

int main() {
    char input_char;
    
    printf("Enter characters to toggle their case. Enter 'q' to quit.\n");
    
    // Loop to continuously read and process characters until 'q' is entered.
    while (1) {
        printf("Enter a character: ");
        
        // Use " %c" to consume any leading whitespace (including newlines)
        // before reading the actual character. This prevents issues with
        // leftover newline characters from previous inputs.
        if (scanf(" %c", &input_char) != 1) {
            // If scanf fails (e.g., end of input), break the loop.
            printf("Input error or end of input. Exiting.\n");
            break;
        }
        
        // Check for the quit character
        if (input_char == 'q' || input_char == 'Q') {
            printf("Quitting program.\n");
            break;
        }
        
        // Check if the character is an uppercase letter
        if (input_char >= 'A' && input_char <= 'Z') {
            // Convert to lowercase by adding the difference between 'a' and 'A'
            printf("Toggled case: %c\n", input_char + ('a' - 'A'));
        } 
        // Check if the character is a lowercase letter
        else if (input_char >= 'a' && input_char <= 'z') {
            // Convert to uppercase by subtracting the difference between 'a' and 'A'
            printf("Toggled case: %c\n", input_char - ('a' - 'A'));
        } 
        // If it's not a letter, print it as is.
        else {
            printf("Character is not a letter, printing as is: %c\n", input_char);
        }
        
        // Print extra newlines for better readability between prompts
        printf("\n"); 
    }
    
    return 0;
}
