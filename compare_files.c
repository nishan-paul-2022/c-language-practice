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
    int mismatch_found = 0; // Flag to track if any mismatch occurred

    // Open the files for reading
    file_output = fopen(OUTPUT_FILE, "r");
    if (file_output == NULL) {
        perror("Error opening output file for reading");
        return EXIT_FAILURE;
    }

    file_input = fopen(INPUT_FILE, "r");
    if (file_input == NULL) {
        perror("Error opening input file for reading");
        fclose(file_output); // Close previously opened file
        return EXIT_FAILURE;
    }

    // Read integers from both files simultaneously and compare them
    // The loop continues as long as we can successfully read an integer from the output file.
    while (fscanf(file_output, "%d", &value_output) == 1) {
        // Try to read an integer from the input file.
        // If reading from input file fails or returns fewer than 1 item, it's a mismatch.
        if (fscanf(file_input, "%d", &value_input) != 1) {
            mismatch_found = 1; // Mismatch: input file ended prematurely or had invalid data
            break; // Exit the loop
        }

        // Compare the values read from both files
        if (value_output != value_input) {
            mismatch_found = 1; // Mismatch found
            break; // Exit the loop
        }
    }

    // After the loop, check if the input file still has data while output file has ended.
    // This indicates a mismatch (input file has more data).
    if (!mismatch_found && fscanf(file_input, "%d", &value_input) == 1) {
        mismatch_found = 1;
    }

    // Close the files
    fclose(file_output);
    fclose(file_input);

    // Print the result based on whether a mismatch was found
    if (mismatch_found) {
        printf("ERROR\n");
    } else {
        printf("ACCEPTED\n");
    }

    return 0;
}
