/*
 * Purpose: Reads numbers from an input file, calculates a value, writes it to an output file, and verifies the output against a reference file.
 * Topic: File I/O, Input Validation, Calculation, File Comparison
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "files/18-input.txt"
#define OUTPUT_FILENAME "files/18-output.txt"

int process_input_file(void) {
    FILE *input_file = fopen(INPUT_FILENAME, "r");
    if (input_file == NULL) {
        perror("Error opening file for reading");
        return -1;
    }

    FILE *mine_file = fopen(OUTPUT_FILENAME, "w");
    if (mine_file == NULL) {
        perror("Error opening file for writing");
        fclose(input_file);
        return -1;
    }

    printf("Processing %s:\n", INPUT_FILENAME);
    int number_from_input;
    while (fscanf(input_file, "%d", &number_from_input) == 1) {
        int calculated_value = number_from_input * number_from_input - 2 * number_from_input + 1; // (n-1)^2

        printf("  Input: %d, Calculated: %d\n", number_from_input, calculated_value);

        if (fprintf(mine_file, "%d\n", calculated_value) < 0) {
            perror("Error writing to file");
            fclose(input_file);
            fclose(mine_file);
            return -1;
        }
    }

    if (ferror(input_file)) {
        perror("Error reading from file");
        fclose(input_file);
        fclose(mine_file);
        return -1;
    }

    fclose(input_file);
    fclose(mine_file);
    return 0;
}

int verify_files(void) {
    FILE *output_file = fopen(INPUT_FILENAME, "r");
    if (output_file == NULL) {
        perror("Error opening file for reading (reference file)");
        return -1;
    }

    FILE *mine_file_read = fopen(OUTPUT_FILENAME, "r");
    if (mine_file_read == NULL) {
        perror("Error opening filefor reading (for comparison)");
        fclose(output_file);
        return -1;
    }

    printf("\nVerifying %s against %s:\n", OUTPUT_FILENAME, INPUT_FILENAME);
    int val_output, val_mine;
    int comparison_result = 0;

    while (fscanf(output_file, "%d", &val_output) == 1) {
        if (fscanf(mine_file_read, "%d", &val_mine) != 1) {
            fprintf(stderr, "  ERROR: Mismatch in number of entries. Input file has more values than output file.\n");
            comparison_result = -1;
            break;
        }

        if (val_output != val_mine) {
            fprintf(stderr, "  ERROR: Mismatch found. Input file has %d, output file has %d.\n", val_output, val_mine);
            comparison_result = -1;
            break;
        }
    }

    if (comparison_result == 0 && fscanf(mine_file_read, "%d", &val_mine) == 1) {
        fprintf(stderr, "  ERROR: Mismatch in number of entries. output file has more values than input file.\n");
        comparison_result = -1;
    }

    if (ferror(output_file) || ferror(mine_file_read)) {
        perror("Error during file comparison read");
        comparison_result = -1;
    }

    fclose(output_file);
    fclose(mine_file_read);
    return comparison_result;
}

void display_result(int result) {
    if (result == 0) {
        printf("  Accepted: All values match.\n");
    } else {
        printf("  ERROR: Verification failed.\n");
    }
}

int main(void) {
    if (process_input_file()) {
        return 0;
    }

    int verification_result = verify_files();
    
    display_result(verification_result);

    return verification_result == 0 ? 0 : 1;
}
