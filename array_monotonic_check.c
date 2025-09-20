/*
 * Purpose: Counts elements in an array that are strictly increasing or strictly decreasing relative to all preceding elements.
 * Topic: Arrays, Loops, Conditional Logic
 */

#include <stdio.h>

int main(void) {
    int num_test_cases;
    printf("Enter number of test cases: ");
    scanf("%d", &num_test_cases);

    int numbers[num_test_cases];

    for (int i = 0; i < num_test_cases; i++) {
        printf("Element %d: ", i);
        scanf("%d", &numbers[i]);
    }
    
    int count_monotonic_elements = 0;
    int monotonic_elements[num_test_cases]; 
    int monotonic_count = 0; 
    
    for (int i = 1; i < num_test_cases; i++) {
        int is_strictly_increasing = 1; 
        int is_strictly_decreasing = 1; 
        
        for (int j = 0; j < i; j++) {
            if (numbers[i] <= numbers[j]) {
                is_strictly_increasing = 0; 
            }
            if (numbers[i] >= numbers[j]) {
                is_strictly_decreasing = 0; 
            }
        }
        
        if (is_strictly_increasing || is_strictly_decreasing) {
            count_monotonic_elements++;
            monotonic_elements[monotonic_count] = i; 
            monotonic_count++;
        }
    }

    printf("\nCount: %d\n", count_monotonic_elements);
    
    if (count_monotonic_elements > 0) {
        printf("Monotonic elements: ");
        for (int i = 0; i < monotonic_count; i++) {
            printf("%d", numbers[monotonic_elements[i]]);
            if (i < monotonic_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
        
        printf("At positions: ");
        for (int i = 0; i < monotonic_count; i++) {
            printf("%d", monotonic_elements[i]);
            if (i < monotonic_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("No monotonic elements found.\n");
    }

    return 0;
}

