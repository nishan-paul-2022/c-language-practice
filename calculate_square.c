/*
 * Purpose: Reads integers from an input file, calculates their squares, and writes the results to an output file.
 * Topic: File I/O, Input/Output Redirection, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char input_file_path[] = "files/02-input.txt";
    char output_file_path[] = "files/02-output.txt";

    // Open input file
    FILE *input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    } else {
        printf("%s opened successfully for reading.\n", input_file_path);
    }

    // Open output file
    FILE *output_file = fopen(output_file_path, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    } else {
        printf("%s opened successfully for writing.\n", output_file_path);
    }

    // Read numbers and calculate squares
    int number;
    while (fscanf(input_file, "%d", &number) == 1) {
        int square = number * number;
        // Write squared number to output file
        if (fprintf(output_file, "%d\n", square) < 0) {
            perror("Error writing to output file");
            fclose(input_file);
            fclose(output_file);
            return EXIT_FAILURE;
        }
    }

    // Check if the loop exited due to a read error rather than end-of-file
    if (ferror(input_file)) {
        perror("Error reading from input file");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    printf("Squares calculated from %s and written to %s successfully.\n", input_file_path, output_file_path);

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
