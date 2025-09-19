/*
 * Purpose: Checks if a given string is a palindrome using recursion.
 * Topic: Recursion, String Manipulation, String Length, Character Comparison, Input Handling
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome_recursive_helper(const char str[], int start, int end) {
    if (start == end) { // Base case: crossed indices
        return 1;
    }

    if (tolower(str[start]) == tolower(str[end])) { // Case-insensitive match
        return is_palindrome_recursive_helper(str, start + 1, end - 1);
    } else {
        return 0; // Not a palindrome
    }
}

int is_palindrome(const char str[]) {
    int length = strlen(str);
    if (length <= 1) { // Empty or single char
        return 1;
    }

    int result = is_palindrome_recursive_helper(str, 0, length - 1);
    return result;
}

void read_input(char str[], int size) {
    printf("Enter a string to check palindrome: ");

    if (fgets(str, size, stdin) != NULL) {
        str[strcspn(str, "\n")] = 0; // Remove trailing newline
    } else {
        fprintf(stderr, "Error reading input.\n");
        str[0] = '\0';
    }
}

void print_result(const char str[]) {
    if (is_palindrome(str)) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }
}

int main(void) {
    char input_string[100];

    read_input(input_string, sizeof(input_string));
    print_result(input_string);

    return 0;
}
