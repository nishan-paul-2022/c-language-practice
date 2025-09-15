/*
 * Purpose: Demonstrates the use of structures, pointers to structures, and self-referential structures.
 * Topic: Structures, Pointers to Structures, Self-Referential Structures
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    char character;
    struct Node *next;
} Node;

int main(void) {
    Node node1 = {10, 'a', NULL};
    Node node2 = {11, 'b', NULL};
    Node node3 = {20, 'x', NULL};
    Node node4 = {21, 'y', NULL};

    Node *node3_ptr = &node3;
    Node *node4_ptr = &node4;

    node1.next = &node2;
    node3_ptr->next = node4_ptr;

    printf("Traversing linked structure: node3_ptr->next points to node with data: %d\n", node3_ptr->next->data);

    return 0;
}
