/*
 * Purpose: Demonstrates accessing and printing individual characters of a string.
 * Topic: Strings, Characters, Array Indexing, Input/Output Functions
 */

#include <stdio.h>
#include <string.h> // Required for strlen()

int main() {
    // Initialize a character array with a string.
    // The array size is 11, which is enough for "Nishan Paul" (10 characters)
    // plus the null terminator '\0'.
    char str[] = "Nishan Paul"; 
    
    // Calculate the length of the string.
    // strlen() returns the number of characters before the null terminator.
    size_t length = strlen(str); 
    
    printf("The string is: %s\n", str);
    printf("String length: %zu\n", length); // %zu is for size_t

    // Access and print individual characters using their index.
    // Remember that array indices are 0-based.
    
    // Example: Print the first character (index 0)
    printf("Character at index 0: %c\n", str[0]); // Should print 'N'
    
    // Example: Print the character at index 9
    // The original code tried to print s[9] using %s, which is incorrect.
    // We should use %c to print a single character.
    if (length > 9) { // Ensure index 9 is valid
        printf("Character at index 9: %c\n", str[9]); // Should print 'u'
    } else {
        printf("Index 9 is out of bounds for this string.\n");
    }

    // Example: Print the last character (index length - 1)
    if (length > 0) {
        printf("Last character (index %zu): %c\n", length - 1, str[length - 1]); // Should print 'l'
    }

    // Example: Print the null terminator (at index length)
    printf("Character at index %zu (null terminator): %d\n", length, str[length]); // Should print 0

    return 0;
}
