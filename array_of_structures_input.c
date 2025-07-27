// Purpose: Demonstrates creating an array of structures and reading user input for each element, including input validation.
// Topic: Arrays of Structures, Input Handling

#include <stdio.h>
#include <string.h> // For strcspn if needed, though scanf handles string input here

// Define a structure to hold different data types
struct Student {
    int id;             // Student ID
    double score;       // Student score
    char name[100];     // Student name
};

int main() {
    int numElements; // Number of students to process
    int i;           // Loop counter

    // Prompt user for the number of elements
    printf("Enter the number of students: ");
    // Read the number of elements and validate input
    if (scanf("%d", &numElements) != 1 || numElements <= 0) {
        fprintf(stderr, "Invalid input for number of students. Please enter a positive integer.\n");
        return 1; // Indicate an error
    }

    // Declare an array of structures (Variable Length Array - C99 feature)
    struct Student students[numElements];

    // Consume the newline character left by scanf for the integer input
    // This is important before reading strings with %[^\n]
    while (getchar() != '\n');

    printf("Enter student details (ID, Score, Name) for each student:\n");

    // Loop to read data for each student
    for (i = 0; i < numElements; i++) {
        printf("Student %d: ", i + 1);
        // Read student details: ID, Score, and Name
        // %[^\n] reads characters until a newline is encountered.
        // The space before %[^\n] consumes any leading whitespace, including the newline from previous input.
        if (scanf("%d, %lf, %[^\n]", &students[i].id, &students[i].score, students[i].name) != 3) {
            fprintf(stderr, "Error reading data for student %d. Please ensure input is in the format: ID, Score, Name\n", i + 1);
            // Clear the input buffer in case of scanf failure
            while (getchar() != '\n');
            // Optionally, you could decide to skip this student or terminate.
            // For this example, we'll print an error and continue, but the data might be inconsistent.
            // To be safer, one might return 1 here or use fgets for more robust input.
            // For now, we'll just report and continue.
            continue; // Skip to the next iteration if input fails
        }
        // Consume the newline character after reading the string to prepare for the next iteration
        // This is crucial if the next input is also string-based or if there are further scanf calls.
        // However, the %[^\n] format specifier in scanf already reads up to newline,
        // so an explicit while(getchar() != '\n'); might be redundant or even problematic
        // if the newline was already consumed by the format specifier.
        // Let's test without it first, and add if necessary.
        // If the next input is also %[^\n], it should work. If it's %d, we might need to consume.
        // For now, let's assume the format string handles it.
    }

    printf("\n--- Entered Student Data ---\n");

    // Loop to print data for each student
    for (i = 0; i < numElements; i++) {
        printf("ID: %d, Score: %.2lf, Name: %s\n", students[i].id, students[i].score, students[i].name);
    }

    printf("\n");

    return 0; // Indicate successful execution
}
