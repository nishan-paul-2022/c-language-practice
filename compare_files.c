/*
 * Purpose: Compares the contents of two integer files ('files/04-input.txt' and 'files/04-output.txt')
 *          element by element. Reports "ERROR" if any mismatch is found,
 *          otherwise reports "ACCEPTED" if all elements match.
 * Topic: File Comparison, Testing Utilities
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "files/04-input.txt"
#define OUTPUT_FILE "files/04-output.txt"

int main(void) {
    FILE *file_output, *file_input;
    int value_output, value_input;
    int mismatch_found = 0;

    printf("=== File Comparator ===\n");
    printf("Comparing integers in '%s' and '%s'...\n\n", OUTPUT_FILE, INPUT_FILE);

    file_output = fopen(OUTPUT_FILE, "r");
    if (file_output == NULL) {
        perror("Error opening output file");
        return 0;
    }

    file_input = fopen(INPUT_FILE, "r");
    if (file_input == NULL) {
        perror("Error opening input file");
        fclose(file_output);
        return 0;
    }

    while (fscanf(file_output, "%d", &value_output) == 1) {
        if (fscanf(file_input, "%d", &value_input) != 1) {
            mismatch_found = 1; // Input file ended prematurely
            break;
        }

        if (value_output != value_input) {
            mismatch_found = 1; // Values don't match
            break;
        }
    }

    // Check for excess data in input file
    if (!mismatch_found && fscanf(file_input, "%d", &value_input) == 1) {
        mismatch_found = 1;
    }

    fclose(file_output);
    fclose(file_input);

    printf("Comparison Result: %s\n", mismatch_found ? "ERROR" : "ACCEPTED");

    return 0;
}
