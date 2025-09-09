/*
 * Purpose: Demonstrates sorting an array of structures by a string member (name) using bubble sort, with improved clarity and input handling.
 * Topic: Arrays of Structures, Sorting, String Comparison
 */

#include <stdio.h>
#include <string.h> // For strcmp and strcpy

// Define a structure to hold student information
struct StudentInfo {
    char name[100]; // Student's name
    int roll;       // Student's roll number
    double cgpa;    // Student's CGPA
};

// Function to sort an array of StudentInfo structures by name using bubble sort
void sortStudentsByName(struct StudentInfo students[], int numStudents) {
    int i, j;
    struct StudentInfo tempStudent; // Temporary variable for swapping

    // Bubble sort algorithm
    for (i = 0; i < numStudents - 1; i++) {
        for (j = 0; j < numStudents - i - 1; j++) {
            // Compare names using strcmp. If a[j].name > a[j+1].name, swap them.
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                // Swap the entire structures
                tempStudent = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tempStudent;
            }
        }
    }
}

// Function to print the array of StudentInfo structures
void printStudentArray(struct StudentInfo students[], int numStudents) {
    int i;
    printf("\n--- Sorted Student Data ---\n");
    for (i = 0; i < numStudents; i++) {
        printf("Name: %s, Roll: %d, CGPA: %.2lf\n", students[i].name, students[i].roll, students[i].cgpa);
    }
    printf("\n");
}

int main() {
    int numStudents; // Number of students
    int i;

    // Prompt user for the number of students
    printf("Enter the number of students: ");
    // Read the number of students and validate input
    if (scanf("%d", &numStudents) != 1 || numStudents <= 0) {
        fprintf(stderr, "Invalid input for number of students. Please enter a positive integer.\n");
        return 0;
    }

    // Consume the newline character left by scanf after reading numStudents
    // This is crucial before reading strings with %[^\n]
    while (getchar() != '\n');

    // Declare an array of structures (Variable Length Array - C99 feature)
    struct StudentInfo students[numStudents];

    printf("Enter student details (Name, Roll, CGPA) for each student:\n");

    // Loop to read data for each student
    for (i = 0; i < numStudents; i++) {
        printf("Student %d: ", i + 1);
        // Read student details: Name, Roll, CGPA
        // "%99[^\n]" reads up to 99 characters to prevent buffer overflow for the name.
        // The space before "%99[^\n]" consumes any leading whitespace, including the newline from previous input.
        // "%d" reads the roll number.
        // "%lf" reads the CGPA.
        if (scanf("%99[^\n] %d %lf", students[i].name, &students[i].roll, &students[i].cgpa) != 3) {
            fprintf(stderr, "Error reading data for student %d. Please ensure input is in the format: Name Roll CGPA\n", i + 1);
            // Clear the input buffer in case of scanf failure
            while (getchar() != '\n');
            // Skip to the next iteration if input fails
            continue;
        }
        // Consume the newline character after reading the last element (CGPA)
        // This is important to ensure the next iteration's scanf works correctly.
        while (getchar() != '\n');
    }

    // Sort the array of students by name
    sortStudentsByName(students, numStudents);

    // Print the sorted array
    printStudentArray(students, numStudents);

    return 0;
}
