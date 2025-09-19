/*
 * Purpose: Reads integers from an input file, calculates their squares, and writes the results to an output file.
 * Topic: File I/O, Input/Output Redirection, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

FILE* open_input_file(const char* file_path) {
    FILE *input_file = fopen(file_path, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return NULL;
    } else {
        printf("%s opened successfully for reading.\n", file_path);
    }
    return input_file;
}

FILE* open_output_file(const char* file_path) {
    FILE *output_file = fopen(file_path, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return NULL;
    } else {
        printf("%s opened successfully for writing.\n", file_path);
    }
    return output_file;
}

int calculate_square(int number) {
    int square = number * number;
    return square;
}

int process_numbers(FILE* input_file, FILE* output_file) {
    int number;
    while (fscanf(input_file, "%d", &number) == 1) {
        int square = calculate_square(number);

        if (fprintf(output_file, "%d\n", square) < 0) {
            perror("Error writing to output file");
            return -1;
        }
    }

    
    if (ferror(input_file)) {
        perror("Error reading from input file");
        return -1;
    }
    
    return 0;
}

void close_files(FILE* input_file, FILE* output_file) {
    if (input_file) {
        fclose(input_file);
    }
    if (output_file) {
        fclose(output_file);
    }
}

int main(void) {
    char input_file_path[] = "files/02-input.txt";
    char output_file_path[] = "files/02-output.txt";

    FILE *input_file = open_input_file(input_file_path);
    if (input_file == NULL) {
        return 0;
    }

    FILE *output_file = open_output_file(output_file_path);
    if (output_file == NULL) {
        close_files(input_file, NULL);
        return 0;
    }

    if (process_numbers(input_file, output_file) == -1) {
        close_files(input_file, output_file);
        return 0;
    }

    printf("Squares calculated from %s and written to %s successfully.\n", input_file_path, output_file_path);

    close_files(input_file, output_file);

    return 0;
}
