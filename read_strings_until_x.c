/*
 * Purpose: Reads strings from input and prints them until a string starting with 'x' is encountered.
 * Topic: String input, loops, conditional execution, input buffer handling.
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256 // Maximum buffer size for input strings

// Function to read a string safely from input
int read_string(char *buffer, int max_length) {
    if (fgets(buffer, max_length, stdin) == NULL) {
        return -1; // EOF or error
    }
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
    return 0; // Success
}

// Function to handle the main loop of reading and printing strings
void process_strings(int max_length) {
    char input[BUFFER_SIZE];
    while (1) {
        printf("Enter a string: ");
        if (read_string(input, max_length) == -1) {
            printf("Error reading input or end of input reached.\n");
            break;
        }

        if (input[0] == 'x') { // Exit condition
            printf("Exiting program as input starts with 'x'.\n");
            break;
        }

        printf("You entered: %s\n", input);
    }
}

int main(void) {
    int max_string_length;

    printf("Enter the maximum length for strings (e.g., 50): ");
    if (scanf("%d", &max_string_length) != 1 || max_string_length <= 0 || max_string_length >= BUFFER_SIZE) {
        printf("Invalid length entered. Please enter a positive integer less than %d.\n", BUFFER_SIZE);
        return 0;
    }

    while (getchar() != '\n'); // Consume leftover newline

    printf("Enter strings. Type a string starting with 'x' to exit.\n");
    process_strings(max_string_length);

    return 0;
}
