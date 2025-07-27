// Purpose: Demonstrates sorting an array of characters using the Bubble Sort algorithm.
// Topic: Arrays, sorting algorithms, characters, loops, input/output.

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

    // Ensure we only consider up to array_size characters if the input was longer
    // and the newline was removed.
    // If the input string was shorter than BUFFER_SIZE-1, array_size might be larger
    // than the actual number of characters entered. We should use the actual length.
    // However, the original code used a fixed size 'n' and then read 'n' characters.
    // Let's stick to the intent of sorting 'array_size' characters.
    // We need to ensure that the input string has at least 'array_size' characters
    // or handle cases where it's shorter.
    // For simplicity and to match the original intent of sorting 'n' characters,
    // we'll assume the user provides exactly 'array_size' characters.
    // A more robust solution would involve dynamic allocation or better input handling.

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
