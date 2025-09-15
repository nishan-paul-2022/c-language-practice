/*
 * Purpose: To swap the values of three variables.
 * Topic: Variables, Basic I/O, Functions
 */

#include <stdio.h>

// Function to swap three integers in the order: x → y, y → z, z → x
void swap_three(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

// Function to print the values with a title
void print_values(const char *title, int x, int y, int z) {
    printf("%s\n", title);
    printf("x = %d, y = %d, z = %d\n\n", x, y, z);
}

int main(void) {
    int x, y, z;

    printf("--- Three-Variable Swapping Program ---\n\n");

    // Input three integers
    printf("Enter three integer values (x y z): ");
    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("[ERROR] Invalid input. Please enter three integers.\n");
        return 0;
    }

    // Print values before swapping
    print_values("Before swapping:", x, y, z);

    // Swap values
    swap_three(&x, &y, &z);

    // Print values after swapping
    print_values("After swapping:", x, y, z);

    return 0;
}
