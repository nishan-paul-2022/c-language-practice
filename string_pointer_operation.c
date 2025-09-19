/*
 * Purpose: Demonstrates string input and manipulation using pointers.
 * Topic: String manipulation, Pointer operations, String analysis
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 101


void demonstrate_string_input_pointers() {
    char buffer[BUFFER_SIZE];
    char *pointer = buffer;
    
    printf("Enter a string (max %d characters): ", BUFFER_SIZE - 1);
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        
        if (*pointer != '\0') {
            printf("Entered string: %s\n", pointer);
            printf("String length: %zu\n", strlen(pointer));
            printf("First character via pointer: '%c'\n", *pointer);
            printf("Last character: '%c'\n", *(pointer + strlen(pointer) - 1));
            
            if (strlen(pointer) > 2) {
                printf("Substring from position 2: %s\n", pointer + 1);
                printf("Substring from position 3: %s\n", pointer + 2);
            }
        } else {
            printf("Empty string entered.\n");
        }
    } else {
        printf("Error reading input.\n");
    }
}

int main(void) {
    printf("String Input with Pointer Operations\n");
    printf("====================================\n\n");
    
    demonstrate_string_input_pointers();
    
    return 0;
}
