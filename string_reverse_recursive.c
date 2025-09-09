/*
 * Purpose: Demonstrates reversing a string using recursion.
 * Topic: Recursion, String Manipulation
 */

#include <stdio.h>
#include <string.h> // Required for strlen()

// Recursive function to reverse a string
// str: The string to reverse
// start: The starting index of the substring to reverse
// end: The ending index of the substring to reverse
void reverse_string_recursive(char *str, int start, int end) {
    // Base case: If the start index is greater than or equal to the end index,
    // the substring is empty or has one character, so it's already reversed.
    if (start >= end) {
        return;
    }
    
    // Swap the characters at the start and end indices
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    // Recursively call the function for the remaining substring
    // Move start index forward and end index backward
    reverse_string_recursive(str, start + 1, end - 1);
}

int main() {
    char str[100]; // Buffer to hold the input string
    
    printf("Enter a string to reverse: ");
    
    // Use fgets for safe input to prevent buffer overflows.
    // fgets reads up to sizeof(str) - 1 characters, or until a newline is encountered.
    if (fgets(str, sizeof(str), stdin) != NULL) {
        
        // Remove the trailing newline character if fgets read one
        // strlen(str) - 1 gives the index of the last character.
        // If it's a newline, replace it with a null terminator.
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--; // Update length after removing newline
        }
        
        // Only proceed if the string is not empty after removing newline
        if (len > 0) {
            // Call the recursive function to reverse the string
            // start index is 0, end index is length - 1
            reverse_string_recursive(str, 0, len - 1);
            
            printf("Reversed string: %s\n", str);
        } else {
            printf("Input string was empty.\n");
        }
    } else {
        printf("Error reading input.\n");
    }
    
    return 0;
}
