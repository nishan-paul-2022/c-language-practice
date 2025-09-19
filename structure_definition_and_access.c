/*
 * Purpose: Demonstrates the definition and usage of a structure, including initializing and accessing its members using function-based approach.
 * Topic: Structures
 */

#include <stdio.h>
#include <string.h>


typedef struct {
    int integer_value;
    double double_value;
    char string_value[100];
} ExampleStructure;


void initialize_structure(ExampleStructure *s, int int_val, double dbl_val, const char *str_val) {
    s->integer_value = int_val;
    s->double_value = dbl_val;
    strcpy(s->string_value, str_val);
}


void print_structure(const ExampleStructure *s) {
    printf("Integer: %d\n", s->integer_value);
    printf("Double: %.2lf\n", s->double_value);
    printf("String: %s\n", s->string_value);
}

int main(void) {
    ExampleStructure my_struct;

    
    initialize_structure(&my_struct, 1, 3.1416, "string");

    
    print_structure(&my_struct);

    return 0;
}
