/*
 * Purpose: Reads integers from a specified text file and calculates their sum.
 * Topic: File I/O, Reading Integers, Summation, File Pointer
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;             // File pointer to manage the input file.
    long number;                // Variable to store each number read from the file.
    long total_sum = 0;         // Variable to accumulate the sum of numbers.
    const char *input_filename = "subin_2nd_data.txt"; // Name of the input file.

    // Open the input file in read mode ("r").
    // It's assumed that "subin_2nd_data.txt" exists in the same directory
    // or a location accessible by the program.
    file_ptr = fopen(input_filename, "r");

    // Check if the file was opened successfully.
    if (file_ptr == NULL) {
        perror("Error opening file"); // Print system error message.
        fprintf(stderr, "Could not open file: %s\n", input_filename);
        return EXIT_FAILURE; // Indicate an error occurred.
    }

    // Read numbers from the file until the end of the file (EOF) is reached.
    // fscanf returns the number of items successfully read, or EOF if an error occurs or end of file is reached.
    while (fscanf(file_ptr, "%ld", &number) == 1) {
        // Add the successfully read number to the total sum.
        total_sum += number;
    }

    // Check if fscanf stopped due to an error other than EOF.
    if (ferror(file_ptr)) {
        perror("Error reading from file");
        fprintf(stderr, "An error occurred while reading from %s.\n", input_filename);
        fclose(file_ptr); // Close the file before exiting.
        return EXIT_FAILURE; // Indicate an error occurred.
    }

    // Print the calculated total sum.
    printf("The sum of numbers in the file is: %ld\n", total_sum);

    // Close the file to free up system resources.
    fclose(file_ptr);

    return 0;
}
