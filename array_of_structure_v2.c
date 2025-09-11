/*
 * Purpose: Demonstrates creating an structure array and reading user input for each element, including input validation.
 * Topic: Structure Array, Input Handling
 */

#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    double score;
    char name[100];
};

int main(void) {
    int number_of_students;

    printf("Enter the number of students: ");
    if (scanf("%d", &number_of_students) != 1 || number_of_students <= 0) {
        fprintf(stderr, "Invalid input for number of students. Please enter a positive integer.\n");
        return 0;
    }

    struct Student students[number_of_students];

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter student details (ID, Score, Name) for each student:\n");

    // Input student data
    for (int i = 0; i < number_of_students; i++) {
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

    // Output student data
    for (int i = 0; i < number_of_students; i++) {
        printf("ID: %d, Score: %.2lf, Name: %s\n", students[i].id, students[i].score, students[i].name);
    }

    printf("\n");

    return 0;
}
