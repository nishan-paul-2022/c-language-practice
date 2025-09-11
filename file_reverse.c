/*
 * Purpose: Reads a text file and writes its content in reverse order to a new file.
 * Topic: File I/O, File Reversal
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char character;
    long file_size;
    long i;

    // Open the input file for reading
    input_file = fopen("FH file.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file FH file.txt");
        return EXIT_FAILURE;
    } else {
        printf("Input file FH file.txt opened successfully for reading.\n");
    }

    // Move to the end of the file to determine its size
    if (fseek(input_file, 0, SEEK_END) != 0) {
        perror("Error seeking to end of input file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Get the current position, which is the file size
    file_size = ftell(input_file);
    if (file_size == -1) {
        perror("Error getting file size");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    output_file = fopen("FH file 1.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file FH file 1.txt");
        fclose(input_file);
        return EXIT_FAILURE;
    } else {
        printf("Output file FH file 1.txt opened successfully for writing.\n");
    }

    // Read the input file in reverse and write to the output file
    // Loop from the last character (file_size - 1) down to the first character (0)
    for (i = file_size - 1; i >= 0; i--) {
        // Seek to the i-th byte from the beginning of the input file
        if (fseek(input_file, i, SEEK_SET) != 0) {
            perror("Error seeking within input file");
            fclose(input_file);
            fclose(output_file);
            return EXIT_FAILURE;
        }

        // Read the character at the current position
        character = fgetc(input_file);
        if (character == EOF) {
            // Check for read errors, but not necessarily end of file if i was 0
            if (ferror(input_file)) {
                perror("Error reading character from input file");
                fclose(input_file);
                fclose(output_file);
                return EXIT_FAILURE;
            }
        }

        // Write the character to the output file
        if (fputc(character, output_file) == EOF) {
            perror("Error writing character to output file");
            fclose(input_file);
            fclose(output_file);
            return EXIT_FAILURE;
        }
    }

    printf("File content reversed successfully.\n");

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
