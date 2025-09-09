/*
 * Purpose: Demonstrates creating an structure array and reading user input for each element, including input validation.
 * Topic: Structure Array, Input Handling
 */

#include <stdio.h>
#include <string.h>

// Student structure
struct Student {
    int id; // Student ID
    double score; // Student score
    char name[100]; // Student name
};

int main() {
    int numElements; // Number of students
    int i; // Loop counter

    // Get number of students
    printf("Enter the number of students: ");
    if (scanf("%d", &numElements) != 1 || numElements <= 0) {
        fprintf(stderr, "Invalid input for number of students. Please enter a positive integer.\n");
        return 1;
    }

    // Create array of students
    struct Student students[numElements];

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter student details (ID, Score, Name) for each student:\n");

    // Read student data
    for (i = 0; i < numElements; i++) {
        printf("Student %d: ", i + 1);
        // Format: ID, Score, Name
        if (scanf("%d, %lf, %[^\n]", &students[i].id, &students[i].score, students[i].name) != 3) {
            fprintf(stderr, "Error reading data for student %d. Please ensure input is in the format: ID, Score, Name\n", i + 1);
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }
    }

    printf("\n--- Entered Student Data ---\n");

    // Display student data
    for (i = 0; i < numElements; i++) {
        printf("ID: %d, Score: %.2lf, Name: %s\n", students[i].id, students[i].score, students[i].name);
    }

    printf("\n");

    return 0;
}
