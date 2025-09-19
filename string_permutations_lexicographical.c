/*
 * Purpose: Generates and prints all permutations of a string in lexicographical order.
 * Topic: String Permutations, Sorting Algorithms
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_chars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void swap_chars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int find_ceil_index(char str[], char first, int left, int right) {
    int ceil_index = left;

    for (int i = left + 1; i <= right; i++) {
        if (str[i] > first && str[i] < str[ceil_index]) {
            ceil_index = i;
        }
    }

    return ceil_index;
}

void generate_lex_permutations(char str[]) {
    int size = strlen(str);
    qsort(str, size, sizeof(str[0]), compare_chars);

    int finished = 0;
    int count = 1;

    while (!finished) {
        printf("%5d  %s\n", count++, str);

        int i;
        for (i = size - 2; i >= 0; i--) {
            if (str[i] < str[i + 1]) {
                break;
            }
        }

        if (i == -1) {
            finished = 1;
        } else {
            int ceil_index = find_ceil_index(str, str[i], i + 1, size - 1);
            swap_chars(&str[i], &str[ceil_index]);
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare_chars);
        }
    }
}

int main(void) {
    char input_string[100];

    printf("Enter a string: ");

    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        input_string[strcspn(input_string, "\n")] = 0;
        printf("Permutations of \"%s\":\n", input_string);
        generate_lex_permutations(input_string);
    } else {
        printf("Error reading input.\n");
        return 0;
    }

    return 0;
}
