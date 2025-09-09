/*
 * Purpose: Calculates the maximum, minimum, and average of an array of integers.
 * Topic: Array Operations, Max/Min, Average Calculation
 */

#include <stdio.h>

int find_maximum(int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }

    int maximum = numbers[0];
    for (int index = 1; index < size; index++) {
        if (numbers[index] > maximum) {
            maximum = numbers[index];
        }
    }

    return maximum;
}

int find_minimum(int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }

    int minimum = numbers[0];
    for (int index = 1; index < size; index++) {
        if (numbers[index] < minimum) {
            minimum = numbers[index];
        }
    }

    return minimum;
}

float calculate_average(int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }

    long long sum = 0;
    for (int index = 0; index < size; index++) {
        sum += numbers[index];
    }

    return (float)sum / size;
}

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1) {
        fprintf(stderr, "Error: Invalid input for array size.\n");
        return 0;
    }

    if (size <= 0) {
        fprintf(stderr, "Error: Array size must be positive.\n");
        return 0;
    }

    int numbers[size];

    printf("Enter %d integers separated by spaces:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Error: Invalid input for element %d.\n", i + 1);
            return 0;
        }
    }

    int maximum = find_maximum(numbers, size);
    int minimum = find_minimum(numbers, size);
    float average = calculate_average(numbers, size);

    printf("Maximum: %d\n", maximum);
    printf("Minimum: %d\n", minimum);
    printf("Average: %.2f\n", average);

    return 0;
}
