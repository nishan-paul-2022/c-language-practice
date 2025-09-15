/*
 * Purpose: Calculates and prints the length of a given string using modular functions.
 * Topic: String Manipulation, Function Usage, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 256

// Reads a string safely from standard input
bool read_input_string(char *buffer, size_t size) {
    printf("Enter a string (max %zu characters): ", size - 1);

    if (fgets(buffer, size, stdin) == NULL) {
        return false;
    }

    // Remove trailing newline
    buffer[strcspn(buffer, "\n")] = '\0';
    return true;
}

// Calculates the length of a string manually
int calculate_string_length(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Prints the length of the string
void print_string_length(const char *str) {
    int length = calculate_string_length(str);
    printf("String length: %d\n", length);
}

int main(void) {
    char input_string[MAX_INPUT];

    if (read_input_string(input_string, sizeof(input_string))) {
        print_string_length(input_string);
    } else {
        fprintf(stderr, "Error: Failed to read a valid string.\n");
        return 1;
    }

    return 0;
}
