/*
 * Purpose: Demonstrates basic file opening, writing, and closing operations in C.
 * Topic: File I/O (fopen, fprintf, fclose)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file_pointer; // File pointer to manage the file stream
    char filename[100];
    char mode[100];
    char input_string[100];
    char input_char;
    int input_int;
    float input_float;

    // Prompt user for filename
    printf("Enter the filename: ");
    if (scanf("%99s", filename) != 1) { // Read up to 99 chars, %s stops at whitespace
        perror("Error reading filename");
        return EXIT_FAILURE;
    }
    // Consume the rest of the line, including the newline character
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt user for file mode
    printf("Enter the file mode (e.g., 'w', 'a', 'r': ");
    if (scanf("%99s", mode) != 1) { // Read up to 99 chars for mode
        perror("Error reading file mode");
        return EXIT_FAILURE;
    }
    // Consume the rest of the line, including the newline character
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt user for data to write to the file (string)
    printf("Enter a string to write to the file: ");
    // For strings that can contain spaces, fgets is better.
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        perror("Error reading string");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character from fgets
    size_t len_string = strlen(input_string);
    if (len_string > 0 && input_string[len_string - 1] == '\n') {
        input_string[len_string - 1] = '\0';
    }

    // Prompt user for a single character
    printf("Enter a single character: ");
    // Use scanf with a space to consume leading whitespace, including newlines
    if (scanf(" %c", &input_char) != 1) {
        perror("Error reading character");
        return EXIT_FAILURE;
    }
    // Consume the rest of the line after reading the character
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt user for an integer
    printf("Enter an integer: ");
    if (scanf("%d", &input_int) != 1) {
        perror("Error reading integer");
        return EXIT_FAILURE;
    }
    // Consume the rest of the line after reading the integer
    while ((c = getchar()) != '\n' && c != EOF);

    // Prompt user for a float
    printf("Enter a float: ");
    if (scanf("%f", &input_float) != 1) {
        perror("Error reading float");
        return EXIT_FAILURE;
    }
    // Consume the rest of the line after reading the float
    while ((c = getchar()) != '\n' && c != EOF);

    // Open the file
    file_pointer = fopen(filename, mode);

    // Check if the file was opened successfully
    if (file_pointer == NULL) {
        perror("Error opening file"); // Prints a system error message
        return EXIT_FAILURE;
    }

    // Write data to the file using fprintf
    // fprintf is used for formatted output to a file stream
    fprintf(file_pointer, "String: %s\n", input_string);
    fprintf(file_pointer, "Character: %c\n", input_char);
    fprintf(file_pointer, "Integer: %d\n", input_int);
    fprintf(file_pointer, "Float: %f\n", input_float);

    // Close the file
    // fclose releases the resources associated with the file stream
    if (fclose(file_pointer) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    printf("Data successfully written to '%s' in mode '%s'.\n", filename, mode);

    return 0;
}
