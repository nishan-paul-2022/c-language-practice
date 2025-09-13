/*
 * Purpose: Demonstrates how to use a character pointer to point to a string (character array)
 * and print the string and its starting memory address.
 * Topic: Pointers, Strings, Arrays, Memory Addresses
 */

#include <stdio.h>

void print_string_info(char *str_ptr) {
    printf("The string is: %s\n", str_ptr);
    printf("The memory address pointed to by pointer_to_string is: %p\n", (void *)str_ptr);
}

int main(void) {
    char country_name_str[] = "BANGLADESH";
    char *pointer_to_string = country_name_str;

    print_string_info(pointer_to_string);

    return 0;
}
