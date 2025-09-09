/*
 * Purpose: Reads 'n' integers into an array, calculates their sum, and then computes and prints their average.
 * Topic: Arrays, Loops, Arithmetic Operations, Type Casting
 */

#include <stdio.h> // For printf and scanf
#include <stdlib.h> // For malloc and free

int main() {
    int num_elements; // Stores the number of elements in the array
    int i; // Loop counter for array traversal
    long long int sum = 0; // Stores the sum of array elements
    double average; // Stores the calculated average

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    if (num_elements <= 0) {
        printf("Number of elements must be positive.\n");
        return 1; // Exit with error
    }

    int arr[num_elements]; // Declare Variable Length Array (VLA)

    printf("Enter %d integer elements:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (double)sum / num_elements; // Calculate average with floating-point division

    printf("Sum of elements: %lld\n", sum);
    printf("Average of elements: %.2lf\n", average);

    return 0;
}
