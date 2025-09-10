/*
 * Purpose: Demonstrates dynamic memory allocation for an array of structures using calloc,
 *          and how pointers within structures can link elements sequentially.
 * Topic: Structures, Pointers, Dynamic Memory Allocation (calloc, free), Input/Output
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure named 'Record' (renamed from 'bat' for clarity)
typedef struct Record {
    long int id;
    char name[100]; // Increased buffer size for safety, original was 100
    float value;
    struct Record *next; // Pointer to the next record in the sequence
} Record;

// Function to input data into an array of Record structures
void input_records(Record *records_array, int count) {
    printf("Enter %d records (ID, Value, Name) separated by commas (e.g., 123, 45.67, JohnDoe):\n", count);
    for (int i = 0; i < count; i++) {
        printf("Record %d: ", i + 1);
        // Use a field width for %s to prevent buffer overflow
        // Note: scanf with %s stops at whitespace. If names can have spaces, use fgets
        if (scanf("%ld, %f, %99s", &records_array[i].id, &records_array[i].value, records_array[i].name) != 3) {
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
void output_records(Record *records_array, int count) {
    printf("\n--- Stored Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Record %d: Name: %s, ID: %ld, Value: %.2f\n", i + 1, records_array[i].name, records_array[i].id, records_array[i].value);
    }
}

int main() {
    int number_of_records;
    Record *records_array; // Pointer to the dynamically allocated array of structures

    printf("Enter the number of records to store: ");
    if (scanf("%d", &number_of_records) != 1 || number_of_records <= 0) {
        printf("Invalid number of records. Please enter a positive integer.\n");
        return EXIT_FAILURE;
    }
    // Clear the newline character left by scanf
    while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));

    // Dynamically allocate memory for an array of 'number_of_records' Record structures
    // calloc initializes all allocated memory to zero, which is useful for pointers (sets them to NULL)
    records_array = (Record *)calloc(number_of_records, sizeof(Record));
    if (records_array == NULL) {
        fprintf(stderr, "Memory allocation failed. Unable to create records array.\n");
        return EXIT_FAILURE;
    }

    // Link the records sequentially using the 'next' pointer, forming a pseudo-linked list within the array
    for (int i = 0; i < number_of_records - 1; i++) {
        records_array[i].next = &records_array[i + 1];
    }
    records_array[number_of_records - 1].next = NULL; // The last record points to NULL

    // Input data into the records
    input_records(records_array, number_of_records);

    // Output data from the records
    output_records(records_array, number_of_records);

    // Free the dynamically allocated memory
    free(records_array);
    records_array = NULL; // Set pointer to NULL after freeing to prevent dangling pointer issues

    return EXIT_SUCCESS;
}