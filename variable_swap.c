/*
 * Purpose: Swaps the values of three variables.
 * Topic: Variables, Basic I/O, Functions
 */

#include <stdio.h>

void swap_three(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void print_values(const char *title, int x, int y, int z) {
    printf("%s: x = %d, y = %d, z = %d\n", title, x, y, z);
}

int main(void) {
    int x, y, z;

    printf("Enter three integer values (x y z): ");

    if (scanf("%d %d %d", &x, &y, &z) != 3) {
        printf("Invalid input. Please enter three integers.\n");
        return 0;
    }

    print_values("Before swapping", x, y, z);
    
    swap_three(&x, &y, &z);

    print_values("After swapping", x, y, z);

    return 0;
}
