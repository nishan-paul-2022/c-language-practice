/*
 * Purpose: Demonstrates the use of structure array and accessing them with pointers.
 * Topic: Structure Array, Pointer to Structure Array
 */

#include <stdio.h>
#include <stdlib.h> // For NULL, though not strictly needed here as we are not using dynamic allocation

struct Node {
    int data; // Integer data member
    char character; // Character data member
    struct Node *next; // Pointer to the next node (not used in this specific example, but part of the original structure)
};

int main() {
    // Declare an array of 3 'Node' structures
    struct Node nodes[3];
    // Declare a pointer to a 'Node' structure
    struct Node *node_ptr;

    // Point the pointer to the beginning of the array
    node_ptr = nodes;

    // Manually initialize the elements of the array
    // Accessing array elements using pointer arithmetic: node_ptr[index] is equivalent to *(node_ptr + index)
    node_ptr[0].data = 1;
    node_ptr[0].character = 'a';

    node_ptr[1].data = 2;
    node_ptr[1].character = 'b';

    node_ptr[2].data = 3;
    node_ptr[2].character = 'c';

    // Print the 'data' member of the first element in the array
    printf("Data of the first node in the array: %d\n", node_ptr[0].data);

    return 0;
}
