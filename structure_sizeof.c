/*
 * Purpose: Demonstrates the use of typedef for creating custom data types and structures,
 *          along with the sizeof operator to determine memory allocation, using function-based design.
 * Topic: Structures, Typedef, Sizeof Operator
 */

#include <stdio.h>

// Define a structure to hold an integer array and a character.
typedef struct {
    int numbers[10];
    char identifier;
} DataContainer;

typedef int AliasInt;

// Function to initialize DataContainer
void initialize_container(DataContainer *container, char id_char) {
    container->identifier = id_char;
    for (int i = 0; i < 10; i++) {
        container->numbers[i] = i + 1;
    }
}

// Function to print container info and aliased integer
void print_container_info(const DataContainer *container, AliasInt value) {
    printf("Size of DataContainer: %zu bytes\n", sizeof(DataContainer));
    printf("Identifier character: %c\n", container->identifier);
    printf("Aliased integer value: %d\n", value);
}

int main(void) {
    DataContainer container_instance;
    AliasInt alias_value = 12;

    initialize_container(&container_instance, 'X');
    print_container_info(&container_instance, alias_value);

    return 0;
}
