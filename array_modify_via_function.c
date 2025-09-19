/*
 * Purpose: Demonstrates how a function can modify array elements passed to it.
 * Topic: Arrays, Functions, Pass-by-Reference (for arrays), Pointers
 */

#include <stdio.h>

int modify_first_element(int data_array[], int array_size) {
    if (data_array == NULL || array_size <= 0) {
        fprintf(stderr, "Invalid array or size passed.\n");
        return -1;
    }

    data_array[0] = 100;

    return data_array[0];
}

int main(void) {
    int data_array[3] = {1, 2, 3};

    printf("data_array[0]: %d\n", data_array[0]);

    int function_return_value = modify_first_element(data_array, 3);

    if (function_return_value == -1) {
        fprintf(stderr, "Function call failed.\n");
        return 0;
    }

    printf("data_array[0]: %d\n", data_array[0]);
    printf("function_return_value: %d\n", function_return_value);

    return 0;
}