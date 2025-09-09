/*
 * Purpose: Demonstrates reading a string using fgets and accessing it via a pointer.
 * Topic: Pointers, Strings, Input/Output Functions, Memory Management
 */

#include <stdio.h>
#include <string.h>

int main() {
    char input_buffer[100]; // Buffer to store the input string
    char *string_ptr = input_buffer; // Pointer to the beginning of the buffer
    
    printf("Enter a string: ");
    
    // Use fgets for safe input to prevent buffer overflows.
    // It reads up to sizeof(input_buffer) - 1 characters, or until a newline.
    if (fgets(input_buffer, sizeof(input_buffer), stdin) != NULL) {
        
        // Remove the trailing newline character if fgets read one.
        size_t len = strlen(input_buffer);
        if (len > 0 && input_buffer[len - 1] == '\n') {
            input_buffer[len - 1] = '\0'; // Replace newline with null terminator
            len--; // Update length
        }
        
        // Check if the string is not empty after removing the newline
        if (len > 0) {
            // Print the string using the pointer.
            // The pointer 'string_ptr' points to the first character of the string.
            // printf("%s", string_ptr) correctly interprets this as a null-terminated string.
            printf("You entered: %s\n", string_ptr);
        } else {
            printf("You entered an empty string.\n");
        }
    } else {
        printf("Error reading input.\n");
    }
    
    return 0;
}
