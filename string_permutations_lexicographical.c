// Purpose: Generates and prints all permutations of a string in lexicographical order.
// Topic: String Permutations, Sorting Algorithms

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compare two characters for qsort. */
int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}

// A utility function to swap two characters a and b
void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h)
{
    // Initialize index of ceiling element
    int ceilIndex = l;

    // Iterate through the rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l + 1; i <= h; i++) {
        if (str[i] > first && str[i] < str[ceilIndex]) {
            ceilIndex = i;
        }
    }
    return ceilIndex;
}

// Function to generate and print all permutations of str in sorted order
void generate_sorted_permutations(char str[])
{
    // Get size of string
    int size = strlen(str);

    // Sort the string in increasing order to start with the lexicographically smallest permutation
    qsort(str, size, sizeof(str[0]), compare);

    // Print permutations one by one
    int isFinished = 0;
    while (!isFinished)
    {
        // Print the current permutation
        static int permutation_count = 1;
        printf("%5d  %s \n", permutation_count++, str);

        // Find the rightmost character which is smaller than its next character.
        // Let us call it 'pivot character'.
        int i;
        for (i = size - 2; i >= 0; --i) {
            if (str[i] < str[i+1]) {
                break;
            }
        }

        // If no such character is found, all characters are sorted in decreasing order,
        // meaning we have printed the last permutation.
        if (i == -1) {
            isFinished = 1;
        } else {
            // Find the smallest character to the right of the pivot character
            // that is greater than the pivot character.
            int ceilIndex = findCeil(str, str[i], i + 1, size - 1);

            // Swap the pivot character with the found character
            swap(&str[i], &str[ceilIndex]);

            // Sort the substring to the right of the pivot character in ascending order
            // to get the lexicographically next permutation.
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
        }
    }
}

// Driver program to test above function
int main()
{
    char input_string[100]; // Buffer to store user input

    printf("Enter a string: ");
    // Use fgets for safe input to prevent buffer overflows
    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        // Remove the trailing newline character if fgets read one
        char *newline = input_string;
        while (*newline != '\n' && *newline != '\0') {
            newline++;
        }
        if (*newline == '\n') {
            *newline = '\0';
        }

        printf("Permutations of the string \"%s\" are:\n", input_string);
        generate_sorted_permutations(input_string);
    } else {
        printf("Error reading input.\n");
        return 1; // Indicate an error
    }

    return 0; // Indicate successful execution
}
