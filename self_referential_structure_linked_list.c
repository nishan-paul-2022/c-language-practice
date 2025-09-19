/*
 * Purpose: Demonstrates self-referential structures and dynamic memory allocation to create a linked list.
 * Topic: Self-Referential Structures, Linked Lists, Dynamic Memory Allocation, Pointers
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data_int;
    char data_char;
    float data_float;
    struct Node *next;
} Node;

void print_linked_list(Node *head) {
    Node *current_node = head;

    printf("Linked List Contents:\n");

    while (current_node != NULL) {
        printf("  Int: %d, Float: %.2f, Char: %c\n", current_node->data_int, current_node->data_float, current_node->data_char);
        current_node = current_node->next;
    }

    printf("End of List.\n");
}

void free_linked_list(Node *head) {
    Node *current_node = head;
    Node *next_node;

    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}

int main(void) {
    Node *head_node = NULL;
    Node *current_node = NULL;

    head_node = (Node *)malloc(sizeof(Node));
    if (head_node == NULL) {
        fprintf(stderr, "Memory allocation failed for head node.\n");
        return 0;
    }

    head_node->data_int = 10;
    head_node->data_float = 1.14f;
    head_node->data_char = 'A';
    head_node->next = NULL;
    current_node = head_node;

    for (int i = 2; i <= 10; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed for node %d.\n", i);
            free_linked_list(head_node);
            return 0;
        }

        new_node->data_int = i * 10;
        new_node->data_float = (float)i + 0.14f;
        new_node->data_char = 'A' + (i - 1);
        new_node->next = NULL;

        current_node->next = new_node;
        current_node = new_node;
    }

    print_linked_list(head_node);
    free_linked_list(head_node);

    return 0;
}
