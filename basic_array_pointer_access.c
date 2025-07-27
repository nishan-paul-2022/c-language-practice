// Purpose: Demonstrates basic array input and access using pointers in C.
// Topic: Pointers, Arrays

#include <stdio.h>

int main() {
    int arr[100]; // Declare an array of 100 integers

    // Prompt the user to enter an integer
    printf("Enter an integer: ");

    // Read an integer from the user and store it in the first element of the array.
    // 'arr' decays to a pointer to the first element, so '&arr[0]' is equivalent to 'arr'.
    if (scanf("%d", arr) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Print the entered integer using pointer arithmetic.
    // '*arr' dereferences the pointer to the first element, giving its value.
    printf("You entered: %d\n", *arr);

    return 0; // Indicate successful execution
}
