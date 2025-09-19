/*
 * Purpose: Demonstrates various ways of passing strings to functions.
 * Topic: Functions, Strings, Arrays, Pointers, String Manipulation
 */

#include <stdio.h>
#include <string.h>

// Function to print a string using puts()
void print_string_puts(const char *text) {
    puts(text);
}

// Function to print a string using printf()
void print_string_printf(const char *text) {
    printf("Using printf(): %s\n", text);
}

// Function to print string length
void print_string_length(const char *text) {
    printf("String length: %zu\n", strlen(text));
}

// Function to print each character of a string
void print_string_characters(const char *text) {
    printf("Characters: ");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("'%c' ", text[i]);
    }
    printf("\n");
}

// Function to convert string to uppercase (modifies the string)
void string_to_uppercase(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }
}

// Function to count vowels in a string
int count_vowels(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

// Function for Example 1: Basic string passing
void demonstrate_basic_string_passing() {
    printf("=== Example 1: Basic String Passing ===\n");

    char str[100] = "UC Berkeley";

    printf("Original string: %s\n", str);
    print_string_puts(str);
    print_string_printf(str);
    print_string_length(str);
    print_string_characters(str);
    printf("\n");
}

// Function for Example 2: Modifying strings through functions
void demonstrate_string_modification() {
    printf("=== Example 2: Modifying Strings ===\n");

    char str[100] = "Hello World";

    printf("Before modification: %s\n", str);
    string_to_uppercase(str);
    printf("After uppercase conversion: %s\n", str);
    printf("\n");
}

// Function for Example 3: String analysis functions
void demonstrate_string_analysis() {
    printf("=== Example 3: String Analysis ===\n");

    char str[100] = "Programming is fun";

    printf("String: %s\n", str);
    printf("Number of vowels: %d\n", count_vowels(str));
    print_string_length(str);
    printf("\n");
}

int main(void) {
    demonstrate_basic_string_passing();
    demonstrate_string_modification();
    demonstrate_string_analysis();
    
    return 0;
}