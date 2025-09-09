/*
 * Purpose: Calculates the maximum, minimum, and average of an array of integers.
 * Topic: Array Operations, Max/Min, Average Calculation
 */

#include <stdio.h>

// Function: find_maximum
int find_maximum(int numbers[], int size) {
    if (size <= 0) {
        return 0; // Indicates an error or default value for empty/invalid arrays.
    }
    int maximum = numbers[0];
    for (int index = 1; index < size; index++) {
        if (numbers[index] > maximum) {
            maximum = numbers[index];
        }
    }
    return maximum;
}

// Function: find_minimum
int find_minimum(int numbers[], int size) {
    if (size <= 0) {
        return 0; // Indicates an error or default value for empty/invalid arrays.
    }
    int minimum = numbers[0];
    for (int index = 1; index < size; index++) {
        if (numbers[index] < minimum) {
            minimum = numbers[index];
        }
    }
    return minimum;
}

// Function: calculate_average
float calculate_average(int numbers[], int size) {
    if (size <= 0) {
        return 0.0f; // Returns 0.0 for average of empty array.
    }
    long long sum = 0; // Use long long for sum to prevent overflow with large arrays/values.
    for (int index = 0; index < size; index++) {
        sum += numbers[index];
    }
    return (float)sum / size;
}

int main() {
    int size; // Number of elements in the array.
    int i; // Loop counter.

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1) {
        fprintf(stderr, "Error: Invalid input for array size.\n");
        return 1; // Indicates an error.
    }

    if (size <= 0) {
        fprintf(stderr, "Error: Array size must be positive.\n");
        return 1; // Indicates an error.
    }

    int numbers[size]; // Declares array with Variable Length Array (VLA).

    printf("Enter %d integers separated by spaces:\n", size);
    for (i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Error: Invalid input for element %d.\n", i + 1);
            return 1; // Indicates an error.
        }
    }

    int maximum = find_maximum(numbers, size);
    int minimum = find_minimum(numbers, size);
    float average = calculate_average(numbers, size);

    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);
    printf("Average: %.2f\n", average); // Displays average with 2 decimal places.

    return 0;
}
