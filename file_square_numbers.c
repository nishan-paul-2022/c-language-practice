/*
 * Purpose: Reads numbers from an input file, calculates their squares, and writes the squares to an output file.
 * Topic: File I/O (fopen, fprintf, fscanf, fclose) - Note: Does not use freopen despite filename.
 */

#include <stdio.h>
#include <stdlib.h>

int create_input_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error creating input file");
        return -1;
    }

    for (int i = 1; i <= 1000; i++) {
        fprintf(file, "%d\n", i);
    }

    if (fclose(file)) {
        perror("Error closing input file after writing");
        return -1;
    }

    return 0;
}

int process_files(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file for reading");
        return -1;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file for writing");
        fclose(input_file);
        return -1;
    }

    int number;
    while (fscanf(input_file, "%d", &number) == 1) {
        int square = number * number;
        fprintf(output_file, "%d\n", square);
    }

    if (!feof(input_file)) {
        perror("Error reading from input file");
        fclose(input_file);
        fclose(output_file);
        return -1;
    }

    if (fclose(input_file)) {
        perror("Error closing input file after reading");
        return -1;
    }
    if (fclose(output_file)) {
        perror("Error closing output file");
        return -1;
    }

    return 0;
}

int main(void) {
    const char *input_filename = "files/file_square_numbers_a.txt";
    const char *output_filename = "files/file_square_numbers_b.txt";

    if (create_input_file(input_filename) != 0) {
        return 0;
    }

    if (process_files(input_filename, output_filename) == 0) {
        printf("Square calculation complete. Results are in %s.\n", output_filename);
    } else {
        fprintf(stderr, "Failed to process files.\n");
    }

    return 0;
}
