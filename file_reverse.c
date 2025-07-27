// Purpose: Reads a text file and writes its content in reverse order to a new file.
// Topic: File I/O, File Reversal
#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *inputFile = NULL;
    FILE *outputFile = NULL;
    char character;
    long fileSize;
    long i;

    // Open the input file for reading
    inputFile = fopen("FH file.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file FH file.txt");
        return EXIT_FAILURE; // Indicate failure
    } else {
        printf("Input file FH file.txt opened successfully for reading.\n");
    }

    // Move to the end of the file to determine its size
    if (fseek(inputFile, 0, SEEK_END) != 0) {
        perror("Error seeking to end of input file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Get the current position, which is the file size
    fileSize = ftell(inputFile);
    if (fileSize == -1) {
        perror("Error getting file size");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    outputFile = fopen("FH file 1.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file FH file 1.txt");
        fclose(inputFile);
        return EXIT_FAILURE;
    } else {
        printf("Output file FH file 1.txt opened successfully for writing.\n");
    }

    // Read the input file in reverse and write to the output file
    // Loop from the last character (fileSize - 1) down to the first character (0)
    for (i = fileSize - 1; i >= 0; i--) {
        // Seek to the i-th byte from the beginning of the input file
        if (fseek(inputFile, i, SEEK_SET) != 0) {
            perror("Error seeking within input file");
            fclose(inputFile);
            fclose(outputFile);
            return EXIT_FAILURE;
        }

        // Read the character at the current position
        character = fgetc(inputFile);
        if (character == EOF) {
            // Check for read errors, but not necessarily end of file if i was 0
            if (ferror(inputFile)) {
                perror("Error reading character from input file");
                fclose(inputFile);
                fclose(outputFile);
                return EXIT_FAILURE;
            }
        }

        // Write the character to the output file
        if (fputc(character, outputFile) == EOF) {
            perror("Error writing character to output file");
            fclose(inputFile);
            fclose(outputFile);
            return EXIT_FAILURE;
        }
    }

    printf("File content reversed successfully.\n");

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0; // Indicate success
}
