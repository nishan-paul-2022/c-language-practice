/*
 * Purpose: Reads unsigned long long integers from a file and prints only the even numbers.
 * Topic: File I/O, Loops, Conditional Statements
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *filePointer;
    unsigned long long int number;
    const char *filename = "PRACTICE C/bishal.txt"; // Specify the path to the input file

    // Open the file in read mode
    filePointer = fopen(filename, "r");

    // Check if the file was opened successfully
    if (filePointer == NULL)
    {
        perror("Error opening file"); // Print error message if file opening fails
        return EXIT_FAILURE;
    }

    printf("Reading numbers from '%s' and printing even numbers:\n", filename);

    // Read numbers from the file until End-Of-File (EOF) is reached
    while (fscanf(filePointer, "%llu", &number) != EOF)
    {
        if (number % 2 == 0)
        {
            printf("%llu ", number); // Print even numbers
        }
    }
    printf("\n"); // Print a newline at the end for cleaner output

    // Close the file
    fclose(filePointer);

    return EXIT_SUCCESS;
}
