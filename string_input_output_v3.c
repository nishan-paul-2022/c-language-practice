// Purpose: Demonstrates reading a string from input and printing it.
// Topic: Basic string input and output

#include <stdio.h>
#include <string.h>

int main(void) {
    char input_string[10000]; // Buffer to store the input string

    printf("Enter a string: ");
    // Read the string safely using fgets
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error reading the string.\n");
        return 1; // Indicate an error
    }
    // Remove the trailing newline character if present
    input_string[strcspn(input_string, "\n")] = 0;

    printf("You entered: ");
    // Print the string
    puts(input_string);

    return 0;
}
