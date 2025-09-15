/*
 * Purpose: Demonstrates the use of 'typedef' to create an alias for a pointer type (char*) and assign string literals to these pointers.
 * Topic: Typedef, Pointers, String Literals
 */

#include <stdio.h>

typedef char* str_ptr;

str_ptr create_string(const char *literal) {
    return (str_ptr)literal;
}

void print_string(str_ptr str) {
    puts(str);
}

int main(void) {
    str_ptr s1 = create_string("University of ");
    str_ptr s2 = create_string("California, ");
    str_ptr s3 = create_string("Berkeley ");
    str_ptr s4 = create_string("(BAIR)");

    printf("%s\n", s1);
    printf("%s\n", s2);
    puts(s3);
    puts(s4);

    return 0;
}
