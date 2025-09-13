/*
 * Purpose: Finds pairs of numbers in an array that sum up to a target value,
 *          where the target value is the sum of the maximum and minimum elements in the array.
 * Topic: Arrays, Finding Pairs, Max/Min Elements, Nested Loops, Target Sum
 */

#include <stdio.h>
#include <limits.h>

void get_elements(int *num_elements, int numbers[]) {
    printf("Enter the number of elements (max 100): ");
    if (scanf("%d", num_elements) != 1 || *num_elements <= 0 || *num_elements > 100) {
        printf("Invalid input. Please enter a positive integer up to 100.\n");
        *num_elements = 0;
        return;
    }

    printf("Enter %d integers:\n", *num_elements);
    for (int i = 0; i < *num_elements; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input for element at index %d.\n", i);
            *num_elements = 0;
            return;
        }
    }
}

void find_max_min(int numbers[], int num_elements, int *max_val, int *min_val) {
    if (num_elements > 0) {
        *max_val = numbers[0];
        *min_val = numbers[0];
        for (int i = 1; i < num_elements; i++) {
            if (numbers[i] > *max_val) {
                *max_val = numbers[i];
            }
            if (numbers[i] < *min_val) {
                *min_val = numbers[i];
            }
        }
    }
}

void find_and_print_pairs(int numbers[], int num_elements, int target_sum) {
    int processed_flags[100] = {0};
    printf("\nPairs that sum to %d:\n", target_sum);
    for (int i = 0; i < num_elements; i++) {
        if (processed_flags[i] == 1) {
            continue;
        }
        for (int j = i + 1; j < num_elements; j++) {
            if (processed_flags[j] == 1) {
                continue;
            }
            if (numbers[i] + numbers[j] == target_sum) {
                printf("%d %d\n", numbers[i], numbers[j]);
                processed_flags[i] = 1;
                processed_flags[j] = 1;
                break;
            }
        }
    }
}

int main(void) {
    int num_elements, numbers[100];

    get_elements(&num_elements, numbers);

    if (num_elements == 0) {
        return 0;
    }

    int max_val, min_val;
    find_max_min(numbers, num_elements, &max_val, &min_val);

    int target_sum = max_val + min_val;
    printf("\nTarget sum (max + min) is: %d\n", target_sum);

    find_and_print_pairs(numbers, num_elements, target_sum);

    return 0;
}
