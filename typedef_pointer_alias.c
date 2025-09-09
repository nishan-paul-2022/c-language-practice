/*
 * Purpose: Demonstrates the use of 'typedef' to create an alias for a pointer type (char*) and assign string literals to these pointers.
 * Topic: Typedef, Pointers, String Literals
 */

#include <stdio.h>

int main() {
    // Define 'p' as a type alias for 'char*' (pointer to character)
    // This makes it easier to declare multiple character pointers.
    typedef char* PointerToString;

    // Declare variables using the typedef alias
    PointerToString strPtr1;
    PointerToString strPtr2;
    PointerToString strPtr3;

    // Assign string literals to the pointers.
    // String literals are stored in read-only memory, and their addresses are assigned to the pointers.
    strPtr1 = "nishan ";
    strPtr2 = "paul ";
    strPtr3 = "cse";

    // Print the first string literal using puts()
    puts(strPtr1);
    // Optionally print the other strings as well
    puts(strPtr2);
    puts(strPtr3);

    return 0;
}
