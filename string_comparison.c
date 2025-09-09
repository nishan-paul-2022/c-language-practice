/*
 * Purpose: Compares two strings lexicographically and prints the result.
 * Topic: String Manipulation, String Comparison, Input Safety
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compare two strings lexicographically
// Returns:
//   0 if strings are equal
//   a negative value if string1 is lexicographically less than string2
//   a positive value if string1 is lexicographically greater than string2
int compareStrings(const char str1[], const char str2[]) {
    // Using the standard library function strcmp for robust comparison
    return strcmp(str1, str2);
}

int main() {
    int bufferSize;
    char string1[256]; // Buffer for the first string
    char string2[256]; // Buffer for the second string
    int comparisonResult;

    // Prompt user for buffer size (though we'll use fixed buffers for simplicity and safety)
    printf("Enter the maximum string length for each input string (e.g., 255 for a buffer of 256):\n");
    if (scanf("%d", &bufferSize) != 1 || bufferSize <= 0 || bufferSize >= sizeof(string1)) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %lu.\n", sizeof(string1) - 1);
        bufferSize = sizeof(string1) - 1; // Use the maximum allowed size
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    printf("Enter the first string (max %d characters):\n", bufferSize);
    // Read the first string safely using fgets
    if (fgets(string1, sizeof(string1), stdin) == NULL) {
        fprintf(stderr, "Error reading the first string.\n");
        return 0;
    }
    // Remove trailing newline character if present
    string1[strcspn(string1, "\n")] = 0;

    printf("Enter the second string (max %d characters):\n", bufferSize);
    // Read the second string safely using fgets
    if (fgets(string2, sizeof(string2), stdin) == NULL) {
        fprintf(stderr, "Error reading the second string.\n");
        return 0;
    }
    // Remove trailing newline character if present
    string2[strcspn(string2, "\n")] = 0;

    // Compare the strings
    comparisonResult = compareStrings(string1, string2);

    printf("\n"); // Print a newline before the result as in the original code

    // Print the comparison result
    if (comparisonResult == 0) {
        printf("EQUAL\n");
    } else if (comparisonResult < 0) {
        // string1 is lexicographically less than string2
        printf("%s\n", string2); // Original code prints string2 if v < 0
    } else { // comparisonResult > 0
        // string1 is lexicographically greater than string2
        printf("%s\n", string1); // Original code prints string1 if v > 0
    }

    return 0;
}
