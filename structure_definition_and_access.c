/*
 * Purpose: Demonstrates the definition and usage of a structure, including initializing and accessing its members using function-based approach.
 * Topic: Structures
 */

#include <stdio.h>
#include <string.h>

// Define a structure to hold different data types
typedef struct {
    int integer_value;
    double double_value;
    char string_value[100];
} ExampleStructure;

// Function to initialize a structure
void initialize_structure(ExampleStructure *s, int int_val, double dbl_val, const char *str_val) {
    s->integer_value = int_val;
    s->double_value = dbl_val;
    strcpy(s->string_value, str_val);
}

// Function to print a structure's members
void print_structure(const ExampleStructure *s) {
    printf("Integer: %d\n", s->integer_value);
    printf("Double: %.2lf\n", s->double_value);
    printf("String: %s\n", s->string_value);
}

int main(void) {
    ExampleStructure my_struct;

    // Initialize structure
    initialize_structure(&my_struct, 1, 3.1416, "string");

    // Print structure members
    print_structure(&my_struct);

    return 0;
}
