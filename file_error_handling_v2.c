/*
 * Purpose: Demonstrates file error handling techniques including perror() and clearerr() functions.
 * Topic: File I/O Error Handling
 */

#include <stdio.h>
#include <stdlib.h>

void demonstrate_perror() {
    printf("=== perror() ===\n");
    FILE *file = fopen("missing.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
    }
}

void demonstrate_clearerr(const char *filename) {
    printf("\n=== clearerr() ===\n");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening test file");
        exit(1);
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    printf("Read: %s", buffer);

    fgets(buffer, sizeof(buffer), file);
    if (feof(file)) {
        printf("\nEOF reached\n");
    }

    clearerr(file);
    if (!feof(file)) {
        printf("\nEOF flag cleared\n");
    }

    fclose(file);
}

int main(void) {
    char test_file[] = "files/file_error_handling_v2.txt";

    demonstrate_perror();
    demonstrate_clearerr(test_file);

    return 0;
}
