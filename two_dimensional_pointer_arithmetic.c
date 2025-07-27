// Purpose: Demonstrates pointer arithmetic with a 2D array, showing how to access elements using pointer notation.
// Topic: Pointers, 2D Arrays, Pointer Arithmetic

#include <stdio.h>

int main() {
    // Declare and initialize a 2D array: 2 rows, 3 columns
    int matrix[2][3] = {
        {1, 2, 3},    // First row
        {10, 20, 30}  // Second row
    };

    // Declare an integer pointer and initialize it to point to the beginning of the 2D array.
    // When an array name is used in an expression, it decays to a pointer to its first element.
    // For a 2D array, 'matrix' decays to a pointer to its first row (which is an array of 3 integers).
    // So, 'ptrToMatrix' points to the first element of the first row (matrix[0][0]).
    int *ptrToMatrix = (int *)matrix; // Explicit cast for clarity, though often implicit

    // --- Accessing elements using pointer arithmetic ---

    // 1. Accessing matrix[1][2] (value 30)
    //    a+1: Points to the second row (matrix[1]). The type is int (*)[3].
    //    *(a+1): Dereferences to get the second row (an array). This array decays to a pointer to its first element (matrix[1][0]).
    //    *(a+1)+2: Adds 2 to the pointer to matrix[1][0], making it point to matrix[1][2].
    //    *( *(a+1)+2 ): Dereferences the pointer to get the value at matrix[1][2].
    int *ptrToElement1 = *(matrix + 1) + 2; // Pointer to matrix[1][2]
    int value1 = *ptrToElement1;            // Value at matrix[1][2]

    // 2. Accessing matrix[1][1] (value 20) using the base pointer 'ptrToMatrix'
    //    ptrToMatrix points to matrix[0][0].
    //    The 2D array elements are stored contiguously in memory:
    //    matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2]
    //    These correspond to indices 0, 1, 2, 3, 4, 5 in a 1D representation.
    //    ptrToMatrix + 5 points to the element at index 5, which is matrix[1][1].
    int *ptrToElement2 = ptrToMatrix + 5; // Pointer to matrix[1][1]
    int value2 = *ptrToElement2;          // Value at matrix[1][1]

    // Print the accessed values
    printf("Value at matrix[1][2]: %d\n", value1);
    printf("Value at matrix[1][1] (accessed via p+5): %d\n", value2);

    return 0; // Indicate successful execution
}
