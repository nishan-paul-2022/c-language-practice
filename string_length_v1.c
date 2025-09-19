/*
 * Purpose: Calculates and prints the length of a given string without using built-in function.
 * Topic: String Manipulation, Function Usage, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 256

void remove_trailing_newline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

bool read_input_string(char *buffer, int size) {
    printf("Enter a string (max %d characters): ", size - 1);

    if (fgets(buffer, size, stdin) == NULL) {
        return false;
    }

    remove_trailing_newline(buffer);

    return true;
}

int calculate_string_length(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }
    
    return length;
}

void print_string_length(const char *str) {
    int length = calculate_string_length(str);
    printf("Length: %d\n", length);
}

int main(void) {
    char input_string[MAX_INPUT];

    if (read_input_string(input_string, MAX_INPUT)) {
        print_string_length(input_string);
    } else {
        fprintf(stderr, "Failed to read a valid string.\n");
        return 0;
    }

    return 0;
}
