/*
 * Purpose: Demonstrates string comparison, length calculation, concatenation, and copying.
 * Topic: Strings, String Functions (strcmp, strlen, strcat, strcpy), Input/Output
 */

#include <stdio.h>
#include <string.h> // For strcmp, strlen, strcat, strcpy, strcspn
#include <stdlib.h> // For exit() and EXIT_FAILURE

#define MAX_STRING_LEN 100 // Define a maximum length for strings to prevent buffer overflows

int main(void) {
    char stringA[MAX_STRING_LEN];
    char stringB[MAX_STRING_LEN];
    char tempBuffer[MAX_STRING_LEN]; // Temporary buffer for concatenation
    int comparisonResult;
    size_t lengthA, lengthB; // Use size_t for lengths

    // Prompt for and read the first string
    printf("Enter the first string (max %d characters): ", MAX_STRING_LEN - 1);
    if (fgets(stringA, MAX_STRING_LEN, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read the first string.\n");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character if present
    stringA[strcspn(stringA, "\n")] = 0;

    // Prompt for and read the second string
    printf("Enter the second string (max %d characters): ", MAX_STRING_LEN - 1);
    if (fgets(stringB, MAX_STRING_LEN, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read the second string.\n");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character if present
    stringB[strcspn(stringB, "\n")] = 0;

    // Compare the two strings
    comparisonResult = strcmp(stringA, stringB);

    // Print the comparison result
    printf("\nString Comparison:\n");
    if (comparisonResult == 0) {
        printf("Strings are the same.\n");
    } else {
        printf("Strings are not the same.\n");
    }

    // Calculate and print the lengths of the strings
    lengthA = strlen(stringA);
    lengthB = strlen(stringB);
    printf("Length of first string: %zu\n", lengthA);
    printf("Length of second string: %zu\n", lengthB);

    // Concatenate stringA, a space, and stringB into stringA
    // Ensure stringA has enough space: MAX_STRING_LEN is sufficient here.
    // First, copy stringA to a temporary buffer to preserve it for the next step.
    strcpy(tempBuffer, stringA);
    
    // Append a space to tempBuffer
    strcat(tempBuffer, " ");
    
    // Append stringB to tempBuffer
    strcat(tempBuffer, stringB);
    
    printf("\nConcatenated string (stringA + \" \" + stringB): %s\n", tempBuffer);

    // Copy stringB to stringA
    // This overwrites the original content of stringA.
    strcpy(stringA, stringB);
    printf("After strcpy(stringA, stringB), stringA is now: %s\n", stringA);

    return 0;
}
