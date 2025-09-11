/*
 * Purpose: Demonstrates basic array input and access using pointers in C.
 * Topic: Pointers, Arrays
 */

#include <stdio.h>

int main(void) {
    int array[100];

    printf("Enter an integer: ");

    // array and &array[0] are both pointers to the first element of the array
    if (scanf("%d", array) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    // *array dereferences the pointer to the first element of the array
    printf("You entered: %d\n", *array);

    return 0;
}
