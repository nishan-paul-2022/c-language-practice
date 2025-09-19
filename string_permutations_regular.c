/*
 * Purpose: Generates and prints all permutations of a string in lexicographical order.
 * Topic: String Manipulation, Permutations, Sorting, Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int compare_chars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void swap_chars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int find_ceil_index(const char str[], char pivot, int start, int end) {
    int ceil_index = start;

    for (int i = start + 1; i <= end; i++) {
        if (str[i] > pivot && str[i] < str[ceil_index]) {
            ceil_index = i;
        }
    }

    return ceil_index;
}

void generate_lex_permutations(char str[]) {
    int len = strlen(str);
    int count = 1;
    qsort(str, len, sizeof(char), compare_chars); 

    bool done = false;
    while (!done) {
        printf("%d: %s\n", count++, str);

        int pivot;
        for (pivot = len - 2; pivot >= 0; pivot--) {
            if (str[pivot] < str[pivot + 1]) {
                break; 
            }
        }

        if (pivot == -1) {
            done = true; 
        } else {
            int ceil_idx = find_ceil_index(str, str[pivot], pivot + 1, len - 1);
            swap_chars(&str[pivot], &str[ceil_idx]);
            qsort(str + pivot + 1, len - pivot - 1, sizeof(char), compare_chars);
        }
    }
}

int main(void) {
    char input_string[100];

    printf("Enter a string to generate permutations: ");

    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        input_string[strcspn(input_string, "\n")] = '\0';
        generate_lex_permutations(input_string);
    } else {
        printf("Error reading input.\n");
        return 0;
    }
    
    return 0;
}
