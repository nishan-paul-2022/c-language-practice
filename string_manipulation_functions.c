/*
 * Purpose: Demonstrates string comparison, length calculation, concatenation, and copying using modular functions.
 * Topic: Strings, String Functions (strcmp, strlen, strcat, strcpy), Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LEN 101

void read_string(char *buffer, int size, const char *prompt) {
    printf("%s (max %d characters): ", prompt, size - 1);

    if (fgets(buffer, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        exit(1);
    }

    buffer[strcspn(buffer, "\n")] = '\0';
}

void compare_strings(const char *str1, const char *str2) {
    if (strcmp(str1, str2) == 0) {
        printf("Strings are the same.\n");
    } else {
        printf("Strings are not the same.\n");
    }
}

void print_string_lengths(const char *str1, const char *str2) {
    printf("Length of first string: %zu\n", strlen(str1));
    printf("Length of second string: %zu\n", strlen(str2));
}

void concatenate_strings(const char *str1, const char *str2, char *dest, int length) {
    int required_length = strlen(str1) + strlen(str2) + 2;
    if (required_length > length) {
        fprintf(stderr, "Destination buffer too small for concatenation.\n");
        exit(1);
    }

    strcpy(dest, str1);
    strcat(dest, " ");
    strcat(dest, str2);
    
    printf("Concatenated string: %s\n", dest);
}

void copy_string(const char *source, char *destination) {
    strcpy(destination, source);
    printf("After copying, destination string: %s\n", destination);
}

int main(void) {
    int length = MAX_STRING_LEN * 2;

    char str1[MAX_STRING_LEN];
    char str2[MAX_STRING_LEN];
    char dest[length];

    read_string(str1, MAX_STRING_LEN, "Enter the first string");
    read_string(str2, MAX_STRING_LEN, "Enter the second string");

    printf("\nString Comparison:\n");
    compare_strings(str1, str2);

    print_string_lengths(str1, str2);

    concatenate_strings(str1, str2, dest, length);

    copy_string(str2, str1);

    return 0;
}
