/*
 * Purpose: Demonstrates basic array input and access using pointers in C.
 * Topic: Pointers, Arrays
 */

#include <stdio.h>

int main()
{
    int array[100]; // Declare an array of 100 integers

    // Prompt the user to enter an integer
    printf("Enter an integer: ");

    // Read an integer from the user and store it in the first element of the array.
    // 'array' presents a pointer to the first element, so '&array[0]' is equivalent to 'array'.
    if (scanf("%d", array) != 1)
    {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Print the entered integer using pointer arithmetic.
    // '*array' dereferences the pointer to the first element, giving its value.
    printf("You entered: %d\n", *array);

    return 0;
}
