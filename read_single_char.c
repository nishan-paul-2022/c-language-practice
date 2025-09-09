// Purpose: Demonstrates reading a single character from a text file and displaying it.
// Topic: Text File I/O, Reading Data

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *input_file_ptr = NULL;
    int char_read; // Use int to correctly handle EOF

    // Open the file for reading in text mode.
    input_file_ptr = fopen("FH fwrite & fread.txt", "r");
    if (input_file_ptr == NULL) {
        perror("Error opening file for reading");
        return 0;
    }

    // Read a single character from the file
    char_read = getc(input_file_ptr);

    // Check if reading was successful or if it was EOF
    if (char_read == EOF) {
        if (ferror(input_file_ptr)) {
            perror("Error reading character from file");
        } else {
            printf("File is empty or could not read the first character.\n");
        }
        fclose(input_file_ptr);
        return 0; or empty file
    }

    // Print the character read to the console
    printf("First character read from file: %c\n", (char)char_read);

    // Close the file
    fclose(input_file_ptr);

    return 0; // Indicate success
}
