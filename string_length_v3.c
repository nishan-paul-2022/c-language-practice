/*
 * Purpose: Calculates and prints the length of a given string using built-in function.
 * Topic: String Input and Length Calculation
 */

#include <stdio.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void remove_trailing_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int get_max_length() {
    printf("Enter the maximum string length: ");
    int max_len;

    if (scanf("%d", &max_len) != 1 || max_len <= 0) {
        fprintf(stderr, "Invalid maximum length.\n");
        return -1;
    }

    return max_len;
}

int read_string_input(char *input, int max_len) {
    printf("Enter a string (up to %d characters): ", max_len);
    clear_input_buffer();
    
    if (fgets(input, max_len + 1, stdin) == NULL) {
        fprintf(stderr, "Failed to read input.\n");
        return -1;
    }

    return 0;
}

void display_result(const char *str, int max_len) {
    size_t len = strlen(str);
    int result = len < (size_t)max_len ? 1 : 0;

    if (result) {
        printf("Length: %zu\n", len);
    } else {
        printf("Input string exceeds maximum allowed length.\n");
    }
}

int main(void) {
    int max_len = get_max_length();
    if (max_len == -1) {
        return 0;
    }
    
    char input[max_len + 1];
    if (read_string_input(input, max_len) == -1) {
        return 0;
    }
    
    remove_trailing_newline(input);
    
    display_result(input, max_len);
    
    return 0;
}