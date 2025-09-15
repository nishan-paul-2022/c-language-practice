/*
 * Purpose: Reads a string and prints its length if it is shorter than a specified maximum length.
 * Topic: String Input, Validation, Modular Programming
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER 10000

// Reads the maximum string length from the user
int get_max_length(void) {
    int max_len;
    printf("Enter the maximum string length (n): ");
    while (scanf("%d", &max_len) != 1 || max_len <= 0 || max_len > MAX_BUFFER) {
        fprintf(stderr, "Invalid input. Enter a positive number (<= %d): ", MAX_BUFFER);
        // Clear invalid input
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Clear newline left in input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    return max_len;
}

// Reads a string from standard input safely
bool read_string(char *buffer, size_t buffer_size) {
    printf("Enter a string (up to %zu characters): ", buffer_size - 1);
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        return false;
    }

    // Remove trailing newline
    buffer[strcspn(buffer, "\n")] = '\0';
    return true;
}

// Processes the string: prints its length if valid, otherwise prints error
void process_string(const char *input, int max_len) {
    size_t len = strlen(input);
    if (len < (size_t)max_len) {
        printf("String length: %zu\n", len);
    } else {
        printf("ERROR: String too long or invalid.\n");
    }
}

int main(void) {
    int max_len = get_max_length();

    char input[MAX_BUFFER];
    if (read_string(input, (size_t)max_len + 1)) {
        process_string(input, max_len);
    } else {
        fprintf(stderr, "Failed to read a valid string.\n");
    }

    return 0;
}
