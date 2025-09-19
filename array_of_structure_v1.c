/*
 * Purpose: Demonstrates the use of structure array and accessing them with pointers.
 * Topic: Structure Array, Pointer to Structure Array
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    char character;
    struct Node *next;
} Node;

int main(void) {
    Node nodes[3];
    Node *node_pointer = nodes;

    
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
