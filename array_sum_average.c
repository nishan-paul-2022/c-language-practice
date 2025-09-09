/*
 * Purpose: Reads 'n' integers into an array, calculates their sum, and then computes and prints their average.
 * Topic: Arrays, Loops, Arithmetic Operations, Type Casting
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int number_of_elements;
    long long int sum = 0;
    double average;

    printf("Enter the number of elements: ");
    scanf("%d", &number_of_elements);

    if (number_of_elements <= 0) {
        printf("Number of elements must be positive.\n");
        return 0;
    }

    int arr[number_of_elements];

    printf("Enter %d integer elements:\n", number_of_elements);
    for (int i = 0; i < number_of_elements; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (double)sum / number_of_elements;

    printf("Sum of elements: %lld\n", sum);
    printf("Average of elements: %.2lf\n", average);

    return 0;
}
