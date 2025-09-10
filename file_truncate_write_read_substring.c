/*
 * Purpose: Demonstrates file operations using "w+" mode (write and read).
 *          It truncates the file, writes user input, reads it back,
 *          and prints a substring of the read content.
 * Topic: File I/O, String Manipulation
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "FH_advanced_mode.txt"

int main(void) {
    FILE *file_write_read;
    char input_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    // Prompt user for input
    printf("Enter a string (at least 5 characters) to write to the file: ");
    
    // Read input safely using fgets
    if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return EXIT_FAILURE; 
    }

    // Open the file in "w+" mode (write and read)
    // "w+" truncates the file to zero length if it exists, or creates it if it doesn't.
    // It allows both writing and reading.
    file_write_read = fopen(FILENAME, "w+");
    if (file_write_read == NULL) {
        perror("Error opening file in 'w+' mode");
        return EXIT_FAILURE; // Indicate file opening error
    }

    // Write the input string to the file.
    // fprintf writes the string. Since the mode is "w+", writing starts at the beginning.
    if (fprintf(file_write_read, "%s", input_buffer) < 0) {
        perror("Error writing to file");
        fclose(file_write_read);
        return EXIT_FAILURE;
    }

    // To read from the beginning of the file after writing, we need to reposition the file pointer.
    // "w+" mode positions the pointer at the beginning for writing, but after writing,
    // it's good practice to explicitly seek to the beginning for reading.
    if (fseek(file_write_read, 0, SEEK_SET) != 0) {
        perror("Error seeking to beginning of file for reading");
        fclose(file_write_read);
        return EXIT_FAILURE;
    }

    // Read from the file up to the first newline character or until the buffer is full.
    // The original code used "%[^\n]", which reads characters until a newline is encountered.
    // Using fgets is generally safer and more robust for reading lines.
    if (fgets(read_buffer, BUFFER_SIZE, file_write_read) == NULL) {
        // If the file is empty or an error occurred during read
        if (feof(file_write_read)) {
            printf("File '%s' is empty or no data to read.\n", FILENAME);
        } else {
            perror("Error reading from file");
        }
        fclose(file_write_read);
        return EXIT_FAILURE;
    }

    // Print a substring of the content read from the file.
    // The original code printed `c2+5`, which means skipping the first 5 characters.
    // We need to ensure the string is long enough to avoid issues.
    // Let's check the length before printing the substring.
    int len = 0;
    while (read_buffer[len] != '\0' && len < BUFFER_SIZE) {
        len++;
    }

    if (len > 5) { // Ensure there are at least 6 characters to print from index 5 onwards
        printf("Substring (from 6th character): %s", read_buffer + 5);
    } else {
        printf("The string read from the file is too short to print a substring from the 6th character.\n");
    }

    // Close the file
    if (fclose(file_write_read) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}
