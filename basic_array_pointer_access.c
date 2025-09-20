/*
 * Purpose: Demonstrates basic array input and access using pointers.
 * Topic: Pointers, Arrays
 */

#include <stdio.h>

int main(void) {
    int array[100];

    printf("Enter an integer: ");
    
    if (scanf("%d", array) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    printf("Entered value: %d\n", *array);

    return 0;
}
