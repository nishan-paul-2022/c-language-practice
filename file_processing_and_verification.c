/*
 * Purpose: Reads numbers from an input file, calculates a value, writes it to an output file, and verifies the output against a reference file.
 * Topic: File I/O, Input Validation, Calculation, File Comparison
 */

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *inputFile = NULL;
    FILE *mineFile = NULL; // Output file for calculated values
    FILE *outputFile = NULL; // Reference file for verification
    FILE *mineFileRead = NULL; // For reading mine.txt again

    int number_from_input;
    int calculated_value;

    // --- Part 1: Read from input.txt, calculate, write to mine.txt ---

    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input.txt for reading");
        return 0;
    }

    // Open mine.txt for writing (truncates if exists)
    mineFile = fopen("mine.txt", "w");
    if (mineFile == NULL) {
        perror("Error opening mine.txt for writing");
        fclose(inputFile); // Close previously opened file
        return 0;
    }

    // Read integers from input file, calculate, print, and write to mine.txt
    printf("Processing input.txt:\n");
    while (fscanf(inputFile, "%d", &number_from_input) == 1) {
        // Calculate m = n*n - 2*n + 1, which is (n-1)^2
        calculated_value = number_from_input * number_from_input - 2 * number_from_input + 1;

        // Print the calculated value to the console
        printf("  Input: %d, Calculated: %d\n", number_from_input, calculated_value);

        // Write the calculated value to mine.txt
        if (fprintf(mineFile, "%d\n", calculated_value) < 0) {
            perror("Error writing to mine.txt");
            fclose(inputFile);
            fclose(mineFile);
            return 0;
        }
    }

    // Check for read errors after the loop
    if (ferror(inputFile)) {
        perror("Error reading from input.txt");
        fclose(inputFile);
        fclose(mineFile);
        return 0;
    }

    // Close files after the first part
    fclose(inputFile);
    fclose(mineFile);

    // --- Part 2: Verify mine.txt against output.txt ---

    // Open output.txt for reading (reference file)
    outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        perror("Error opening output.txt for reading (reference file)");
        // If output.txt doesn't exist, we can't verify. Treat as an error or skip verification.
        // For this example, we'll treat it as an error as the original code implies its existence.
        return 0;
    }

    // Open mine.txt again for reading to compare
    mineFileRead = fopen("mine.txt", "r");
    if (mineFileRead == NULL) {
        perror("Error opening mine.txt for reading (for comparison)");
        fclose(outputFile); // Close previously opened file
        return 0;
    }

    printf("\nVerifying mine.txt against output.txt:\n");
    int val_output, val_mine;
    int comparison_result = 0; // 0: ACCEPTED, -1: ERROR

    // Read values from both files and compare
    while (fscanf(outputFile, "%d", &val_output) == 1) {
        if (fscanf(mineFileRead, "%d", &val_mine) != 1) {
            // If mine.txt has fewer numbers than output.txt
            fprintf(stderr, "  ERROR: Mismatch in number of entries. output.txt has more values than mine.txt.\n");
            comparison_result = -1;
            break;
        }

        if (val_output != val_mine) {
            fprintf(stderr, "  ERROR: Mismatch found. output.txt has %d, mine.txt has %d.\n", val_output, val_mine);
            comparison_result = -1;
            // We can break here if we only need to report the first error,
            // or continue to find all mismatches. Let's break on first error.
            break;
        }
    }

    // Check if mine.txt had more numbers than output.txt after the loop
    if (comparison_result == 0 && fscanf(mineFileRead, "%d", &val_mine) == 1) {
        fprintf(stderr, "  ERROR: Mismatch in number of entries. mine.txt has more values than output.txt.\n");
        comparison_result = -1;
    }

    // Check for read errors on either file after the loop
    if (ferror(outputFile) || ferror(mineFileRead)) {
        perror("Error during file comparison read");
        comparison_result = -1;
    }

    // Close files after comparison
    fclose(outputFile);
    fclose(mineFileRead);

    // Report final result
    if (comparison_result == 0) {
        printf("  ACCEPTED: All values match.\n");
    } else {
        printf("  ERROR: Verification failed.\n");
    }

    return comparison_result == 0 ? 0 : 1; // Return 0 for success, 1 for error
}
