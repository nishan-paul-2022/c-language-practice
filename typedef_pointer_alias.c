/*
 * Purpose: Demonstrates the use of 'typedef' to create an alias for a pointer type (char*) and assign string literals to these pointers.
 * Topic: Typedef, Pointers, String Literals
 */

#include <stdio.h>

int main() {
    // Define 'p' as a type alias for 'char*' (pointer to character)
    // This makes it easier to declare multiple character pointers.
    typedef char* pointer_to_string;

    // Declare variables using the typedef alias
    pointer_to_string str_ptr1;
    pointer_to_string str_ptr2;
    pointer_to_string str_ptr3;

    // Assign string literals to the pointers.
    // String literals are stored in read-only memory, and their addresses are assigned to the pointers.
    str_ptr1 = "nishan ";
    str_ptr2 = "paul ";
    str_ptr3 = "cse";

    // Print the first string literal using puts()
    puts(str_ptr1);
    // Optionally print the other strings as well
    puts(str_ptr2);
    puts(str_ptr3);

    return 0;
}
