/*
 * Purpose: Demonstrates file operations using "a+" mode (append and read).
 *          It reads a line from input, appends it to a file,
 *          then reads from the file up to a specified delimiter and prints it.
 * Topic: File I/O, String Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "FH_advanced_mode.txt" // Define filename for clarity

int main(void) {
    FILE *file_append_read;
    char input_buffer[BUFFER_SIZE];
    char read_buffer[BUFFER_SIZE];

    // Prompt user for input
    printf("Enter a line of text to append to the file: ");
    
    // Read input safely using fgets
    if (fgets(input_buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return EXIT_FAILURE; 
    }

    // Open the file in "a+" mode (append and read)
    // "a+" creates the file if it doesn't exist, and allows both appending and reading
    file_append_read = fopen(FILENAME, "a+");
    if (file_append_read == NULL) {
        perror("Error opening file in 'a+' mode");
        return EXIT_FAILURE; // Indicate file opening error
    }

    // Append the input string to the file
    // fprintf adds the string, and we ensure a newline is added if fgets didn't capture one
    // Note: fgets might include the newline character if it fits in the buffer
    // We'll add a newline explicitly for consistent appending
    if (fprintf(file_append_read, "\n%s", input_buffer) < 0) {
        perror("Error writing to file");
        fclose(file_append_read);
        return EXIT_FAILURE;
    }

    // To read from the beginning of the file after appending, we need to reposition the file pointer
    // The "a+" mode positions the pointer at the end for writing, but for reading,
    // we need to explicitly seek to the beginning
    if (fseek(file_append_read, 0, SEEK_SET) != 0) {
        perror("Error seeking to beginning of file");
        fclose(file_append_read);
        return EXIT_FAILURE;
    }

    // Read from the file up to the first '!' character or until the buffer is full
    // The original code used "%[^!]", which reads characters until '!' is encountered
    // We'll use fgets to read a line, which is generally safer and more common for text files
    // If the original intent was to read up to '!', we'd need a custom read or careful fscanf
    // For this example, let's read the first line that was just appended
    // If the file contains other data, reading the first line might be more robust
    
    // Let's try to mimic the original behavior of reading up to '!'
    // However, fscanf with "%[^!]" can be tricky with buffer sizes and newlines
    // A safer approach is to read line by line or character by character
    // For demonstration, let's read the first line that was just appended
    // If the file already had content, this would read the first line of that content
    
    // Using fgets to read the first line after repositioning
    if (fgets(read_buffer, BUFFER_SIZE, file_append_read) == NULL) {
        // If the file is empty or an error occurred during read
        if (feof(file_append_read)) {
            printf("File is empty or no data to read.\n");
        } else {
            perror("Error reading from file");
        }
        fclose(file_append_read);
        return EXIT_FAILURE;
    }

    // Print the content read from the file
    printf("Content read from file: %s", read_buffer); // fgets includes newline if present

    // Close the file
    if (fclose(file_append_read) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}
