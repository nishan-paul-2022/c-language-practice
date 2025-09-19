/*
 * Purpose: Compares the contents of two integer files ('files/04-file-a.txt' and 'files/04-file-b.txt')
 *          element by element. Reports "ERROR" if any mismatch is found,
 *          otherwise reports "ACCEPTED" if all elements match.
 * Topic: File Comparison, Testing Utilities
 */

#include <stdio.h>
#include <stdlib.h>

#define FILE_A "files/04-file-a.txt"
#define FILE_B "files/04-file-b.txt"

int main(void) {
    FILE *file_output, *file_input;
    int value_output, value_input;
    int mismatch_found = 0;

    printf("=== File Comparator ===\n");
    printf("Comparing integers in '%s' and '%s'...\n\n", FILE_B, FILE_A);

    file_output = fopen(FILE_B, "r");
    if (file_output == NULL) {
        perror("Error opening output file");
        return 0;
    }

    file_input = fopen(FILE_A, "r");
    if (file_input == NULL) {
        perror("Error opening input file");
        fclose(file_output);
        return 0;
    }

    while (fscanf(file_output, "%d", &value_output) == 1) {
        if (fscanf(file_input, "%d", &value_input) != 1) {
            mismatch_found = 1; 
            break;
        }

        if (value_output != value_input) {
            mismatch_found = 1; 
            break;
        }
    }

    
    if (!mismatch_found && fscanf(file_input, "%d", &value_input) == 1) {
        mismatch_found = 1;
    }

    fclose(file_output);
    fclose(file_input);

    printf("Comparison Result: %s\n", mismatch_found ? "Sample Files Do Not Match" : "Sample Files Match");

    return 0;
}
