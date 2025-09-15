/*
 * Purpose: Reads a string, converts it to lowercase, and prints it without vowels.
 * Topic: String Manipulation, Character Handling, Loops, Input Safety
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to print a string without vowels
void print_without_vowels(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')) {
            putchar(str[i]);
        }
    }
    putchar('\n');
}

// Function to safely read a string from input
int read_input_string(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return -1; // Failure
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    return 0; // Success
}

int main(void) {
    char input_string[MAX_STRING_SIZE];

    printf("Enter a string: ");
    if (read_input_string(input_string, MAX_STRING_SIZE) == -1) {
        fprintf(stderr, "Error: Failed to read input.\n");
        return 0;
    }

    to_lowercase(input_string);

    printf("String without vowels: ");
    print_without_vowels(input_string);

    return 0;
}
