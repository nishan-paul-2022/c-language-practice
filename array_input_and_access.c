/*
 * Purpose: Demonstrates taking user input for an array, accessing a specific element,
 *          and shows how an array name can be used as a pointer to its first element.
 * Topic: Arrays, User Input, Array Access, Pointers to Arrays
 */

#include <stdio.h>

int main(void) {
    int numbers_array[5];
    int *pointer_to_numbers;

    printf("Enter 5 integers line by line.\n");

    for (int i = 0; i < 5; i++) {
        printf("Enter element at index %d: ", i);
        scanf(" %d", &numbers_array[i]); 
    }
    
    printf("The element at index 3 is %d\n", numbers_array[3]);
    
    pointer_to_numbers = numbers_array;

    printf("The element at index 3 (accessed via pointer) is %d\n", *(pointer_to_numbers + 3));

    return 0;
}
