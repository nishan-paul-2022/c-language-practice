// Purpose: Demonstrates that an array name can be treated as a pointer to its first element
// and how to print the string and its starting memory address.
// Topic: Pointers, Arrays, String Handling, Memory Addresses

#include <stdio.h>

int main(void) {
    // Declare a character array and initialize it with a string.
    // The compiler automatically adds a null terminator ('\0') at the end.
    char country_name[] = "Bangladesh";

    // Print the string. The array name 'country_name' decays to a pointer
    // to its first element, which is what printf("%s", ...) expects.
    printf("The string is: %s\\n", country_name);

    // Print the memory address of the first character of the string.
    // The array name 'country_name' itself evaluates to the address of its first element.
    // Using %p format specifier for printing memory addresses.
    printf("The memory address of the string (first character) is: %p\\n", (void *)country_name);

    return 0; // Indicate successful execution.
}
