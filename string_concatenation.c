// Purpose: Demonstrates concatenating two strings.
// Topic: String concatenation

#include <stdio.h>
#include <string.h>

int main(void) {
    char string1[10000]; // Buffer for the first string (destination for concatenation)
    char string2[10000]; // Buffer for the second string (source for concatenation)

    printf("Enter the first string: ");
    // Read the first string safely using fgets
    if (fgets(string1, sizeof(string1), stdin) == NULL) {
        fprintf(stderr, "Error reading the first string.\n");
        return 0;
    }
    // Remove the trailing newline character if present
    string1[strcspn(string1, "\n")] = 0;

    printf("Enter the second string: ");
    // Read the second string safely using fgets
    if (fgets(string2, sizeof(string2), stdin) == NULL) {
        fprintf(stderr, "Error reading the second string.\n");
        return 0;
    }
    // Remove the trailing newline character if present
    string2[strcspn(string2, "\n")] = 0;

    // Concatenate string2 to the end of string1
    // strcat is safe here because string1 has enough space (10000 characters)
    // to hold its original content plus the content of string2.
    strcat(string1, string2);

    printf("The concatenated string is: ");
    // Print the resulting string (string1)
    puts(string1);

    return 0;
}
