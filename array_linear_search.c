/*
 * Purpose: Performs a linear search on an array to find all occurrences of a target number and prints their 1-based indices.
 * Topic: Arrays, Input/Output, Loops, Linear Search
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array_size;
    printf("Enter the size of the array (or Ctrl+D to exit): ");

    while (scanf("%d", &array_size) == 1) {
        if (array_size <= 0) {
            printf("Array size must be positive. Please try again.\n");
            continue;
        }
        
        int *numbers = (int *)malloc(array_size * sizeof(int));
        if (numbers == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 0;
        }

        printf("Enter %d integers for the array:\n", array_size);
        for (int i = 0; i < array_size; i++) {
            if (scanf("%d", &numbers[i]) != 1) {
                printf("Invalid input. Exiting.\n");
                free(numbers);  
                return 0;
            }
        }

        printf("Enter the number to search for: ");
        int target_number;
        if (scanf("%d", &target_number) != 1) {
            printf("Invalid input. Exiting.\n");
            free(numbers);  
            return 0;
        }

        printf("Occurrences of %d found at 1-based indices: ", target_number);
        int found = 0;
        for (int i = 0; i < array_size; i++) { 
            if (numbers[i] == target_number) {
                printf("%d ", i + 1); 
                found = 1;
            }
        }
        if (!found) {
            printf("None");
        }
        printf("\n\n");

        free(numbers);

        printf("Enter the size of the next array (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
