/*
 * Purpose: Demonstrates string comparison, length calculation, concatenation, and copying using modular functions.
 * Topic: Strings, String Functions (strcmp, strlen, strcat, strcpy), Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LEN 100

// Reads a string safely from standard input
void read_string(char *buffer, size_t size, const char *prompt) {
    printf("%s (max %zu characters): ", prompt, size - 1);
    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(1);
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
}

// Compares two strings and prints whether they are equal
void compare_strings(const char *str1, const char *str2) {
    if (strcmp(str1, str2) == 0) {
        printf("Strings are the same.\n");
    } else {
        printf("Strings are not the same.\n");
    }
}

// Prints the lengths of two strings
void print_string_lengths(const char *str1, const char *str2) {
    printf("Length of first string: %zu\n", strlen(str1));
    printf("Length of second string: %zu\n", strlen(str2));
}

// Concatenates str1 + " " + str2 into a destination buffer and prints it
void concatenate_strings(const char *str1, const char *str2, char *dest, size_t dest_size) {
    if (strlen(str1) + strlen(str2) + 2 > dest_size) { // +1 for space, +1 for null
        fprintf(stderr, "Error: Destination buffer too small for concatenation.\n");
        exit(1);
    }
    strcpy(dest, str1);
    strcat(dest, " ");
    strcat(dest, str2);
    printf("Concatenated string: %s\n", dest);
}

// Copies source string into destination and prints the result
void copy_string(const char *source, char *destination) {
    strcpy(destination, source);
    printf("After copying, destination string: %s\n", destination);
}

int main(void) {
    char string_a[MAX_STRING_LEN];
    char string_b[MAX_STRING_LEN];
    char temp_buffer[MAX_STRING_LEN * 2]; // Buffer for concatenation

    // Read strings from the user
    read_string(string_a, MAX_STRING_LEN, "Enter the first string");
    read_string(string_b, MAX_STRING_LEN, "Enter the second string");

    printf("\nString Comparison:\n");
    compare_strings(string_a, string_b);

    print_string_lengths(string_a, string_b);

    concatenate_strings(string_a, string_b, temp_buffer, sizeof(temp_buffer));

    copy_string(string_b, string_a);

    return 0;
}
