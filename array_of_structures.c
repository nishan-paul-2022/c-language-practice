// Purpose: Demonstrates the use of arrays of structures and accessing them with pointers.
// Topic: Arrays of Structures, Pointers to Arrays of Structures

#include <stdio.h>
#include <stdlib.h> // For NULL, though not strictly needed here as we are not using dynamic allocation

// Define a structure
struct Node {
    int data;          // Integer data member
    char character;    // Character data member
    struct Node *next; // Pointer to the next node (not used in this specific example, but part of the original structure)
};

int main() {
    // Declare an array of 3 'Node' structures
    struct Node nodes[3];
    // Declare a pointer to a 'Node' structure
    struct Node *node_ptr;

    // Point the pointer to the beginning of the array
    node_ptr = nodes;

    /*
    // Original commented-out input section - removed as it was incomplete and flawed.
    // If input was intended, it would require proper scanf usage and loop control.
    int i = 0;
    while(i < 10) {
        // scanf("%d, %c", y[0].i); // Incorrect usage: y[0].i is not a pointer, and format specifiers are missing for other members.
        i++;
    }
    */

    // Manually initialize the elements of the array
    // Accessing array elements using pointer arithmetic: node_ptr[index] is equivalent to *(node_ptr + index)
    node_ptr[0].data = 1;
    node_ptr[0].character = 'a';
    // node_ptr[0].next = NULL; // Not explicitly set, will be uninitialized if not assigned

    node_ptr[1].data = 2;
    node_ptr[1].character = 'b';
    // node_ptr[1].next = NULL;

    node_ptr[2].data = 3;
    node_ptr[2].character = 'c';
    // node_ptr[2].next = NULL;

    // Print the 'data' member of the first element in the array
    printf("Data of the first node in the array: %d\n", node_ptr[0].data);

    return 0;
}
