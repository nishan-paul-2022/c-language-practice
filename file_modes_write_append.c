/*
 * Purpose: Demonstrates writing to a file using 'w' (write) and 'a' (append) modes.
 * Topic: Text File I/O, File Modes
 */

#include <stdio.h>
#include <stdlib.h> // For exit()

int main() {
    FILE *file_ptr = NULL;
    const char *first_part = "This is the first part of the text. ";
    const char *second_part = "This is the second part, appended.";

    // --- Demonstrate "w" mode (write) ---
    // Open the file in write mode ("w"). This will create the file if it doesn't exist,
    // or truncate (empty) it if it already exists.
    file_ptr = fopen("file_modes_example.txt", "w");
    if (file_ptr == NULL) {
        perror("Error opening file in 'w' mode");
        return 0;
    }

    // Write the first part of the text
    if (fprintf(file_ptr, "%s", first_part) < 0) {
        perror("Error writing first part to file");
        fclose(file_ptr);
        return 0;
    }
    printf("Wrote first part using 'w' mode.\n");

    // Close the file after writing in "w" mode
    fclose(file_ptr);

    // --- Demonstrate "a" mode (append) ---
    // Open the file in append mode ("a"). This will create the file if it doesn't exist,
    // or position the file pointer at the end of the file if it already exists.
    // Data written will be added to the end of the existing content.
    file_ptr = fopen("file_modes_example.txt", "a");
    if (file_ptr == NULL) {
        perror("Error opening file in 'a' mode");
        return 0;
    }

    // Write the second part of the text
    if (fprintf(file_ptr, "%s", second_part) < 0) {
        perror("Error writing second part to file");
        fclose(file_ptr);
        return 0;
    }
    printf("Wrote second part using 'a' mode.\n");

    // Close the file after writing in "a" mode
    fclose(file_ptr);

    printf("File 'file_modes_example.txt' updated successfully.\n");

    return 0;
}
