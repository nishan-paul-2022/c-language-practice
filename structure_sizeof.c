/*
 * Purpose: Demonstrates the use of typedef for creating custom data types and structures,
 *          along with the sizeof operator to determine memory allocation.
 * Topic: Structures, Typedef, Sizeof Operator
 */

#include <stdio.h>

// Define a structure to hold an integer array and a character.
typedef struct {
    int numbers[10]; // An array to store 10 integers.
    char identifier; // A character to identify the structure instance.
} DataContainer;

// Define a type alias for integer, demonstrating typedef.
// In a real-world scenario, 'teacher' might be a more specific alias if relevant.
typedef int AliasInt;

int main() {
    // Declare a variable using the integer type alias.
    AliasInt alias_value = 12;

    // Declare a variable of the DataContainer structure type.
    DataContainer container_instance;

    // Assign a character to the 'identifier' member of the structure.
    container_instance.identifier = 'X';

    // Print the size of the structure, the identifier character, and the aliased integer value.
    // sizeof(container_instance) will show the total memory occupied by the structure.
    printf("Size of DataContainer: %zu bytes\n", sizeof(DataContainer));
    printf("Identifier character: %c\n", container_instance.identifier);
    printf("Aliased integer value: %d\n", alias_value);

    return 0;
}
