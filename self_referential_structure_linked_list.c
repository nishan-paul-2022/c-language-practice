// Purpose: Demonstrates self-referential structures and dynamic memory allocation to create a linked list.
// Topic: Self-Referential Structures, Linked Lists, Dynamic Memory Allocation, Pointers

#include <stdio.h>
#include <stdlib.h> // Required for malloc and free

// Define a self-referential structure
typedef struct Node {
    int data_int;         // An integer data member
    char data_char;       // A character data member
    float data_float;     // A float data member
    struct Node *next;    // A pointer to the next node in the list
} Node;

// Function to print the data of each node in the linked list
void print_list(Node *head) {
    Node *current = head; // Start from the head of the list

    printf("Linked List Contents:\n");
    // Traverse the list until the current pointer is NULL (end of the list)
    while (current != NULL) {
        printf("  Int: %d, Float: %.2f, Char: %c\n",
               current->data_int, current->data_float, current->data_char);
        current = current->next; // Move to the next node
    }
    printf("End of List.\n");
}

// Function to free the memory allocated for the linked list
void free_list(Node *head) {
    Node *current = head;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next; // Save the next node's address
        free(current);              // Free the current node
        current = next_node;        // Move to the next node
    }
}

int main() {
    Node *head = NULL; // Initialize the head of the list to NULL
    Node *current = NULL;

    // Create the first node
    head = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        fprintf(stderr, "Memory allocation failed for head node.\n");
        return 1; // Indicate an error
    }
    head->data_int = 10;
    head->data_float = 1.14f;
    head->data_char = 'A';
    head->next = NULL; // Initially, the next pointer is NULL
    current = head;

    // Create and link subsequent nodes
    for (int i = 2; i <= 10; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed for node %d.\n", i);
            // Clean up already allocated memory before exiting
            free_list(head);
            return 1; // Indicate an error
        }
        new_node->data_int = i * 10;
        new_node->data_float = (float)i + 0.14f;
        // Assign characters 'A' through 'J' (or wrap around if needed)
        new_node->data_char = 'A' + (i - 1);
        new_node->next = NULL; // Set next to NULL for the last node

        current->next = new_node; // Link the previous node to the new node
        current = new_node;       // Move current to the new node
    }

    // Print the contents of the linked list
    print_list(head);

    // Free the allocated memory to prevent memory leaks
    free_list(head);

    return 0; // Indicate successful execution
}
