/*
 * Purpose: Demonstrates swapping two integer values using pass-by-pointer.
 * Topic: Pointers, Function Parameters, Swapping Variables
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int *ptr2) {
    int temp;

    if (ptr1 == NULL || ptr2 == NULL) {
        fprintf(stderr, "Error: Invalid pointers passed to swap function.\n");
        return;
    }

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int get_two_integers(int *num1, int *num2) {
    printf("Enter two integers: ");
    return scanf("%d %d", num1, num2);
}

void display_values(int num1, int num2, const char *stage) {
    printf("%s num1 = %d, num2 = %d\n", stage, num1, num2);
}

void clear_input_buffer(void) {
    while (getchar() != '\n');
}

int main(void) {
    int num1, num2;

    if (get_two_integers(&num1, &num2) == 2) {
        display_values(num1, num2, "Before swap:");
        swap(&num1, &num2);
        display_values(num1, num2, "After swap: ");
    } else {
        fprintf(stderr, "Error: Invalid input. Please enter two integers.\n");
        clear_input_buffer();
    }

    return 0;
}
