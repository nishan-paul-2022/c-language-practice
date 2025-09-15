/*
 * Purpose: Demonstrates basic pointer usage with strings, including array-pointer equivalence. 
 * Topic: Pointers, String Manipulation 
 */

#include <stdio.h>

int main(void) {
    char country_name[] = "Bangladesh";

    printf("String: %s\n", country_name); // Print string
    printf("Address of first character: %p\n", (void *)country_name); // Print memory address

    return 0;
}
