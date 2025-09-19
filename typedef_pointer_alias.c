/*
 * Purpose: Demonstrates the use of 'typedef' to create an alias for a pointer type and assign data to these pointers.
 * Topic: Typedef, Pointers, String Literals
 */

#include <stdio.h>

typedef char* string_pointer;

string_pointer create_string(const char *literal) {
    return (string_pointer)literal;
}

void print_string(string_pointer str) {
    puts(str);
}

int main(void) {
    string_pointer s1 = create_string("University of ");
    string_pointer s2 = create_string("California, ");
    string_pointer s3 = create_string("Berkeley ");
    string_pointer s4 = create_string("(BAIR)");

    printf("%s\n", s1);
    printf("%s\n", s2);
    puts(s3);
    puts(s4);

    return 0;
}
