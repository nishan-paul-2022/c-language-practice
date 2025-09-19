/*
 * Purpose: Compares two strings lexicographically and prints the result.
 * Topic: String Manipulation, Input Safety
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

int read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        printf("\nError reading input string.\n");
        return -1;
    }

    buffer[strcspn(buffer, "\n")] = 0;
    
    return 0;
}

void display_comparison_result(const char *str1, const char *str2) {
    int comparison = strcmp(str1, str2);
    
    if (comparison == 0) {
        printf("%s and %s is equivalent.\n", str1, str2);
    } else if (comparison < 0) {
        printf("%s > %s\n", str2, str1);
    } else {
        printf("%s > %s\n", str1, str2);
    }
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
    
    display_comparison_result(str1, str2);
    
    return 0;
}
