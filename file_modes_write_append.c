/*
 * Purpose: Demonstrates writing to a file using 'w' (write) and 'a' (append) modes.
 * Topic: Text File I/O, File Modes
 */

#include <stdio.h>
#include <stdlib.h>

int write_first_part(const char *filename, const char *text) {
    FILE *file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        perror("Error opening file in 'w' mode");
        return -1;
    }

    if (fprintf(file_ptr, "%s", text) < 0) {
        perror("Error writing first part to file");
        fclose(file_ptr);
        return -1;
    }

    fclose(file_ptr);
    printf("Wrote first part using 'w' mode.\n");
    return 0;
}

int append_second_part(const char *filename, const char *text) {
    FILE *file_ptr = fopen(filename, "a");
    if (file_ptr == NULL) {
        perror("Error opening file in 'a' mode");
        return -1;
    }

    if (fprintf(file_ptr, "%s", text) < 0) {
        perror("Error writing second part to file");
        fclose(file_ptr);
        return -1;
    }

    fclose(file_ptr);
    printf("Wrote second part using 'a' mode.\n");
    return 0;
}

int demonstrate_file_modes() {
    const char *filename = "files/15-input.txt";
    const char *first_part = "A promise was once made, ";
    const char *second_part = "that promise will be kept.\n";

    if (write_first_part(filename, first_part)) {
        return 0;
    }

    if (append_second_part(filename, second_part)) {
        return 0;
    }

    printf("File '%s' updated successfully.\n", filename);

    return 0;
}

int main(void) {
    demonstrate_file_modes();
    return 0;
}
