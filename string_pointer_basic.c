/*
 * Purpose: Demonstrates basic string pointer concepts.
 * Topic: String arrays, pointers, memory addresses
 */

#include <stdio.h>
#include <string.h>

void demonstrate_basic_string_pointers() {
    char str[] = "UC Berkeley (BAIR)";
    char *pointer = str;
    
    printf("String via array name: %s\n", str);
    printf("String via pointer: %s\n", pointer);
    printf("Memory address of string: %p\n", (void*)str);
    printf("Memory address via pointer: %p\n", (void*)pointer);
    printf("Address equivalence: %s\n", (str == pointer) ? "True" : "False");
}

int main(void) {
    printf("Basic String Pointer Demonstration\n");
    printf("==================================\n\n");
    
    demonstrate_basic_string_pointers();
    
    return 0;
}
