/*
 * Purpose: Performs a linear search on an array to find all occurrences of a target number and prints their 1-based indices.
 * Topic: Arrays, Input/Output, Loops, Linear Search
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int arraySize;
    int *numbers;
    int targetNumber;

    printf("Enter the size of the array (or Ctrl+D to exit): ");
    while (scanf("%d", &arraySize) == 1) {
        if (arraySize <= 0) {
            printf("Array size must be positive. Please try again.\n");
            continue;
        }

        // Dynamically allocate memory for the array
        numbers = (int *)malloc(arraySize * sizeof(int));
        if (numbers == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 0;
        }

        printf("Enter %d integers for the array:\n", arraySize);
        for (int i = 0; i < arraySize; i++) {
            if (scanf("%d", &numbers[i]) != 1) {
                printf("Invalid input. Exiting.\n");
                free(numbers);  // Free allocated memory before exiting
                return 0;
            }
        }

        printf("Enter the number to search for: ");
        if (scanf("%d", &targetNumber) != 1) {
            printf("Invalid input. Exiting.\n");
            free(numbers);  // Free allocated memory before exiting
            return 0;
        }

        printf("Occurrences of %d found at 1-based indices: ", targetNumber);
        int found = 0;
        for (int i = 0; i < arraySize; i++) { // Loop up to arraySize, not i
            if (numbers[i] == targetNumber) {
                printf("%d ", i + 1); // Print 1-based index
                found = 1;
            }
        }
        if (!found) {
            printf("None");
        }
        printf("\n\n");

        free(numbers); // Free the allocated memory after use

        printf("Enter the size of the next array (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return 0;
}
