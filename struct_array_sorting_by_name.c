// Purpose: Sorts an array of structures based on a string member in lexicographical order.
// Topic: Structures, Arrays of Structures, String Sorting

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For malloc, free, and other utilities if needed, though not strictly required here.

// Define a structure to hold different data types
typedef struct {
    int integer_value;      // An integer member
    double double_value;    // A double-precision floating-point member
    char string_data[100];  // A character array to store strings
} Record;

// Function to input data for an array of Record structures
void input_records(Record records[], int num_records) {
    printf("Enter data for %d records:\n", num_records);
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);

        printf("  Enter string (max 99 chars): ");
        // Use fgets for safe string input to prevent buffer overflows
        if (fgets(records[i].string_data, sizeof(records[i].string_data), stdin) != NULL) {
            // Remove the trailing newline character if fgets read one
            char *newline = strchr(records[i].string_data, '\n');
            if (newline) {
                *newline = '\0';
            }
        } else {
            fprintf(stderr, "Error reading string for record %d.\n", i + 1);
            // Handle error appropriately, e.g., exit or skip record
            return; // Exit input function on error
        }

        printf("  Enter an integer: ");
        // Use scanf for integer and double input
        if (scanf("%d", &records[i].integer_value) != 1) {
            fprintf(stderr, "Error reading integer for record %d.\n", i + 1);
            return;
        }

        printf("  Enter a double: ");
        if (scanf("%lf", &records[i].double_value) != 1) {
            fprintf(stderr, "Error reading double for record %d.\n", i + 1);
            return;
        }

        // Consume the newline character left by scanf to prepare for the next fgets
        // This is important to ensure fgets reads the string correctly in the next iteration.
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// Function to output data from an array of Record structures
void output_records(Record records[], int num_records) {
    printf("\n--- Records ---\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("  String: %s\n", records[i].string_data);
        printf("  Integer: %d\n", records[i].integer_value);
        printf("  Double: %.2lf\n", records[i].double_value);
    }
    printf("---------------\n");
}

// Function to sort an array of Record structures by their string_data member
void sort_records_by_name(Record records[], int num_records) {
    // Using a bubble sort algorithm for demonstration.
    // For larger datasets, more efficient algorithms like quicksort or mergesort would be preferred.
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = 0; j < num_records - 1 - i; j++) {
            // Compare strings using strcmp. If a[i].c > a[j].c, swap them.
            if (strcmp(records[j].string_data, records[j + 1].string_data) > 0) {
                // Swap the entire structures
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

// Main function to drive the program
int main() {
    int num_records;

    printf("Enter the number of records: ");
    if (scanf("%d", &num_records) != 1) {
        fprintf(stderr, "Invalid input for number of records.\n");
        return 0;
    }

    // Consume the newline character left by scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Dynamically allocate memory for the array of structures if num_records is large,
    // or use a fixed-size array if num_records is known to be small.
    // For this example, we'll use a VLA as in the original code, assuming reasonable input size.
    // If VLA is not supported or for larger scale, dynamic allocation with malloc would be better.
    Record records[num_records];

    input_records(records, num_records); // Input data into the array
    sort_records_by_name(records, num_records); // Sort the array by name
    output_records(records, num_records); // Output the sorted data

    return 0;
}
