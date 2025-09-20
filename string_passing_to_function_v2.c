/*
 * Purpose: Demonstrates various ways of passing strings to functions.
 * Topic: Functions, Strings, Arrays, Pointers, String Manipulation
 */

#include <stdio.h>
#include <string.h>

void print_string_puts(const char *text) {
    puts(text);
}

void print_string_length(const char *text) {
    printf("String length: %zu\n", strlen(text));
}

void concatenate_strings(char *dest, const char *src) {
    int dest_len = strlen(dest);
    int i, j;
    for (i = dest_len, j = 0; src[j] != '\0'; i++, j++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
}

int compare_strings(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

void demonstrate_string_concatenation() {
    printf("=== Example 1: String Concatenation ===\n");

    char str1[100] = "UC Berkeley";
    char str2t[] = " (BAIR)";

    printf("Before concatenation: %s\n", str1);
    concatenate_strings(str1, str2t);
    printf("After concatenation: %s\n", str1);
    printf("\n");
}

void demonstrate_string_comparison() {
    printf("=== Example 2: String Comparison ===\n");

    char str1[100] = "Apple";
    char str2[100] = "Banana";

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);

    int result = compare_strings(str1, str2);
    if (result < 0) {
        printf("'%s' comes before '%s' alphabetically\n", str1, str2);
    } else if (result > 0) {
        printf("'%s' comes after '%s' alphabetically\n", str1, str2);
    } else {
        printf("'%s' and '%s' are equal\n", str1, str2);
    }
    printf("\n");
}

void demonstrate_string_literals() {
    printf("=== Example 3: Passing String Literals ===\n");

    print_string_puts("This is a string literal");
    print_string_length("C programming");
    printf("\n");
}

int main(void) {
    demonstrate_string_concatenation();
    demonstrate_string_comparison();
    demonstrate_string_literals();
    
    return 0;
}
