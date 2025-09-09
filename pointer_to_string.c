// Purpose: Demonstrates how to use a character pointer to point to a string (character array)
// and print the string and its starting memory address.
// Topic: Pointers, Strings, Arrays, Memory Addresses

#include <stdio.h>

int main(void) {
    // Declare a character array and initialize it with a string.
    char country_name_str[] = "BANGLADESH";

    // Declare a character pointer.
    char *pointer_to_string;

    // Assign the address of the first element of the array 'country_name_str' to 'pointer_to_string'.
    // The array name itself decays to a pointer to its first element.
    pointer_to_string = country_name_str; // Equivalent to pointer_to_string = &country_name_str[0];

    // Print the string using the pointer. printf("%s", ...) expects a char pointer.
    printf("The string is: %s\\n", pointer_to_string);

    // Print the memory address stored in the pointer.
    // Using %p format specifier for printing memory addresses.
    printf("The memory address pointed to by pointer_to_string is: %p\\n", (void *)pointer_to_string);

    return 0;
}
