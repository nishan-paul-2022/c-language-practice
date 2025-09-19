/*
 * Purpose: Demonstrate safe pointer usage and validation.
 * Topic: Pointer safety, null checking, boundary validation
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

// Demonstrate pointer comparison and validation
void demonstrate_pointer_validation() {
    char buffer[] = "Hello World";
    
    // Safe pointer usage
    char *pointer = buffer;

    if (pointer != NULL) {
        printf("Valid pointer: %s\n", pointer);
        printf("Pointer points to: %p\n", (void*)pointer);
    }
    
    // Null pointer handling
    char *null_pointer = NULL;

    if (null_pointer == NULL) {
        printf("Null pointer detected - safe handling\n");
    }
    
    // Boundary checking
    int len = strlen(buffer);

    printf("String boundary check:\n");
    printf("  Valid access at position 0: '%c'\n", *(pointer + 0));
    printf("  Valid access at last position %d: '%c'\n", len - 1, *(pointer + len - 1));
    printf("  Null terminator at position %d: %d\n", len, *(pointer + len));
}

int main(void) {
    printf("Pointer Validation and Safety Demonstration\n");
    printf("===========================================\n\n");
    
    demonstrate_pointer_validation();
    
    return 0;
}
