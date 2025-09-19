/*
 * Purpose: Demonstrates string manipulation using pointer operations.
 * Topic: Manual string copying, string reversal, pointer-based operations
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

char* reverse_string(char *str) {
    int length = strlen(str);

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
    
    return str;
}

void demonstrate_string_manipulation() {
    char original[] = "UC Berkeley (BAIR)";
    char copy[BUFFER_SIZE];
    char *pointer_original = original;
    char *pointer_copy = copy;
    
    printf("Original string: %s\n", pointer_original);
    
    while (*pointer_original != '\0') {
        *pointer_copy = *pointer_original;
        pointer_original++;
        pointer_copy++;
    }
    *pointer_copy = '\0';
    
    printf("Copied string: %s\n", copy);
    
    reverse_string(copy);
    printf("Reversed string: %s\n", copy);
    
    if (strlen(copy) > 3) {
        printf("Substring from 4th char of reversed: %s\n", copy + 3);
    }
}

int main(void) {
    printf("String Manipulation with Pointers\n");
    printf("=================================\n\n");
    
    demonstrate_string_manipulation();
 
    return 0;
}
