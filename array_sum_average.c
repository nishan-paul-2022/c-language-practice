/*
 * Purpose: Reads 'n' integers into an array, calculates their sum, and then computes and prints their average.
 * Topic: Arrays, Loops, Arithmetic Operations, Type Casting
 */

#include <stdio.h> // Required for printf and scanf
#include <stdlib.h> // Required for malloc and free (if VLA is not desired)

int main() {
    int num_elements; // Number of elements in the array
    int i;            // Loop counter
    long long int sum = 0; // Variable to store the sum of array elements (use long long for larger sums)
    double average;   // Variable to store the calculated average

    // Prompt user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    // Check for valid number of elements
    if (num_elements <= 0) {
        printf("Number of elements must be positive.\n");
        return 1; // Indicate an error
    }

    // Declare a Variable Length Array (VLA) - C99 feature
    // For strict C89/C90, dynamic memory allocation with malloc would be used.
    int arr[num_elements];

    // Read elements into the array and calculate their sum
    printf("Enter %d integer elements:\n", num_elements);
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Add current element to sum
    }

    // Calculate the average.
    // Cast 'sum' to double before division to ensure floating-point division.
    average = (double)sum / num_elements;

    // Print the calculated sum and average, formatted to two decimal places
    printf("Sum of elements: %lld\n", sum);
    printf("Average of elements: %.2lf\n", average);

    return 0; // Indicate successful execution
}
