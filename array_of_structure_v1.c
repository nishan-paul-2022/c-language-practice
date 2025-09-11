/*
 * Purpose: Demonstrates the use of structure array and accessing them with pointers.
 * Topic: Structure Array, Pointer to Structure Array
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    char character;
    struct Node *next;
};

int main(void) {
    struct Node nodes[3];
    struct Node *node_pointer;

    node_pointer = nodes;

    // Accessing array elements using pointer arithmetic: node_pointer[index] is equivalent to *(node_pointer + index)
    node_pointer[0].data = 1;
    node_pointer[0].character = 'a';

    node_pointer[1].data = 2;
    node_pointer[1].character = 'b';

    node_pointer[2].data = 3;
    node_pointer[2].character = 'c';

    printf("Data of the first node in the array: %d\n", node_pointer[0].data);
    printf("Character of the first node in the array: %c\n", node_pointer[0].character);

    return 0;
}
