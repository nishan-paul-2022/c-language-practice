/*
 * Purpose: Demonstrate array-pointer equivalence for character access.
 * Topic: Multiple ways to access array elements
 */

#include <stdio.h>
#include <string.h>

void demonstrate_array_pointer_equivalence() {
    char str[] = "UC Berkeley (BAIR)";
    char *pointer = str;
    
    printf("Original string: %s\n", str);
    printf("Characters accessed both ways:\n");
    
    for (int i = 0; i < 10 && str[i] != '\0'; i++) {
        printf("  Position %d: str[%d] = '%c', pointer[%d] = '%c', *(pointer+%d) = '%c'\n", i, i, str[i], i, pointer[i], i, *(pointer + i));
    }
}

int main(void) {
    printf("Array-Pointer Equivalence Demonstration\n");
    printf("=======================================\n\n");
    
    demonstrate_array_pointer_equivalence();
    
    return 0;
}
