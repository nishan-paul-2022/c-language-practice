/*
 * Purpose: Reads a line of text and counts the occurrences of vowels, consonants, digits, spaces, and other characters.
 * Topic: String Manipulation, Loops, Conditional Statements, Character Handling (ctype.h)
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100

int is_vowel(char c) {
    char lower = tolower(c);
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}

void count_characters(const char *str, int *vowels, int *consonants, int *digits, int *spaces, int *others) {
    for (int i = 0; str[i] != '\0'; i++) {
        char current_char = str[i];
        
        if (isalpha(current_char)) {
            if (is_vowel(current_char)) {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        } else if (isdigit(current_char)) {
            (*digits)++;
        } else if (isspace(current_char)) {
            (*spaces)++;
        } else {
            (*others)++;
        }
    }
}

void print_results(int vowels, int consonants, int digits, 
    int spaces, int others) {
    printf("\nCharacter Count Results:\n");
    printf("%-12s: %d\n", "Vowels", vowels);
    printf("%-12s: %d\n", "Consonants", consonants);
    printf("%-12s: %d\n", "Digits", digits);
    printf("%-12s: %d\n", "Spaces", spaces);
    printf("%-12s: %d\n", "Others", others);
}

int main(void) {
    char input_string[MAX_INPUT_SIZE];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, others = 0;

    printf("Enter a line of text: ");
    
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        return 0;
    }

    // Remove trailing newline if present
    size_t len = strlen(input_string);
    if (len > 0 && input_string[len - 1] == '\n') {
        input_string[len - 1] = '\0';
    }

    count_characters(input_string, &vowels, &consonants, &digits, &spaces, &others);
    
    print_results(vowels, consonants, digits, spaces, others);

    return 0;
}
