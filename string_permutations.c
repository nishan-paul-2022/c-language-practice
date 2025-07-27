// Purpose: Generates and prints all permutations of a string in lexicographical order.
// Topic: String Manipulation, Permutations, Sorting, Algorithms

#include <stdio.h>
#include <stdlib.h> // For qsort, EXIT_SUCCESS
#include <string.h>  // For strlen
#include <stdbool.h> // For bool type

/*
 * @brief Compares two characters for qsort.
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 * @return Negative if a < b, zero if a == b, positive if a > b.
 */
int compare_chars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

/*
 * @brief Swaps two characters.
 * @param a Pointer to the first character.
 * @param b Pointer to the second character.
 */
void swap_chars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * @brief Finds the index of the smallest character in str[start_index..end_index]
 *        that is greater than 'pivot_char'.
 * @param input_string The string to search within.
 * @param pivot_char The character to compare against.
 * @param start_index The starting index of the search range.
 * @param end_index The ending index of the search range.
 * @return The index of the ceiling character.
 */
int find_ceil_index(const char input_string[], char pivot_char, int start_index, int end_index) {
    int ceil_index = start_index;

    for (int i = start_index + 1; i <= end_index; i++) {
        if (input_string[i] > pivot_char && input_string[i] < input_string[ceil_index]) {
            ceil_index = i;
        }
    }
    return ceil_index;
}

/*
 * @brief Generates and prints all permutations of a given string in lexicographical order.
 * @param input_string The string for which to generate permutations.
 */
void generate_sorted_permutations(char input_string[]) {
    int string_length = strlen(input_string);
    int permutation_count = 1; // Counter for permutations

    // Sort the string in increasing order to start with the lexicographically smallest permutation
    qsort(input_string, string_length, sizeof(char), compare_chars);

    bool permutations_complete = false;
    while (!permutations_complete) {
        // Print the current permutation
        printf("%d: %s\n", permutation_count++, input_string);

        // Find the rightmost character that is smaller than its next character.
        // This is the pivot character.
        int pivot_index;
        for (pivot_index = string_length - 2; pivot_index >= 0; --pivot_index) {
            if (input_string[pivot_index] < input_string[pivot_index + 1]) {
                break; // Found the pivot
            }
        }

        // If no such character is found, it means the string is sorted in descending order,
        // which is the last permutation.
        if (pivot_index == -1) {
            permutations_complete = true;
        } else {
            // Find the smallest character to the right of the pivot that is greater than the pivot.
            int ceil_idx = find_ceil_index(input_string, input_string[pivot_index], pivot_index + 1, string_length - 1);

            // Swap the pivot character with the ceiling character.
            swap_chars(&input_string[pivot_index], &input_string[ceil_idx]);

            // Sort the substring to the right of the pivot in ascending order.
            // This ensures the next permutation is the lexicographically smallest one.
            qsort(input_string + pivot_index + 1, string_length - pivot_index - 1, sizeof(char), compare_chars);
        }
    }
}

// Driver program to test the permutation generation function
int main() {
    char input_string[] = "ACBC"; // Example string for permutation generation
    generate_sorted_permutations(input_string);
    return EXIT_SUCCESS; // Indicate successful execution
}
