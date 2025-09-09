// Purpose: Demonstrates writing characters to a file and then reading them back using 'w+' mode and rewind.
// Topic: File I/O

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *file_ptr;
    char char1, char2;
    char read_char1, read_char2;

    // Prompt user for input and read two characters
    printf("Enter two characters separated by a comma (e.g., a,b): ");
    if (scanf(" %c,%c", &char1, &char2) != 2) {
        fprintf(stderr, "Error: Invalid input format.\n");
        return 0;
    }

    // Open the file for writing and reading.
    // "w+" mode truncates the file if it exists, or creates it if it doesn't.
    file_ptr = fopen("FH function.txt", "w+");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return 0;
    }

    // Write the characters to the file
    if (putc(char1, file_ptr) == EOF) {
        perror("Error writing first character to file");
        fclose(file_ptr);
        return 1;
    }
    if (putc(char2, file_ptr) == EOF) {
        perror("Error writing second character to file");
        fclose(file_ptr);
        return 1;
    }

    // Rewind the file pointer to the beginning of the file to read what was written.
    // If we had opened the file again with "w+", it would have been truncated.
    rewind(file_ptr);

    // Read the characters back from the file
    // getc returns an int, which should be checked against EOF
    int temp_read_char1 = getc(file_ptr);
    if (temp_read_char1 == EOF) {
        // Handle case where file might be empty or read error occurred
        // For this specific example, if we wrote two chars, this shouldn't happen unless there's a read error.
        if (ferror(file_ptr)) {
            perror("Error reading first character from file");
        } else {
            fprintf(stderr, "Error: Could not read first character from file.\n");
        }
        fclose(file_ptr);
        return 1;
    }
    read_char1 = (char)temp_read_char1;

    int temp_read_char2 = getc(file_ptr);
    if (temp_read_char2 == EOF) {
        if (ferror(file_ptr)) {
            perror("Error reading second character from file");
        } else {
            fprintf(stderr, "Error: Could not read second character from file.\n");
        }
        fclose(file_ptr);
        return 1;
    }
    read_char2 = (char)temp_read_char2;

    // Print the characters read from the file
    printf("Characters read from file: %c%c\n", read_char1, read_char2);

    // Close the file
    fclose(file_ptr);

    return 0; // Indicate success
}
