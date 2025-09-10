/*
 * Purpose: Reads unsigned long long integers from a file and prints only the even numbers.
 * Topic: File I/O, Loops, Conditional Statements
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    unsigned long long int number;
    const char *filename = "bishal.txt"; // Specify the path to the input file

    // Open the file in read mode
    file_pointer = fopen(filename, "r");

    // Check if the file was opened successfully
    if (file_pointer == NULL) {
        perror("Error opening file"); // Print error message if file opening fails
        return EXIT_FAILURE;
    }

    printf("Reading numbers from '%s' and printing even numbers:\n", filename);

    // Read numbers from the file until End-Of-File (EOF) is reached
    while (fscanf(file_pointer, "%llu", &number) != EOF) {
        if (number % 2 == 0) {
            printf("%llu ", number); // Print even numbers
        }
    }
    printf("\n"); // Print a newline at the end for cleaner output

    // Close the file
    fclose(file_pointer);

    return EXIT_SUCCESS;
}