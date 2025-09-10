/*
 * Purpose: Reads integers from an input file, calculates their squares, and writes the results to an output file.
 * Topic: File I/O, Input/Output Redirection, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    int number;
    int square;

    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file input.txt");
        return EXIT_FAILURE;
    } else {
        printf("Input file input.txt opened successfully for reading.\n");
    }

    // Open output file
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file output.txt");
        fclose(input_file);
        return EXIT_FAILURE;
    } else {
        printf("Output file output.txt opened successfully for writing.\n");
    }

    // Read numbers and calculate squares
    printf("Calculating squares...\n");
    while (fscanf(input_file, "%d", &number) == 1) {
        square = number * number;
        // Write squared number to output file
        if (fprintf(output_file, "%d\n", square) < 0) {
            perror("Error writing to output file");
            fclose(input_file);
            fclose(output_file);
            return EXIT_FAILURE;
        }
    }

    // Check for read errors
    if (ferror(input_file)) {
        perror("Error reading from input file");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    printf("Squares calculated and written successfully.\n");

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
