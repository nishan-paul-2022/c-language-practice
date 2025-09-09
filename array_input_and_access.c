/*
 * Purpose: Demonstrates taking user input for an array, accessing a specific element,
 *          and shows how an array name can be used as a pointer to its first element.
 * Topic: Arrays, User Input, Array Access, Pointers to Arrays
 */

#include <stdio.h>

int main(void) {
    int numbers_array[5];
    int *pointer_to_numbers;

    printf("Enter 5 integers.\n");
    // Read 5 integers from user
    for (int i = 0; i < 5; i++) {
        // Use " %d" to consume any leading whitespace, including newlines.
        printf("Enter element %d: ", i);
        scanf(" %d", &numbers_array[i]);
    }

    // Print the element at index 3 (the fourth element) directly.
    printf("The element at index 3 is: %d\n", numbers_array[3]);

    // Equivalent to pointer_to_numbers = &numbers_array[0]
    pointer_to_numbers = numbers_array;

    // numbers_array[3] is equivalent to *(pointer_to_numbers + 3)
    printf("The element at index 3 (accessed via pointer) is: %d\n", *(pointer_to_numbers + 3));

    return 0;
}
