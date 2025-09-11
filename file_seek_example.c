/*
 * Purpose: Demonstrates using fseek to manipulate file pointers for reading and writing.
 * Topic: File I/O (fseek, fputs, fscanf, sprintf)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *file_ptr = NULL;          // File pointer
    int input_int1;                 // First integer input
    int input_int2;                 // Second integer input
    char input_string[100];         // String input
    char formatted_string[256];     // Buffer to hold formatted string for writing
    char read_string[100];          // Buffer to read string from file
    long int offset = 5;            // Offset for fseek

    // --- Input ---
    printf("Enter an integer, another integer, and a string (e.g., 10 20 hello_world): ");
    // Using scanf for integers and a single word string
    // For strings with spaces, fgets would be more appropriate
    if (scanf("%d %d %99s", &input_int1, &input_int2, input_string) != 3) {
        perror("Error reading input");
        return 0;
    }
    // Consume the rest of the line, including the newline character
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // --- Formatting input into a string ---
    // sprintf formats data into a string buffer
    sprintf(formatted_string, "%d %d %s", input_int1, input_int2, input_string);

    // --- File Operations ---
    // Open FH fseek.txt in read/write mode ("w+")
    // "w+" truncates the file if it exists, or creates it if it doesn't
    file_ptr = fopen("FH fseek.txt", "w+");
    if (file_ptr == NULL) {
        perror("Error opening FH fseek.txt");
        return 0;
    }

    // Write the formatted string to the file
    if (fputs(formatted_string, file_ptr) == EOF) {
        perror("Error writing to FH fseek.txt");
        fclose(file_ptr);
        return 0;
    }

    // --- Using fseek ---
    // Move the file position indicator to 'offset' bytes from the beginning of the file (SEEK_SET)
    // The original code had a syntax error here (missing whence argument)
    if (fseek(file_ptr, offset, SEEK_SET) != 0) {
        perror("Error seeking in FH fseek.txt");
        fclose(file_ptr);
        return 0;
    }

    // Read a string from the current file position until a newline character is encountered
    // Note: The format string "%[^\n]" reads characters until a newline
    // If the offset in fseek is not correctly placed or the data format doesn't match,
    // this read operation might not yield the expected results
    if (fscanf(file_ptr, "%99[^\n]", read_string) != 1) {
        // Check if it's EOF or a format error
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or no matching data found after seeking.\n");
        } else {
            perror("Error reading from FH fseek.txt after seeking");
        }
        fclose(file_ptr);
        return 0;
    }

    // Print the string read from the file
    printf("String read after fseek: %s\n", read_string);

    // --- Optional: Uncomment to test another fseek operation ---
    /*
    // Move the file position indicator to 10 bytes from the beginning
    if (fseek(file_ptr, 10, SEEK_SET) != 0) {
        perror("Error seeking in FH fseek.txt (second attempt)");
        fclose(file_ptr);
        return 0;
    }
    // Read again
    if (fscanf(file_ptr, "%99[^\n]", read_string) != 1) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or no matching data found after second seek.\n");
        } else {
            perror("Error reading from FH fseek.txt after second seeking");
        }
        fclose(file_ptr);
        return 0;
    }
    printf("String read after second fseek: %s\n", read_string);
    */

    // Close the file
    if (fclose(file_ptr) != 0) {
        perror("Error closing FH fseek.txt");
        return 0;
    }

    return 0;
}
