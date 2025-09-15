/*
 * Purpose: Demonstrates various ways of passing strings to functions in C.
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

// Function to concatenate two strings
void concatenate_strings(char *dest, const char *src) {
    int dest_len = strlen(dest);
    int i, j;
    for (i = dest_len, j = 0; src[j] != '\0'; i++, j++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
}

// Function to compare two strings
int compare_strings(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

// Function for Example 1: Basic string passing
void demonstrate_basic_string_passing() {
    char my_string1[100] = "UC Berkeley";
    printf("=== Example 1: Basic String Passing ===\n");
    printf("Original string: %s\n", my_string1);
    print_string_puts(my_string1);
    print_string_printf(my_string1);
    print_string_length(my_string1);
    print_string_characters(my_string1);
    printf("\n");
}

// Function for Example 2: Modifying strings through functions
void demonstrate_string_modification() {
    char my_string2[100] = "Hello World";
    printf("=== Example 2: Modifying Strings ===\n");
    printf("Before modification: %s\n", my_string2);
    string_to_uppercase(my_string2);
    printf("After uppercase conversion: %s\n", my_string2);
    printf("\n");
}

// Function for Example 3: String analysis functions
void demonstrate_string_analysis() {
    char my_string3[100] = "Programming is fun";
    printf("=== Example 3: String Analysis ===\n");
    printf("String: %s\n", my_string3);
    printf("Number of vowels: %d\n", count_vowels(my_string3));
    print_string_length(my_string3);
    printf("\n");
}

// Function for Example 4: String concatenation
void demonstrate_string_concatenation() {
    char my_string4[100] = "Hello";
    char append_text[] = " World!";
    printf("=== Example 4: String Concatenation ===\n");
    printf("Before concatenation: %s\n", my_string4);
    concatenate_strings(my_string4, append_text);
    printf("After concatenation: %s\n", my_string4);
    printf("\n");
}

// Function for Example 5: String comparison
void demonstrate_string_comparison() {
    char my_string5a[100] = "Apple";
    char my_string5b[100] = "Banana";
    printf("=== Example 5: String Comparison ===\n");
    printf("String 1: %s\n", my_string5a);
    printf("String 2: %s\n", my_string5b);
    int result = compare_strings(my_string5a, my_string5b);
    if (result < 0) {
        printf("'%s' comes before '%s' alphabetically\n", my_string5a, my_string5b);
    } else if (result > 0) {
        printf("'%s' comes after '%s' alphabetically\n", my_string5a, my_string5b);
    } else {
        printf("'%s' and '%s' are equal\n", my_string5a, my_string5b);
    }
    printf("\n");
}

// Function for Example 6: Passing string literals
void demonstrate_string_literals() {
    printf("=== Example 6: Passing String Literals ===\n");
    print_string_puts("This is a string literal");
    print_string_length("C programming");
    printf("\n");
}

int main(void) {
    demonstrate_basic_string_passing();
    demonstrate_string_modification();
    demonstrate_string_analysis();
    demonstrate_string_concatenation();
    demonstrate_string_comparison();
    demonstrate_string_literals();
    
    return 0;
}