/*
 * Purpose: Reads two strings, copies the first into the second, and prints the result.
 * Topic: String Functions
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10000

int read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL) {
        printf("\nError reading input string.\n");
        return -1;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    return 1;
}

void copy_and_display(char *destination, const char *source) {
    strcpy(destination, source);
    printf("Copied string: %s\n", destination);
}

int main(void) {
    char str1[BUFFER_SIZE];    
    if (read_string("Enter the first string: ", str1, BUFFER_SIZE) == -1) {
        return 0;
    }
    
    char str2[BUFFER_SIZE];
    if (read_string("Enter the second string: ", str2, BUFFER_SIZE) == -1) {
        return 0;
    }
    
    copy_and_display(str2, str1);
    
    return 0;
}
