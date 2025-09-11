/*
 * Purpose: Compares the contents of two integer files ('output.txt' and 'mineput.txt')
 *          element by element. Reports "ERROR" if any mismatch is found,
 *          otherwise reports "ACCEPTED" if all elements match.
 * Topic: File Comparison, Testing Utilities
 */

#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILE "output.txt"
#define INPUT_FILE "mineput.txt"

int main(void) {
    FILE *file_output, *file_input;
    int value_output, value_input;
    int mismatch_found = 0; // Flag to track mismatches

    // Open files for reading
    file_output = fopen(OUTPUT_FILE, "r");
    if (file_output == NULL) {
        perror("Error opening output file for reading");
        return 0;
    }

    file_input = fopen(INPUT_FILE, "r");
    if (file_input == NULL) {
        perror("Error opening input file for reading");
        fclose(file_output); // Close previously opened file
        return 0;
    }

    // Compare integers from both files
    // Continue while successfully reading from output file
    while (fscanf(file_output, "%d", &value_output) == 1) {
        // Try to read integer from input file
        // Failure indicates mismatch (premature end or invalid data)
        if (fscanf(file_input, "%d", &value_input) != 1) {
            mismatch_found = 1; // Mismatch: input file ended or had invalid data
            break; // Exit loop
        }

        // Compare values from both files
        if (value_output != value_input) {
            mismatch_found = 1; // Mismatch found
            break; // Exit loop
        }
    }

    // Check if input file has more data after output file ended
    // Indicates mismatch (input file has excess data)
    if (!mismatch_found && fscanf(file_input, "%d", &value_input) == 1) {
        mismatch_found = 1;
    }

    // Close files
    fclose(file_output);
    fclose(file_input);

    // Print result based on mismatch flag
    if (mismatch_found) {
        printf("ERROR\n");
    } else {
        printf("ACCEPTED\n");
    }

    return 0;
}
