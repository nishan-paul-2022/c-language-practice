// Purpose: Reads integers from an input file, calculates their squares, and writes the results to an output file.
// Topic: File I/O, Input/Output Redirection, Basic Arithmetic
#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *inputFile = NULL;
    FILE *outputFile = NULL;
    int number;
    int square;

    // Open the input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file input.txt");
        return EXIT_FAILURE; // Indicate failure
    } else {
        printf("Input file input.txt opened successfully for reading.\n");
    }

    // Open the output file for writing
    outputFile = fopen("mineput.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file mineput.txt");
        fclose(inputFile); // Close the already opened input file
        return EXIT_FAILURE;
    } else {
        printf("Output file mineput.txt opened successfully for writing.\n");
    }

    // Read numbers from the input file and calculate their squares
    printf("Calculating squares...\n");
    while (fscanf(inputFile, "%d", &number) == 1) {
        square = number * number;
        // Write the squared number to the output file
        if (fprintf(outputFile, "%d\n", square) < 0) {
            perror("Error writing to output file");
            fclose(inputFile);
            fclose(outputFile);
            return EXIT_FAILURE;
        }
    }

    // Check if the loop terminated due to an error other than reaching EOF
    if (ferror(inputFile)) {
        perror("Error reading from input file");
        fclose(inputFile);
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    printf("Squares calculated and written successfully.\n");

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0; // Indicate success
}
