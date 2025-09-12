/*
 * Purpose: Demonstrates file operations using "w+" mode (write and read).
 *          It truncates the file, writes user input, reads it back,
 *          and prints a substring of the read content.
 * Topic: File I/O, String Manipulation
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define FILENAME "FH_advanced_mode.txt"

// Function to write content to the file
void writeToFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w+"); // Truncate or create and open for writing and reading
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    if (fprintf(file, "%s", content) < 0) {
        perror("Error writing to file");
    }

    fclose(file);
}

// Function to read content from the file
void readFromFile(const char *filename, char *buffer, int buffer_size) {
    FILE *file = fopen(filename, "r"); // Open for reading
    if (file == NULL) {
        perror("Error opening file for reading");
        buffer[0] = '\0'; // Ensure buffer is empty on error
        return;
    }

    if (fgets(buffer, buffer_size, file) == NULL) {
        buffer[0] = '\0'; // Ensure buffer is empty if read fails
    }

    fclose(file);
}

int main(void) {
    char input_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    // Prompt user for input
    printf("Enter a string to write to the file: ");
    if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    // Write the user input to the file
    writeToFile(FILENAME, input_buffer);

    // Read the content back from the file
    readFromFile(FILENAME, read_buffer, BUFFER_SIZE);

    // Check if the read was successful and the string is long enough
    if (read_buffer[0] != '\0') {
        printf("Content read from file: %s", read_buffer);

        // Print a substring if the string is long enough
        if (strlen(read_buffer) > 5) {
            printf("Substring (from 6th character): %s", read_buffer + 5);
        } else {
            printf("String is too short to create a substring from the 6th character.\n");
        }
    } else {
        printf("Failed to read from file or file is empty.\n");
    }

    return 0;
}
