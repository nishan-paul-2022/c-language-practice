// Purpose: Demonstrates reading various data types from user input, writing them to a file, and then reading them back from the file.
// Topic: File I/O, Input/Output Functions, Data Types

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // For strcspn

#define MAX_FILENAME_LEN 100
#define MAX_STRING_LEN 100

int main() {
    FILE *file_ptr = NULL;
    char filename[MAX_FILENAME_LEN];
    char input_string[MAX_STRING_LEN];
    char read_char;
    int input_int;
    float input_float;

    char read_string[MAX_STRING_LEN];
    char read_char_from_file;
    int read_int;
    float read_float_from_file;

    // --- Input Phase ---

    // Get filename from user
    printf("Enter filename (e.g., my_data.txt): ");
    if (fgets(filename, MAX_FILENAME_LEN, stdin) == NULL) {
        perror("Error reading filename");
        return 1;
    }
    // Remove trailing newline character from filename if present
    filename[strcspn(filename, "\n")] = 0;

    // Open file for writing using the user-provided filename
    file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Get string input from user
    printf("Enter a string: ");
    if (fgets(input_string, MAX_STRING_LEN, stdin) == NULL) {
        perror("Error reading string");
        fclose(file_ptr);
        return 1;
    }
    // Remove trailing newline from input_string
    input_string[strcspn(input_string, "\n")] = 0;

    // Get character input from user
    printf("Enter a character: ");
    // Read character, consuming any leftover newline from previous input
    if (scanf(" %c", &read_char) != 1) { // Note: Using read_char as variable name here
        perror("Error reading character");
        fclose(file_ptr);
        return 1;
    }
    // Consume any remaining characters on the line after the character, including the newline
    while (getchar() != '\n');


    // Get integer and float input from user
    printf("Enter an integer and a float (e.g., 123 45.67): ");
    if (scanf("%d %f", &input_int, &input_float) != 2) {
        perror("Error reading integer and float");
        fclose(file_ptr);
        return 1;
    }
    // Consume any remaining characters on the line after the float, including the newline
    while (getchar() != '\n');


    // --- Write Phase ---
    // Write the collected data to the file
    // fprintf is suitable for writing formatted strings, characters, and numbers.
    if (fprintf(file_ptr, "%s\n", input_string) < 0) {
        perror("Error writing string to file");
        fclose(file_ptr);
        return 1;
    }
    if (fprintf(file_ptr, "%c\n", read_char) < 0) { // Writing char with newline
        perror("Error writing character to file");
        fclose(file_ptr);
        return 1;
    }
    if (fprintf(file_ptr, "%d\n", input_int) < 0) {
        perror("Error writing integer to file");
        fclose(file_ptr);
        return 1;
    }
    if (fprintf(file_ptr, "%f\n", input_float) < 0) {
        perror("Error writing float to file");
        fclose(file_ptr);
        return 1;
    }

    // Close the file after writing
    fclose(file_ptr);
    printf("Data written to '%s' successfully.\n", filename);

    // --- Read Phase ---
    // Reopen the file for reading
    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("\nReading data from '%s':\n", filename);

    // Read the string (first line)
    if (fgets(read_string, MAX_STRING_LEN, file_ptr) == NULL) {
        perror("Error reading string from file");
        fclose(file_ptr);
        return 1;
    }
    read_string[strcspn(read_string, "\n")] = 0; // Remove newline

    // Read the character
    if (fscanf(file_ptr, "%c", &read_char_from_file) != 1) {
        perror("Error reading character from file");
        fclose(file_ptr);
        return 1;
    }
    // Consume the newline character after reading the character
    if (fgetc(file_ptr) == EOF && ferror(file_ptr)) { // Check for error after consuming newline
        perror("Error consuming newline after character read");
        fclose(file_ptr);
        return 1;
    }


    // Read the integer
    if (fscanf(file_ptr, "%d", &read_int) != 1) {
        perror("Error reading integer from file");
        fclose(file_ptr);
        return 1;
    }
    // Consume the newline character after reading the integer
    if (fgetc(file_ptr) == EOF && ferror(file_ptr)) {
        perror("Error consuming newline after integer read");
        fclose(file_ptr);
        return 1;
    }

    // Read the float
    if (fscanf(file_ptr, "%f", &read_float_from_file) != 1) {
        perror("Error reading float from file");
        fclose(file_ptr);
        return 1;
    }

    // Display the data read from the file
    printf("String: %s\n", read_string);
    printf("Character: %c\n", read_char_from_file);
    printf("Integer: %d\n", read_int);
    printf("Float: %.2f\n", read_float_from_file);

    // Close the file
    fclose(file_ptr);

    return 0;
}
