/*
 * Purpose: Demonstrates the definition and usage of a structure in C, including initializing and accessing its members.
 * Topic: Structures
 */

#include <stdio.h>
#include <string.h>

// Define a structure to hold different data types
struct example_structure {
    int integer_value;      // An integer member
    double double_value;    // A double-precision floating-point member
    char string_value[100]; // A character array (string) member
};

int main() {
    // Declare an instance of the structure
    struct example_structure my_struct;

    // Initialize the structure members
    my_struct.integer_value = 1;
    my_struct.double_value = 3.1416;
    strcpy(my_struct.string_value, "string"); // Use strcpy for string assignment

    // Print the structure members
    printf("Integer: %d\n", my_struct.integer_value);
    printf("Double: %.2lf\n", my_struct.double_value);
    printf("String: %s\n", my_struct.string_value);

    return 0;
}
