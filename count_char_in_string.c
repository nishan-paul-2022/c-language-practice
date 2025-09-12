/*
 * Purpose: Counts the occurrences of a specific character within a string.
 * Topic: Strings, Arrays, Functions, Character Counting, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Clear input buffer
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Print program header
void print_header(void) {
    printf("=== Character Counter ===\n");
    printf("This program counts occurrences of a specific character in your string.\n\n");
}

// Read string from user input
int read_string(char *buffer, int max_length) {
    printf("Enter a string (max %d characters): ", max_length - 1);
    
    if (fgets(buffer, max_length, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read string input.\n");
        return 0;
    }
    
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
    return 1;
}

// Read character to search for
int read_search_character(char *character) {
    printf("Enter the character to count: ");
    
    if (scanf(" %c", character) != 1) {
        fprintf(stderr, "Error: Invalid character input.\n");
        return 0;
    }
    
    clear_input_buffer();
    return 1;
}

// Count occurrences of character in string
int count_character_occurrences(const char *str, char target_char) {
    if (str == NULL) {
        fprintf(stderr, "Error: Invalid string provided.\n");
        return -1;
    }
    
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target_char) {
            count++;
        }
    }
    
    return count;
}

// Display results
void display_results(const char *str, char character, int count) {
    printf("\nResults:\n");
    printf("String: \"%s\"\n", str);
    printf("Character: '%c'\n", character);
    printf("Occurrences: %d\n", count);
}

int main(void) {
    char input_string[MAX_STRING_LENGTH];
    char search_character;
    int occurrence_count;
    
    print_header();
    
    if (!read_string(input_string, MAX_STRING_LENGTH)) {
        return 1;
    }
    
    if (!read_search_character(&search_character)) {
        return 1;
    }
    
    occurrence_count = count_character_occurrences(input_string, search_character);
    
    if (occurrence_count == -1) {
        return 1;
    }
    
    display_results(input_string, search_character, occurrence_count);
    
    return 0;
}