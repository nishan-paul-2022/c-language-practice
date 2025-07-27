/*
 * Purpose: Demonstrates dynamic memory allocation for an array of structures using calloc,
 *          and how pointers within structures can link elements sequentially.
 * Topic: Structures, Pointers, Dynamic Memory Allocation (calloc, free), Input/Output
 */

#include <stdio.h>
#include <stdlib.h> // For calloc, free, EXIT_SUCCESS, EXIT_FAILURE
#include <string.h> // For string operations if needed, though not directly used in this version's scanf

// Define a structure named 'Record' (renamed from 'bat' for clarity)
typedef struct Record
{
    long int id;
    char name[100]; // Increased buffer size for safety, original was 100
    float value;
    struct Record *next; // Pointer to the next record in the sequence
} Record;

// Function to input data into an array of Record structures
void inputRecords(Record *recordsArray, int count)
{
    printf("Enter %d records (ID, Value, Name) separated by commas (e.g., 123, 45.67, JohnDoe):\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("Record %d: ", i + 1);
        // Use a field width for %s to prevent buffer overflow
        // Note: scanf with %s stops at whitespace. If names can have spaces, use fgets.
        if (scanf("%ld, %f, %99s", &recordsArray[i].id, &recordsArray[i].value, recordsArray[i].name) != 3)
        {
            fprintf(stderr, "Invalid input format for record %d. Exiting.\n", i + 1);
            // Clear input buffer in case of invalid input
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            exit(EXIT_FAILURE);
        }
        // Clear the rest of the line after scanf to handle remaining characters (like newline)
        while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
    }
}

// Function to output data from an array of Record structures
void outputRecords(Record *recordsArray, int count)
{
    printf("\n--- Stored Records ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Record %d: Name: %s, ID: %ld, Value: %.2f\n", i + 1, recordsArray[i].name, recordsArray[i].id, recordsArray[i].value);
    }
}

int main()
{
    int numberOfRecords;
    Record *recordsArray; // Pointer to the dynamically allocated array of structures

    printf("Enter the number of records to store: ");
    if (scanf("%d", &numberOfRecords) != 1 || numberOfRecords <= 0)
    {
        printf("Invalid number of records. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }
    // Clear the newline character left by scanf
    while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));

    // Dynamically allocate memory for an array of 'numberOfRecords' Record structures
    // calloc initializes all allocated memory to zero, which is useful for pointers (sets them to NULL)
    recordsArray = (Record *)calloc(numberOfRecords, sizeof(Record));
    if (recordsArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed. Unable to create records array.\n");
        return EXIT_FAILURE;
    }

    // Link the records sequentially using the 'next' pointer, forming a pseudo-linked list within the array
    for (int i = 0; i < numberOfRecords - 1; i++)
    {
        recordsArray[i].next = &recordsArray[i + 1];
    }
    recordsArray[numberOfRecords - 1].next = NULL; // The last record points to NULL

    // Input data into the records
    inputRecords(recordsArray, numberOfRecords);

    // Output data from the records
    outputRecords(recordsArray, numberOfRecords);

    // Free the dynamically allocated memory
    free(recordsArray);
    recordsArray = NULL; // Set pointer to NULL after freeing to prevent dangling pointer issues

    return EXIT_SUCCESS;
}
