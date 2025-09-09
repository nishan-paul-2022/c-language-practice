// Purpose: Demonstrates reading a string from user input, writing it to a file,
//          and then reading it back from the file using fgets.
// Topic: File I/O (fopen, fputs, fgets, fclose)

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE, perror
#include <string.h> // For strlen (to remove newline from fgets)

int main() {
    FILE *output_file_ptr = NULL; // Pointer for the output file
    FILE *input_file_ptr = NULL;  // Pointer for the input file
    char user_input_string[100];  // Buffer for user's string input
    char read_string[100];        // Buffer to read the string back from the file

    // --- Input from User ---
    printf("Enter a string: ");
    // Use fgets for safe input, as gets() is unsafe.
    if (fgets(user_input_string, sizeof(user_input_string), stdin) == NULL) {
        perror("Error reading user input");
        return EXIT_FAILURE;
    }
    // Remove the trailing newline character read by fgets
    user_input_string[strcspn(user_input_string, "\n")] = '\0';

    // --- Write to File ---
    // Open the file in write mode ("w"). This creates the file if it doesn't exist,
    // or truncates it if it does.
    output_file_ptr = fopen("FH function (fgets).txt", "w");
    if (output_file_ptr == NULL) {
        perror("Error opening FH function (fgets).txt for writing");
        return EXIT_FAILURE;
    }

    // Write the user's input string to the file.
    // fputs writes a string to a stream. It does not automatically add a newline.
    if (fputs(user_input_string, output_file_ptr) == EOF) {
        perror("Error writing string to file");
        fclose(output_file_ptr); // Clean up
        return EXIT_FAILURE;
    }

    // Close the output file after writing.
    if (fclose(output_file_ptr) != 0) {
        perror("Error closing FH function (fgets).txt after writing");
        // Continue to the read operation, but report the error.
    }

    // --- Read from File ---
    // Open the same file in read mode ("r")
    input_file_ptr = fopen("FH function (fgets).txt", "r");
    if (input_file_ptr == NULL) {
        perror("Error opening FH function (fgets).txt for reading");
        return EXIT_FAILURE;
    }

    // Read a string from the file using fgets.
    // fgets reads up to n-1 characters or until a newline is encountered.
    // It includes the newline character in the buffer if read.
    if (fgets(read_string, sizeof(read_string), input_file_ptr) == NULL) {
        if (feof(input_file_ptr)) {
            fprintf(stderr, "Reached end of file unexpectedly while reading.\n");
        } else {
            perror("Error reading string from file");
        }
        fclose(input_file_ptr);
        return EXIT_FAILURE;
    }

    // Print the string read from the file.
    // puts adds a newline character after printing the string.
    printf("String read from file: ");
    puts(read_string);

    // Close the input file.
    if (fclose(input_file_ptr) != 0) {
        perror("Error closing FH function (fgets).txt after reading");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
