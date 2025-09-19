/*
 * Purpose: Demonstrate pointer arithmetic for string manipulation.
 * Topic: Pointer arithmetic, substring operations
 */

#include <stdio.h>
#include <string.h>

void demonstrate_pointer_arithmetic() {
    char str[] = "California";
    char *pointer = str;
    
    printf("Original string: %s\n", pointer);
    printf("From 1st position (pointer): %s\n", pointer);
    printf("From 2nd position (pointer+1): %s\n", pointer + 1);
    printf("From 3rd position (pointer+2): %s\n", pointer + 2);
    printf("From 5th position (pointer+4): %s\n", pointer + 4);
    
    printf("\nCharacter access via pointer arithmetic:\n");
    for (int i = 0; i < 5 && *(pointer + i) != '\0'; i++) {
        printf("  *(pointer + %d) = '%c'\n", i, *(pointer + i));
    }
}

int main(void) {
    printf("Pointer Arithmetic Demonstration\n");
    printf("================================\n\n");
    
    demonstrate_pointer_arithmetic();

    return 0;
}
