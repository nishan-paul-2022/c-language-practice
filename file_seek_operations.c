// Purpose: Demonstrates various uses of fseek with different whence values (SEEK_CUR) and data types.
// Topic: File I/O (fseek, fgets, fscanf, puts, printf, sprintf)

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE, EXIT_SUCCESS
#include <string.h> // For strlen (if needed for input handling)

int main() {
    FILE *file_ptr = NULL;          // File pointer
    char input_buffer_s[100];       // Buffer for initial string input
    char input_buffer_t[100];       // Buffer for reading string from file
    char read_buffer[100];          // General buffer for reading strings
    int num1, num2, num3, num4, num5; // Variables for integer inputs and reads
    int read_num1, read_num2, read_num3; // Variables for integers read after fseek

    // --- Input ---
    printf("Enter an integer, another integer, and a string (e.g., 10 20 some_text): ");
    // Using scanf for integers and a single word string.
    if (scanf("%d %d %99s", &num1, &num2, input_buffer_s) != 3) {
        perror("Error reading input");
        return EXIT_FAILURE;
    }
    // Consume the rest of the line, including the newline character
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // --- Formatting input into a string ---
    // sprintf formats data into a string buffer
    char formatted_string[256];
    sprintf(formatted_string, "%d %d %s", num1, num2, input_buffer_s);

    // --- File Operations ---
    // Open FH fseek.txt in read mode ("r").
    file_ptr = fopen("FH fseek.txt", "r");
    if (file_ptr == NULL) {
        perror("Error opening FH fseek.txt for reading");
        // If the file doesn't exist, we can't proceed with fseek examples.
        // For demonstration, we'll assume it exists or create it if needed.
        // In a real scenario, you might create it here if it's missing.
        // For this example, we'll create it with some sample data.
        printf("Creating FH fseek.txt with sample data...\n");
        file_ptr = fopen("FH fseek.txt", "w"); // Open in write mode to create/overwrite
        if (file_ptr == NULL) {
            perror("Error creating FH fseek.txt");
            return EXIT_FAILURE;
        }
        // Write some sample data that includes strings and numbers
        fprintf(file_ptr, "SampleString12345 10 20 30 40 50\n");
        fclose(file_ptr); // Close and reopen in read mode
        file_ptr = fopen("FH fseek.txt", "r");
        if (file_ptr == NULL) {
            perror("Error reopening FH fseek.txt for reading");
            return EXIT_FAILURE;
        }
    }

    // --- First fseek and read ---
    // Move the file position indicator forward by 3 characters from the current position (SEEK_CUR).
    // This will skip "Sam" from "SampleString12345"
    if (fseek(file_ptr, sizeof(char) * 3, SEEK_CUR) != 0) {
        perror("Error seeking in FH fseek.txt (first seek)");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    // Read the next 5 characters into input_buffer_t
    if (fgets(input_buffer_t, sizeof(input_buffer_t), file_ptr) == NULL) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file while reading after first seek.\n");
        } else {
            perror("Error reading string after first seek");
        }
        fclose(file_ptr);
        return EXIT_FAILURE;
    }
    printf("String read after first fseek (skipping 3 chars): %s\n", input_buffer_t);

    // --- Second fseek and read ---
    // Move the file position indicator forward by 5 characters from the current position (SEEK_CUR).
    // This will skip the characters after "ple" in "pleString12345" and the newline.
    if (fseek(file_ptr, sizeof(char) * 5, SEEK_CUR) != 0) {
        perror("Error seeking in FH fseek.txt (second seek)");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    // Read integers from the current file position.
    // This assumes the data format is " num1 num2 num3 num4 num5" after the previous seeks.
    // The original code read 5 integers, but the fseek might position us differently.
    // Let's adjust the read to match the expected data after the seeks.
    // The first seek skipped "Sam", leaving "pleString12345\n10 20 30 40 50\n"
    // The second seek skips "String" (10 chars), leaving "12345\n10 20 30 40 50\n"
    // So, reading "%d %d %d" should get 12345, 10, 20.
    if (fscanf(file_ptr, "%d %d %d", &num1, &num2, &num3) != 3) {
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or invalid format for first integer read after second seek.\n");
        } else {
            perror("Error reading first set of integers after second seek");
        }
        fclose(file_ptr);
        return EXIT_FAILURE;
    }
    printf("Integers read after second fseek: %d %d %d\n", num1, num2, num3);

    // --- Third fseek (moving backward) ---
    // Move the file position indicator backward by 1 character from the current position (SEEK_CUR).
    // This moves back from reading num3.
    if (fseek(file_ptr, -sizeof(char) * 1, SEEK_CUR) != 0) {
        perror("Error seeking backward in FH fseek.txt");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    // --- Fourth fseek and read ---
    // Move the file position indicator forward by 2 integers from the current position (SEEK_CUR).
    // This moves past num1 and num2 (assuming they were read correctly).
    // The original code had a syntax error here (missing whence argument).
    if (fseek(file_ptr, sizeof(int) * 2, SEEK_CUR) != 0) {
        perror("Error seeking in FH fseek.txt (fourth seek)");
        fclose(file_ptr);
        return EXIT_FAILURE;
    }

    // Read the remaining integers.
    // After the previous seeks and reads, we expect to be at num3.
    // The original code read "%d %d %d" into x, y, z.
    // Let's assume we are positioned to read num3, num4, num5.
    if (fscanf(file_ptr, "%d %d %d", &num4, &num5, &num3) != 3) { // Reusing num3 for num5
        if (feof(file_ptr)) {
            fprintf(stderr, "Reached end of file or invalid format for second integer read after fourth seek.\n");
        } else {
            perror("Error reading second set of integers after fourth seek");
        }
        fclose(file_ptr);
        return EXIT_FAILURE;
    }
    printf("Integers read after fourth fseek: %d %d %d\n", num4, num5, num3); // Printing num3 again as num5

    // Close the file
    if (fclose(file_ptr) != 0) {
        perror("Error closing FH fseek.txt");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
