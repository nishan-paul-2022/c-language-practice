// Purpose: Demonstrates writing a character using `fputc` and reading it back, with corrected file handling.
// Topic: Text File I/O, Character I/O

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *file_ptr = NULL;
    char char_to_write = 's';
    int char_read; // Use int to correctly handle EOF

    // Open the file for writing and reading in text mode.
    // "w+" mode truncates the file if it exists, or creates it if it doesn't.
    file_ptr = fopen("FH putw.txt", "w+");
    if (file_ptr == NULL) {
        perror("Error opening file for writing/reading");
        return 0;
    }

    // Write a character to the file using fputc
    if (fputc(char_to_write, file_ptr) == EOF) {
        perror("Error writing character to file");
        fclose(file_ptr);
        return 1;
    }
    printf("Wrote character '%c' to file.\n", char_to_write);

    // Rewind the file pointer to the beginning of the file to read what was written.
    // This is necessary because "w+" mode allows both reading and writing,
    // but after writing, the file pointer is at the end.
    rewind(file_ptr);

    // Read a single character from the file
    char_read = getc(file_ptr);

    // Check if reading was successful or if it was EOF
    if (char_read == EOF) {
        if (ferror(file_ptr)) {
            perror("Error reading character from file");
        } else {
            printf("File is empty or could not read the first character after writing.\n");
        }
        fclose(file_ptr);
        return 0; or empty file
    }

    // Print the character read to the console
    printf("First character read from file: %c\n", (char)char_read);

    // Close the file
    fclose(file_ptr);

    return 0;
}
