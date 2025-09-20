/*
 * Purpose: Demonstrates the use of typedef for creating custom data types and structures,
 *          along with the sizeof operator to determine memory allocation, using function-based design.
 * Topic: Structures, Typedef, Sizeof Operator
 */

#include <stdio.h>

typedef struct {
    int numbers[10];
    char identifier;
} DataContainer;

typedef int IntAlias;

void initialize_container(DataContainer *container, char id_char) {
    container->identifier = id_char;
    for (int i = 0; i < 10; i++) {
        container->numbers[i] = i + 1;
    }
}

void print_container_info(const DataContainer *container, IntAlias value) {
    printf("Size of DataContainer: %zu bytes\n", sizeof(DataContainer));
    printf("Identifier character: %c\n", container->identifier);
    printf("Aliased integer value: %d\n", value);
}

int main(void) {
    DataContainer container;
    IntAlias value = 12;

    initialize_container(&container, 'X');
    print_container_info(&container, value);

    return 0;
}
