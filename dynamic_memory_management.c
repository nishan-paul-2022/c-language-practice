// Purpose: Demonstrates dynamic memory allocation, manipulation, and deallocation in C
//          using calloc, realloc, and free.
// Topic: Dynamic Memory Management

#include <stdio.h>
#include <stdlib.h> // Required for calloc, realloc, free

int main() {
    int *allocated_memory = NULL; // Pointer to the dynamically allocated memory block.
    int num_elements;             // Number of elements to allocate initially.
    int index;                    // Loop index.
    int new_size_in_bytes;        // New size for realloc.

    // --- Input ---
    printf("Enter the number of integers to allocate: ");
    // Read the number of elements and validate input.
    if (scanf("%d", &num_elements) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Ensure the number of elements is positive.
    if (num_elements <= 0) {
        printf("Please enter a positive number of elements.\n");
        return 0;
    }

    // --- Dynamic Allocation using calloc ---
    // Allocate memory for 'num_elements' integers.
    // calloc allocates memory and initializes all bits to zero.
    allocated_memory = (int *)calloc(num_elements, sizeof(int));

    // Check if memory allocation was successful.
    if (allocated_memory == NULL) {
        printf("Error: Memory allocation failed using calloc.\n");
        return 0;
    }

    printf("Memory allocated successfully for %d integers.\n", num_elements);

    // --- Reading Input into Allocated Memory ---
    printf("Enter %d integers:\n", num_elements);
    for (index = 0; index < num_elements; index++) {
        // Read each integer.
        // Note: scanf("%d%*c", ...) is used here for simplicity to consume the newline
        // after each integer. For more robust input handling, consider reading lines with fgets
        // and parsing them.
        printf("Enter integer %d: ", index + 1);
        if (scanf("%d", &allocated_memory[index]) != 1) {
            printf("Invalid input for integer %d. Aborting.\n", index + 1);
            free(allocated_memory); // Free allocated memory before exiting.
            return 0;
        }
        // Consume the newline character after reading the integer.
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // --- Printing Elements ---
    printf("You entered: ");
    for (index = 0; index < num_elements; index++) {
        printf("%d ", allocated_memory[index]);
    }
    printf("\n");

    // --- Reallocating Memory ---
    // Resize the memory block to hold 5 integers.
    new_size_in_bytes = 5 * sizeof(int);
    printf("Reallocating memory to hold 5 integers...\n");

    // realloc attempts to resize the memory block pointed to by allocated_memory.
    // It returns a pointer to the new block, which might be the same or different.
    // If reallocation fails, it returns NULL, and the original block remains valid.
    int *temp_ptr = (int *)realloc(allocated_memory, new_size_in_bytes);

    // Check if reallocation was successful.
    if (temp_ptr == NULL) {
        printf("Error: Memory reallocation failed using realloc.\n");
        // If realloc fails, the original pointer 'allocated_memory' is still valid.
        // We should free it before exiting.
        free(allocated_memory);
        return 0;
    } else {
        // If reallocation was successful, update the pointer.
        allocated_memory = temp_ptr;
        printf("Memory reallocated successfully to %d bytes.\n", new_size_in_bytes);
    }

    // --- Printing Elements After Reallocation ---
    // Print the first 5 elements. We need to be careful not to read out of bounds
    // if the original allocation (num_elements) was less than 5.
    printf("First 5 elements (or fewer if original allocation was smaller): ");
    // Determine how many elements to safely print.
    int elements_to_print_after_realloc = (num_elements < 5) ? num_elements : 5;
    
    for (index = 0; index < elements_to_print_after_realloc; index++) {
        printf("%d ", allocated_memory[index]);
    }
    // If num_elements was less than 5, the new memory allocated by realloc is uninitialized.
    // If num_elements was 5 or more, the first 5 elements are preserved.
    printf("\n");

    // --- Deallocating Memory ---
    // Free the dynamically allocated memory to prevent memory leaks.
    printf("Freeing allocated memory...\n");
    free(allocated_memory);
    allocated_memory = NULL; // Good practice to set pointer to NULL after freeing.
    printf("Memory freed.\n");

    return 0;
}
