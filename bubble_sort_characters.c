/*
 * Purpose: Demonstrates sorting an array of characters using the Bubble Sort algorithm.
 * Topic: Arrays, sorting algorithms, characters, loops, input/output.
 */

#include <stdio.h>
#include <string.h> // For strlen, strcspn
#include <stdlib.h> // For exit()

#define BUFFER_SIZE 256 // Define a reasonable buffer size for input

int main(void) {
    int array_size;
    char characters[BUFFER_SIZE]; // Use a fixed buffer size for simplicity
    int outer_index, inner_index;
    char temp; // Use char for temp variable as we are sorting characters

    printf("Enter the number of characters to sort (max %d): ", BUFFER_SIZE);
    // Read the size of the array and validate input
    if (scanf("%d", &array_size) != 1 || array_size <= 0 || array_size > BUFFER_SIZE) {
        printf("Invalid input. Please enter a positive integer up to %d.\\n", BUFFER_SIZE);
        return 1; // Indicate an error
    }

    // Consume the newline character left by scanf
    while (getchar() != '\\n');

    printf("Enter %d characters, separated by spaces or newlines:\\n", array_size);
    // Use fgets for safe input to read the characters.
    // We read into a buffer and then process it to get individual characters.
    // This approach is safer than reading characters one by one with scanf,
    // especially if the input format is mixed.
    if (fgets(characters, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input string.\\n");
        return 1; // Indicate an error
    }

    // Remove the trailing newline character if it exists
    characters[strcspn(characters, "\\n")] = 0;

    // Input validation: Ensure exactly 'array_size' characters are provided.
    // A more robust solution would handle cases where fewer characters are entered
    // or implement dynamic allocation.

    // Bubble Sort algorithm to sort the characters in ascending order (based on ASCII values)
    // The outer loop controls the number of passes.
    for (outer_index = 0; outer_index < array_size - 1; outer_index++) {
        // The inner loop performs comparisons and swaps.
        // In each pass, the largest unsorted character "bubbles up" to its correct position.
        for (inner_index = 0; inner_index < array_size - 1 - outer_index; inner_index++) {
            // If the current character is greater than the next character, swap them
            if (characters[inner_index] > characters[inner_index + 1]) {
                temp = characters[inner_index];
                characters[inner_index] = characters[inner_index + 1];
                characters[inner_index + 1] = temp;
            }
        }
    }

    printf("Sorted characters (ascending order):\\n");
    // Print the sorted characters
    for (outer_index = 0; outer_index < array_size; outer_index++) {
        printf("%c ", characters[outer_index]);
    }
    printf("\\n"); // Print a newline at the end

    return 0; // Indicate successful execution
}
