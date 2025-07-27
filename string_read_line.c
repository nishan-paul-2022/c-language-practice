// Purpose: Demonstrates reading an entire line of text from standard input using fgets.
// Topic: Strings, Input/Output Functions, Buffer Handling

#include <stdio.h>
#include <string.h> // Required for strlen()

int main() {
    char input_line[100000]; // Buffer to store the input line
    
    printf("Enter a line of text: ");
    
    // Use fgets for safe input to read an entire line.
    // It reads up to sizeof(input_line) - 1 characters, or until a newline is encountered.
    // It also appends a null terminator.
    if (fgets(input_line, sizeof(input_line), stdin) != NULL) {
        
        // Remove the trailing newline character if fgets read one.
        // This is important because we usually don't want the newline in our string.
        size_t len = strlen(input_line);
        if (len > 0 && input_line[len - 1] == '\n') {
            input_line[len - 1] = '\0'; // Replace newline with null terminator
            len--; // Update length after removing newline
        }
        
        // Print the line that was read.
        printf("You entered: %s\n", input_line);
        
    } else {
        // Handle potential errors during input reading.
        printf("Error reading input.\n");
    }
    
    return 0;
}
