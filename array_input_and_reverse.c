/*
 * Purpose: Reads integers into an array until a non-integer input is entered,
 *          then reverses the array and prints its elements.
 * Topic: Arrays, Input Termination, Reversal Algorithm, Loops, Input/Output
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100

void reverse_array(int arr[], int size) {
    int start_index = 0;
    int end_index = size - 1;
    
    while (start_index < end_index) {
        int temp = arr[start_index];
        arr[start_index] = arr[end_index];
        arr[end_index] = temp;
        
        start_index++;
        end_index--;
    }
}

int main(void) {
    int numbers[MAX_ARRAY_SIZE];

    printf("Enter integers (or any non-integer to stop and process):\n");
    
    int count = 0;
    while (count < MAX_ARRAY_SIZE) {
        printf("Enter element %d: ", count + 1);
        int input_value;
        if (scanf("%d", &input_value) != 1) {
            break; 
        }

        numbers[count] = input_value;
        count++;
    }
    
    if (count == 0) {
        printf("\nNo elements were entered.\n");
        return 0;
    }
    
    reverse_array(numbers, count);

    printf("\nArray after reversal:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
