/*
 * Purpose: Reads a string and prints its length if it is shorter than a specified maximum length.
 * Topic: String Input and Length Validation
 */

#include <stdio.h>
#include <string.h>

// Function to get and validate maximum length
int get_max_length() {
    printf("Enter the maximum string length (n): ");
    int max_len;
    if (scanf("%d", &max_len) != 1 || max_len <= 0) {
        fprintf(stderr, "Invalid maximum length.\n");
        return -1;
    }
    return max_len;
}

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to read string input
int read_string_input(char *input, int max_len) {
    printf("Enter a string (up to %d characters):\n", max_len);
    clear_input_buffer(); // Clear newline left by scanf
    
    if (fgets(input, max_len + 1, stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return -1;
    }
    return 0;
}

// Function to remove trailing newline
void remove_trailing_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Function to check string length
int check_string_length(const char *str, int max_len) {
    size_t len = strlen(str);
    return len < (size_t)max_len ? 1 : 0;
}

// Function to display result
void display_result(const char *str, int max_len) {
    size_t len = strlen(str);
    if (len < (size_t)max_len) {
        printf("String length: %zu\n", len);
    } else {
        printf("ERROR: String too long or invalid.\n");
    }
}

int main(void) {
    // Get maximum length
    int max_len = get_max_length();
    if (max_len == -1) {
        return 1;
    }
    
    // Read string input
    char input[max_len + 1]; // +1 for null terminator
    if (read_string_input(input, max_len) == -1) {
        return 1;
    }
    
    // Remove trailing newline
    remove_trailing_newline(input);
    
    // Display result
    display_result(input, max_len);
    
    return 0;
}