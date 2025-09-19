/*
 * Purpose: Reads a specified number of integers into an array and prints them in groups of three.
 * Topic: Arrays, Loops, Input/Output, Grouping Elements
 */

#include <stdio.h>

int main(void) {
    int num_elements;

    printf("Enter the number of elements: ");
    if (scanf("%d", &num_elements) != 1 || num_elements < 3) {
        printf("Please enter an integer >= 3.\n");
        return 0;
    }

    int elements[num_elements];

    printf("Enter %d integers:\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        if (scanf("%d", &elements[i]) != 1) {
            printf("Invalid input for element %d.\n", i + 1);
            return 0;
        }
    }

    printf("\nElements printed in groups of three:\n");
    for (int i = 0; i + 2 < num_elements; i += 3) {
        printf("%d %d %d\n", elements[i], elements[i + 1], elements[i + 2]);
    }

    return 0;
}
