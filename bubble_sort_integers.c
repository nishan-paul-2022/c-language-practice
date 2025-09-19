/*
 * Purpose: Demonstrates sorting an array of integers using the Bubble Sort algorithm.
 * Topic: Arrays, sorting algorithms, loops, input/output.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_array_size() {
    int size;

    printf("Enter the number of integers to sort (max %d): ", BUFFER_SIZE);

    if (scanf("%d", &size) != 1 || size <= 0 || size > BUFFER_SIZE) {
        printf("Invalid input. Please enter a positive integer up to %d.\n", BUFFER_SIZE);
        return -1;
    }

    clear_input_buffer();

    return size;
}

int read_integers(int numbers[], int size) {
    printf("Enter %d integers, separated by newlines:\n", size);

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input for integer at position %d. Please enter integers only.\n", i + 1);
            return -1;
        }
        clear_input_buffer();
    }

    return 0;
}

void bubble_sort(int numbers[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void display_sorted_array(int numbers[], int size) {
    printf("Sorted array (ascending order):\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    
    printf("\n");
}

int main(void) {
    int numbers[BUFFER_SIZE];
    
    int array_size = get_array_size();
    if (array_size == -1) {
        return 0;
    }
    
    if (read_integers(numbers, array_size) == -1) {
        return 0;
    }
    
    bubble_sort(numbers, array_size);
    display_sorted_array(numbers, array_size);
    
    return 0;
}
