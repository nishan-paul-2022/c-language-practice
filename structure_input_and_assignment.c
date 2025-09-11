/*
 * Purpose: Demonstrates reading user input into a string and assigning it to a structure member, highlighting safe input practices.
 * Topic: Structures, String Input
 */

#include <stdio.h>
#include <string.h>

// Define a structure to hold different data types
struct example_structure {
    int integer_value;      // An integer member
    double double_value;    // A double-precision floating-point member
    char string_value[100]; // A character array (string) member
};

int main(void) {
    // Declare an instance of the structure
    struct example_structure my_struct;
    // Declare a buffer for user input
    char input_string[100];

    // Prompt user for input
    printf("Enter a string: ");

    // Safely read user input using fgets to prevent buffer overflow
    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        // Remove the trailing newline character read by fgets, if present
        input_string[strcspn(input_string, "\n")] = 0;

        // Assign values to the structure members
        my_struct.integer_value = 10;
        my_struct.double_value = 10.12345;
        strcpy(my_struct.string_value, input_string); // Copy the user's input string

        // Print the structure members
        printf("Integer: %d\n", my_struct.integer_value);
        printf("Double: %.2lf\n", my_struct.double_value);
        printf("String: %s\n", my_struct.string_value);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return 0;
    }

    return 0;
}
