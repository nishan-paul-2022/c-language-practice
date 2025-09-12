/*
 * Purpose: Demonstrates dynamic memory allocation, manipulation, and deallocation in C
 *          using calloc, realloc, and free.
 * Topic: Dynamic Memory Management
 */

#include <stdio.h>
#include <stdlib.h>

int get_element_count(void) {
    int num_elements;
    printf("Enter the number of integers to allocate: ");
    
    if (scanf("%d", &num_elements) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return -1;
    }
    
    if (num_elements <= 0) {
        printf("Please enter a positive number of elements.\n");
        return -1;
    }
    
    return num_elements;
}

int *allocate_memory(int num_elements) {
    int *memory = (int *)calloc(num_elements, sizeof(int));
    
    if (memory == NULL) {
        printf("Error: Memory allocation failed using calloc.\n");
        return NULL;
    }
    
    printf("Memory allocated successfully for %d integers.\n", num_elements);
    return memory;
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int read_integers(int *memory, int num_elements) {
    printf("Enter %d integers:\n", num_elements);
    
    for (int index = 0; index < num_elements; index++) {
        printf("Enter integer %d: ", index + 1);
        if (scanf("%d", &memory[index]) != 1) {
            printf("Invalid input for integer %d. Aborting.\n", index + 1);
            return 0;
        }
        clear_input_buffer();
    }
    return 1;
}

void print_elements(int *memory, int count, const char *message) {
    printf("%s", message);
    for (int index = 0; index < count; index++) {
        printf("%d ", memory[index]);
    }
    printf("\n");
}

int *reallocate_memory(int *memory, int new_count) {
    int new_size_in_bytes = new_count * sizeof(int);
    printf("Reallocating memory to hold %d integers...\n", new_count);
    
    int *temp_ptr = (int *)realloc(memory, new_size_in_bytes);
    
    if (temp_ptr == NULL) {
        printf("Error: Memory reallocation failed using realloc.\n");
        return NULL;
    }
    
    printf("Memory reallocated successfully to %d bytes.\n", new_size_in_bytes);
    return temp_ptr;
}

void free_memory(int **memory) {
    printf("Freeing allocated memory...\n");
    free(*memory);
    *memory = NULL;
    printf("Memory freed.\n");
}

int main(void) {
    int num_elements = get_element_count();
    if (num_elements <= 0) {
        return 0;
    }
    
    int *allocated_memory = allocate_memory(num_elements);
    if (allocated_memory == NULL) {
        return 0;
    }
    
    if (!read_integers(allocated_memory, num_elements)) {
        free(allocated_memory);
        return 0;
    }
    
    print_elements(allocated_memory, num_elements, "You entered: ");
    
    int *reallocated_memory = reallocate_memory(allocated_memory, 5);
    if (reallocated_memory == NULL) {
        free(allocated_memory);
        return 0;
    }
    allocated_memory = reallocated_memory;
    
    int elements_to_print = (num_elements < 5) ? num_elements : 5;
    print_elements(allocated_memory, elements_to_print, "First 5 elements (or fewer if original allocation was smaller): ");
    
    free_memory(&allocated_memory);
    
    return 0;
}
