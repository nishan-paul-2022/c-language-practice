/*
 * Purpose: Demonstrates accessing and printing individual characters of a string.
 * Topic: Strings, Characters, Array Indexing, Input/Output
 */

#include <stdio.h>
#include <string.h>

void display_string_info(const char *str) {
    size_t length = strlen(str);
    printf("String: %s\n", str);
    printf("Length: %zu\n", length);
}

void display_character_at_index(const char *str, size_t index) {
    size_t length = strlen(str);
    if (index < length) {
        printf("Character at index %zu: %c\n", index, str[index]);
    }
}

void display_last_character(const char *str) {
    size_t length = strlen(str);
    if (length > 0) {
        printf("Last character (index %zu): %c\n", length - 1, str[length - 1]);
    }
}

void display_null_terminator(const char *str) {
    size_t length = strlen(str);
    printf("Null terminator at index %zu: %d\n", length, str[length]);
}

int main(void) {
    char str[] = "UC Berkeley (BAIR)";
    
    display_string_info(str);
    display_character_at_index(str, 0);
    display_character_at_index(str, 9);
    display_last_character(str);
    display_null_terminator(str);
    
    return 0;
}
