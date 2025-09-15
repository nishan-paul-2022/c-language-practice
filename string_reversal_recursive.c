/*
 * Purpose: Demonstrates reversing a string using recursion.
 * Topic: Recursion, String Manipulation
 */

#include <stdio.h>
#include <string.h>

// Recursive function to reverse a string
void reverse_string_recursive(char *str, int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse_string_recursive(str, start + 1, end - 1);
}

// Function to get input string from user
int get_input_string(char *str, size_t max_len) {
    printf("Enter a string to reverse: ");
    if (fgets(str, max_len, stdin) != NULL) {
        return 0; // Success
    } else {
        return -1; // Error
    }
}

// Function to clean input string (remove trailing newline)
size_t clean_input_string(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }
    return len;
}

// Function to validate input string
int is_valid_string(const char *str, size_t len) {
    return len > 0;
}

// Function to display result
void display_result(const char *str, int success) {
    if (success) {
        printf("Reversed string: %s\n", str);
    } else {
        printf("Input string was empty.\n");
    }
}

// Function to display error message
void display_error(const char *message) {
    printf("%s\n", message);
}

int main(void) {
    char str[100];
    
    // Get input string
    if (get_input_string(str, sizeof(str)) == -1) {
        display_error("Error reading input.");
        return 1;
    }
    
    // Clean input string
    size_t len = clean_input_string(str);
    
    // Validate input and process
    if (is_valid_string(str, len)) {
        reverse_string_recursive(str, 0, len - 1);
        display_result(str, 1);
    } else {
        display_result(str, 0);
    }
    
    return 0;
}
