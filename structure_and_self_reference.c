/*
 * Purpose: Demonstrates the use of structures, pointers to structures, and self-referential structures.
 * Topic: Structures, Pointers to Structures, Self-Referential Structures
 */

#include <stdio.h>
#include <stdlib.h>

// Define a self-referential structure
struct Node {
    int data;          // Integer data member
    char character;    // Character data member
    struct Node *next; // Pointer to the next node in a potential linked list
};

int main(void) {
    // Declare instances of the structure and pointers to structures
    struct Node node1;
    struct Node node2;
    struct Node node_z;
    struct Node node_z1;

    struct Node *ptr_to_node_z;
    struct Node *ptr_to_node_z1;

    // Initialize the first node (node1)
    node1.data = 10;
    node1.character = 'a';
    node1.next = &node2; // node1's next pointer points to node2

    // Initialize the second node (node2)
    node2.data = 11;
    node2.character = 'b';
    node2.next = NULL; // node2 is the last node in this sequence

    // Initialize node_z and its pointer
    ptr_to_node_z = &node_z; // ptr_to_node_z points to node_z
    ptr_to_node_z->data = 20;
    ptr_to_node_z->character = 'x';
    ptr_to_node_z->next = ptr_to_node_z1; // ptr_to_node_z's next points to ptr_to_node_z1

    // Initialize node_z1 and its pointer
    ptr_to_node_z1 = &node_z1; // ptr_to_node_z1 points to node_z1
    ptr_to_node_z1->data = 21;
    ptr_to_node_z1->character = 'y';
    ptr_to_node_z1->next = NULL; // node_z1 is the last node in this sequence

    // Access and print the 'data' member of the node pointed to by ptr_to_node_z->next
    // This is equivalent to accessing node_z1.data
    printf("Data of the node pointed to by (ptr_to_node_z->next): %d\n", ptr_to_node_z->next->data);

    return 0;
}
