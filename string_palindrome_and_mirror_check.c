/*
 * Purpose: Checks if a string is a palindrome, a mirrored string, or a mirrored palindrome.
 * Topic: Strings, Conditionals, Character Handling, Modular Programming
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LEN 10000

// Function to return the mirrored character of a given character
char get_mirrored_char(char c) {
    switch (c) {
        case 'A': {
            return 'A';
        }
        case 'H': {
            return 'H';
        }
        case 'I': {
            return 'I';
        }
        case 'M': {
            return 'M';
        }
        case 'O': {
            return 'O';
        }
        case 'T': {
            return 'T';
        }
        case 'U': {
            return 'U';
        }
        case 'V': {
            return 'V';
        }
        case 'W': {
            return 'W';
        }
        case 'X': {
            return 'X';
        }
        case 'Y': {
            return 'Y';
        }
        case '1': {
            return '1';
        }
        case '8': {
            return '8';
        }
        case 'E': {
            return '3';
        }
        case '3': {
            return 'E';
        }
        case 'S': {
            return '2';
        }
        case '2': {
            return 'S';
        }
        case 'Z': {
            return '5';
        }
        case '5': {
            return 'Z';
        }
        case 'L': {
            return 'J';
        }
        case 'J': {
            return 'L';
        }
        default: {
            return '\0';
        }
    }
}

// Function to check if a string is a palindrome
int is_palindrome(const char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

// Function to check if a string is a mirrored string
int is_mirrored_string(const char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i <= (len - 1) / 2; i++) {
        char mirrored = get_mirrored_char(str[i]);
        if (mirrored == '\0' || mirrored != str[len - 1 - i]) {
            return 0; // Not a mirrored string
        }
    }
    return 1; // Mirrored string
}

// Function to classify a string and print the result
void classify_string(const char *str) {
    int palindrome = is_palindrome(str);
    int mirrored = is_mirrored_string(str);

    if (palindrome && mirrored) {
        printf("%s -- is a mirrored palindrome.\n\n", str);
    } else if (palindrome) {
        printf("%s -- is a regular palindrome.\n\n", str);
    } else if (mirrored) {
        printf("%s -- is a mirrored string.\n\n", str);
    } else {
        printf("%s -- is not a palindrome.\n\n", str);
    }
}

int main(void) {
    char input_string[MAX_STRING_LEN];

    printf("Enter strings (Ctrl+D to end input on Unix/Linux or Ctrl+Z on Windows):\n");
    while (scanf("%s", input_string) != EOF) {
        classify_string(input_string);
    }

    return 0;
}
