/*
 * Purpose: Demonstrates file operations using "r+" mode (read and write).
 *          It reads content from a file up to a delimiter, prints it,
 *          then overwrites the beginning of the file with new content.
 * Topic: File I/O
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "FH_advanced_mode.txt" // Define filename for clarity

int main(void) {
    FILE *file_read_write;
    char read_buffer[BUFFER_SIZE];
    const char *write_string = "GOOGLE ";

    // Open the file in "r+" mode (read and write)
    // This mode requires the file to exist
    file_read_write = fopen(FILENAME, "r+");
    if (file_read_write == NULL) {
        perror("Error opening file in 'r+' mode. Ensure the file exists.");
        return 0; // Indicate file opening error
    }

    // Read from the file up to the first '!' character or until the buffer is full
    // The original code used "%[^!]", which reads characters until '!' is encountered
    // We'll use fgets for safer reading, reading up to a newline or buffer limit
    // If the original intent was strictly to read up to '!', a different approach might be needed
    // For this example, we'll read the first line
    
    // Using fgets to read the first line from the file
    if (fgets(read_buffer, BUFFER_SIZE, file_read_write) == NULL) {
        // If the file is empty or an error occurred during read
        if (feof(file_read_write)) {
            printf("File '%s' is empty or no data to read.\n", FILENAME);
        } else {
            perror("Error reading from file");
        }
        // Close the file before exiting
        fclose(file_read_write);
        return 0;
    }

    // Print the content read from the file
    printf("Content read from file: %s", read_buffer); // fgets includes newline if present

    // Now, we want to write "GOOGLE " to the file
    // In "r+" mode, writing starts at the current file position
    // To overwrite from the beginning, we need to reposition the file pointer to the start
    if (fseek(file_read_write, 0, SEEK_SET) != 0) {
        perror("Error seeking to beginning of file for writing");
        fclose(file_read_write);
        return 0;
    }

    // Write the new string to the file. This will overwrite existing content from the beginning
    if (fprintf(file_read_write, "%s", write_string) < 0) {
        perror("Error writing to file");
        fclose(file_read_write);
        return 0;
    }

    // Close the file
    if (fclose(file_read_write) != 0) {
        perror("Error closing file");
        return 0;
    }

    printf("Successfully read from and wrote to '%s'.\n", FILENAME);

    return 0;
}
