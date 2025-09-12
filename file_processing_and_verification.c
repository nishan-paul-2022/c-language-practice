/*
 * Purpose: Reads numbers from an input file, calculates a value, writes it to an output file, and verifies the output against a reference file.
 * Topic: File I/O, Input Validation, Calculation, File Comparison
 */

#include <stdio.h>
#include <stdlib.h>

// Process input file and write calculated values to output file
int process_input_file(void) {
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input.txt for reading");
        return -1;
    }

    FILE *mine_file = fopen("mine.txt", "w");
    if (mine_file == NULL) {
        perror("Error opening mine.txt for writing");
        fclose(input_file);
        return -1;
    }

    printf("Processing input.txt:\n");
    int number_from_input;
    while (fscanf(input_file, "%d", &number_from_input) == 1) {
        // Calculate m = n*n - 2*n + 1, which is (n-1)^2
        int calculated_value = number_from_input * number_from_input - 2 * number_from_input + 1;

        printf("  Input: %d, Calculated: %d\n", number_from_input, calculated_value);

        if (fprintf(mine_file, "%d\n", calculated_value) < 0) {
            perror("Error writing to mine.txt");
            fclose(input_file);
            fclose(mine_file);
            return -1;
        }
    }

    // Check for read errors
    if (ferror(input_file)) {
        perror("Error reading from input.txt");
        fclose(input_file);
        fclose(mine_file);
        return -1;
    }

    fclose(input_file);
    fclose(mine_file);
    return 0;
}

// Verify mine.txt against output.txt
int verify_files(void) {
    FILE *output_file = fopen("output.txt", "r");
    if (output_file == NULL) {
        perror("Error opening output.txt for reading (reference file)");
        return -1;
    }

    FILE *mine_file_read = fopen("mine.txt", "r");
    if (mine_file_read == NULL) {
        perror("Error opening mine.txt for reading (for comparison)");
        fclose(output_file);
        return -1;
    }

    printf("\nVerifying mine.txt against output.txt:\n");
    int val_output, val_mine;
    int comparison_result = 0;

    // Read and compare values from both files
    while (fscanf(output_file, "%d", &val_output) == 1) {
        if (fscanf(mine_file_read, "%d", &val_mine) != 1) {
            fprintf(stderr, "  ERROR: Mismatch in number of entries. output.txt has more values than mine.txt.\n");
            comparison_result = -1;
            break;
        }

        if (val_output != val_mine) {
            fprintf(stderr, "  ERROR: Mismatch found. output.txt has %d, mine.txt has %d.\n", val_output, val_mine);
            comparison_result = -1;
            break;
        }
    }

    // Check if mine.txt has more numbers than output.txt
    if (comparison_result == 0 && fscanf(mine_file_read, "%d", &val_mine) == 1) {
        fprintf(stderr, "  ERROR: Mismatch in number of entries. mine.txt has more values than output.txt.\n");
        comparison_result = -1;
    }

    // Check for read errors
    if (ferror(output_file) || ferror(mine_file_read)) {
        perror("Error during file comparison read");
        comparison_result = -1;
    }

    fclose(output_file);
    fclose(mine_file_read);
    return comparison_result;
}

// Display verification result
void display_result(int result) {
    if (result == 0) {
        printf("  ACCEPTED: All values match.\n");
    } else {
        printf("  ERROR: Verification failed.\n");
    }
}

int main(void) {
    // Process input file and generate mine.txt
    if (process_input_file()) {
        return 0;
    }

    // Verify mine.txt against output.txt
    int verification_result = verify_files();
    
    // Display final result
    display_result(verification_result);

    return verification_result == 0 ? 0 : 1;
}
