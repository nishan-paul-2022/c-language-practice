/*
 * Purpose: Copies the content of an input file ('FH file.txt') to an output file
 *          ('FH file 1.txt') by reading it character by character after determining
 *          the file size using fseek() and ftell().
 * Topic: File I/O, File Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILENAME "FH_file.txt"
#define OUTPUT_FILENAME "FH_file_1.txt"

int main(void) {
    FILE *file_input, *file_output;
    char character;
    long file_size; // Use long for file size, as returned by ftell

    // Open the input file in read mode
    file_input = fopen(INPUT_FILENAME, "r");
    if (file_input == NULL) {
        perror("Error opening input file");
        fprintf(stderr, "Please ensure '%s' exists.\n", INPUT_FILENAME);
        return EXIT_FAILURE;
    }

    // Move the file position indicator to the end of the file
    if (fseek(file_input, 0, SEEK_END) != 0) {
        perror("Error seeking to end of input file");
        fclose(file_input);
        return EXIT_FAILURE;
    }

    // Get the current file position, which is the size of the file
    file_size = ftell(file_input);
    if (file_size == -1) {
        perror("Error getting file size");
        fclose(file_input);
        return EXIT_FAILURE;
    }

    // Move the file position indicator back to the beginning of the file
    if (fseek(file_input, 0, SEEK_SET) != 0) {
        perror("Error seeking to beginning of input file");
        fclose(file_input);
        return EXIT_FAILURE;
    }

    // Open the output file in write mode
    file_output = fopen(OUTPUT_FILENAME, "w");
    if (file_output == NULL) {
        perror("Error opening output file");
        fclose(file_input); // Close input file before exiting
        return EXIT_FAILURE;
    }

    // Read from the input file character by character and write to the output file
    // The loop iterates 'file_size' times.
    // Note: For text files, file_size might not be exact due to line ending translations.
    // However, this method is common for demonstrating file I/O.
    printf("Copying content from '%s' to '%s'...\n", INPUT_FILENAME, OUTPUT_FILENAME);
    while (file_size > 0) {
        character = fgetc(file_input);
        // Check for read errors or EOF during character read
        if (character == EOF) {
            if (ferror(file_input)) {
                perror("Error reading character from input file");
            } else if (feof(file_input)) {
                // This should ideally not happen if file_size was correct and > 0
                // but can occur if file size calculation was off or file changed.
                printf("Warning: Reached EOF before expected based on file size.\n");
            }
            // Break loop if read error or unexpected EOF
            break; 
        }
        
        if (fputc(character, file_output) == EOF) {
            perror("Error writing character to output file");
            // Break loop if write error occurs
            break;
        }
        
        file_size--; // Decrement the counter
    }

    // Close the files
    if (fclose(file_input) != 0) {
        perror("Error closing input file");
        // Continue to close output file even if input file closing failed
    }
    if (fclose(file_output) != 0) {
        perror("Error closing output file");
        return EXIT_FAILURE;
    }

    printf("File copy complete.\n");

    return 0;
}
