/*
 * Purpose: Calculates the maximum, minimum, sum, and average of an array of integers.
 * Topic: Array Operations, Max/Min, Sum, Average Calculation
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

int calculate_sum(int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }

    int sum = 0;
    for (int index = 0; index < size; index++) {
        sum += numbers[index];
    }

    return sum;
}

float calculate_average(int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }

    int sum = calculate_sum(numbers, size);
    float average = (float)sum / size;
    return average;
}

int main(void) {
    int size;

    printf("Enter the number of elements in the array: ");
    if (scanf("%d", &size) != 1) {
        fprintf(stderr, "Invalid input for array size.\n");
        return 0;
    }

    if (size <= 0) {
        fprintf(stderr, "Array size must be positive.\n");
        return 0;
    }

    printf("Enter %d integers separated by space or newline:\n", size);
    int numbers[size];
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            fprintf(stderr, "Invalid input for element %d.\n", i + 1);
            return 0;
        }
    }

    int maximum = find_maximum(numbers, size);
    printf("Maximum: %d\n", maximum);

    int minimum = find_minimum(numbers, size);
    printf("Minimum: %d\n", minimum);
    
    int sum = calculate_sum(numbers, size);
    printf("Sum: %d\n", sum);
    
    float average = calculate_average(numbers, size);
    printf("Average: %.2f\n", average);

    return 0;
}