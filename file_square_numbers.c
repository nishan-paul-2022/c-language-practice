/*
 * Purpose: Reads numbers from an input file, calculates their squares, and writes the squares to an output file.
 * Topic: File I/O (fopen, fprintf, fscanf, fclose) - Note: Does not use freopen despite filename.
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE, perror

int main() {
    FILE *input_file_ptr = NULL;  // Pointer for the input file
    FILE *output_file_ptr = NULL; // Pointer for the output file
    int number;                   // Variable to store the number read from input file
    int square;                   // Variable to store the calculated square
    int counter = 1;              // Counter for writing numbers to the input file

    // --- Step 1: Create input.txt and populate it with numbers from 1 to 1000 ---

    // Open input.txt in write mode ("w"). If the file exists, its content is truncated.
    input_file_ptr = fopen("input.txt", "w");
    if (input_file_ptr == NULL) {
        perror("Error opening input.txt for writing");
        return EXIT_FAILURE;
    }

    // Write numbers from 1 to 1000 to input.txt
    while (counter <= 1000) {
        fprintf(input_file_ptr, "%d\n", counter);
        counter++;
    }

    // Close the input file after writing
    if (fclose(input_file_ptr) != 0) {
        perror("Error closing input.txt after writing");
        // Continue execution as the primary task is to process the file
    }

    // --- Step 2: Read from input.txt, calculate squares, and write to output.txt ---

    // Open input.txt in read mode ("r")
    input_file_ptr = fopen("input.txt", "r");
    if (input_file_ptr == NULL) {
        perror("Error opening input.txt for reading");
        return EXIT_FAILURE;
    }

    // Open output.txt in write mode ("w")
    output_file_ptr = fopen("output.txt", "w");
    if (output_file_ptr == NULL) {
        perror("Error opening output.txt for writing");
        fclose(input_file_ptr); // Close the already opened input file
        return EXIT_FAILURE;
    }

    // Read numbers from input.txt until the end of the file (EOF) is reached
    // fscanf returns the number of items successfully read, or EOF on failure/end of file.
    while (fscanf(input_file_ptr, "%d", &number) == 1) {
        square = number * number; // Calculate the square of the number
        fprintf(output_file_ptr, "%d\n", square); // Write the square to output.txt
    }

    // Check if the loop terminated due to an error other than EOF
    if (!feof(input_file_ptr)) {
        // If it's not EOF, it means fscanf failed for some other reason (e.g., invalid data format)
        perror("Error reading from input.txt");
        // Clean up resources before exiting
        fclose(input_file_ptr);
        fclose(output_file_ptr);
        return EXIT_FAILURE;
    }

    // Close both files after processing
    if (fclose(input_file_ptr) != 0) {
        perror("Error closing input.txt after reading");
        // Continue to close output file
    }
    if (fclose(output_file_ptr) != 0) {
        perror("Error closing output.txt");
        return EXIT_FAILURE;
    }

    printf("Successfully processed numbers and wrote squares to output.txt.\n");

    return 0;
}
