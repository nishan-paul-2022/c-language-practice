// Purpose: Checks if a given string is a palindrome using recursion.
// Topic: Recursion, String Manipulation, String Length, Character Comparison, Input Handling

#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower, to make comparison case-insensitive

// Recursive helper function to check for palindrome property.
// It compares characters from the start (index `start`) and end (index `end`) of the string.
// Returns 1 if it's a palindrome up to this point, 0 otherwise.
int is_palindrome_recursive_helper(const char str[], int start, int end) {
    // Base case 1: If the start index has crossed or met the end index, it's a palindrome.
    if (start >= end) {
        return 1; // It's a palindrome
    }

    // Compare characters at the current start and end indices (case-insensitive).
    // Convert characters to lowercase for case-insensitive comparison.
    if (tolower(str[start]) == tolower(str[end])) {
        // If characters match, recursively call for the inner substring.
        // Move start index forward and end index backward.
        return is_palindrome_recursive_helper(str, start + 1, end - 1);
    } else {
        // If characters do not match, it's not a palindrome.
        return 0; // Not a palindrome
    }
}

// Main function to check if a string is a palindrome.
// It sets up the initial call to the recursive helper function.
int is_palindrome(const char str[]) {
    int length = strlen(str);
    // If the string is empty or has only one character, it's considered a palindrome.
    if (length <= 1) {
        return 1;
    }
    // Call the recursive helper function with initial start and end indices.
    return is_palindrome_recursive_helper(str, 0, length - 1);
}

int main() {
    char input_string[100]; // Buffer to store the input string

    printf("Enter a string to check if it's a palindrome: ");
    
    // Use fgets for safer string input to prevent buffer overflows.
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read input string.\n");
        return 0;
    }

    // Remove the trailing newline character if fgets read one
    input_string[strcspn(input_string, "\n")] = 0;

    // Check if the string is a palindrome using the recursive function
    if (is_palindrome(input_string)) {
        printf("Yes, the string \"%s\" is a palindrome.\n", input_string);
    } else {
        printf("No, the string \"%s\" is not a palindrome.\n", input_string);
    }

    return 0;
}
