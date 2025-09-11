/*
 * Purpose: Demonstrates basic pointer usage with strings, including array-pointer equivalence.
 * Topic: Pointers, String Manipulation
 */

#include <stdio.h>

// Function to demonstrate basic pointer usage with strings
void demonstrate_string_pointer() {
    char str[] = "BANGLADESH"; // Declare and initialize a character array (string)
    char *ptr;                 // Declare a character pointer

    // Assign the base address of the array 'str' to the pointer 'ptr'.
    // 'str' itself decays to a pointer to its first element.
    ptr = str;

    printf("Original string: %s\n", str);
    printf("String printed using pointer: %s\n", ptr);

    // You can also print character by character using the pointer
    printf("Characters accessed via pointer:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("  str[%d]: %c (via ptr[%d]: %c)\n", i, str[i], i, ptr[i]);
    }
}

int main(void) {
    demonstrate_string_pointer(); // Call the function to demonstrate
    return 0;
}
