/*
 * Purpose: Demonstrates how to print the memory address of a character variable using a pointer.
 * Topic: Pointers, Memory Addresses, Character Types
 */

#include <stdio.h>

void get_address() {
    printf("=== Example 1: Getting Memory Address ===\n");
    char c = 'a';
    printf("Memory address of 'c' is: %p\n", (void *)&c);
    printf("Value of 'c' is: %c\n\n", c);
}

void dereference_pointer() {
    printf("=== Example 2: Dereferencing Pointer ===\n");
    char c = 'a';
    char *ptr = &c;
    printf("Value pointed to by ptr is: %c\n", *ptr);
    printf("Address stored in ptr is: %p\n\n", (void *)ptr);
}

void modify_through_pointer() {
    printf("=== Example 3: Modifying Value Through Pointer ===\n");
    char c = 'a';
    char *ptr = &c;
    printf("Initial value of c: %c\n", c);
    *ptr = 'b';
    printf("After modifying through pointer, c = '%c'\n", c);
    printf("Value pointed to by ptr is now: %c\n\n", *ptr);
}

void pointer_arithmetic() {
    printf("=== Example 4: Pointer Arithmetic ===\n");
    char str[] = "Hello";
    char *ptr = str;
    printf("String is '%s'\n", str);
    printf("Address of first character: %p\n", (void *)ptr);
    printf("Address of second character: %p\n", (void *)(ptr + 1));
    printf("Value of first character: %c\n", *ptr);
    printf("Value of second character: %c\n\n", *(ptr + 1));
}

void compare_pointers() {
    printf("=== Example 5: Comparing Pointers ===\n");
    char c1 = 'x';
    char c2 = 'y';
    char *ptr1 = &c1;
    char *ptr2 = &c2;
    printf("Address of x: %p\n", (void *)ptr1);
    printf("Address of y: %p\n", (void *)ptr2);
    if (ptr1 > ptr2) {
        printf("ptr1 has a higher address than ptr2\n");
    } else {
        printf("ptr2 has a higher address than ptr1\n");
    }
    printf("\n");
}

int main(void) {
    get_address();
    
    dereference_pointer();
    
    modify_through_pointer();
    
    pointer_arithmetic();
    
    compare_pointers();
    
    return 0;
}
