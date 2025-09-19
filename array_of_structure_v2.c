/*
 * Purpose: Demonstrates creating a structure array and reading user input for each element, including input validation.
 * Topic: Structure Array, Input Handling
 */

#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    double score;
    char name[100];
};

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_number_of_students() {
    int number_of_students;
    
    printf("Enter the number of students: ");
    while (scanf("%d", &number_of_students) != 1 || number_of_students <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer: ");
        clear_input_buffer();
    }
    
    return number_of_students;
}

int read_student_data(struct Student *student, int student_number) {
    printf("Student %d: ", student_number);
    
    // Format: ID, Score, Name
    if (scanf("%d, %lf, %[^\n]", &student->id, &student->score, student->name) != 3) {
        fprintf(stderr, "Error reading data for student %d. Please ensure input is in the format: ID, Score, Name\n", student_number);
        clear_input_buffer();
        return -1; // Failure
    }
    
    return 0; // Success
}

void input_all_students(struct Student students[], int count) {
    printf("Enter student details (ID, Score, Name) for each student:\n");
    printf("Format: ID, Score, Name (e.g., 123, 85.5, John Doe)\n\n");
    
    for (int i = 0; i < count; i++) {
        while (read_student_data(&students[i], i + 1) == -1) {
            printf("Please try again for student %d: ", i + 1);
        }
        clear_input_buffer(); // Clear any remaining input
    }
}

void display_student(const struct Student *student) {
    printf("ID: %d, Score: %.2lf, Name: %s\n", student->id, student->score, student->name);
}

void display_all_students(const struct Student students[], int count) {
    printf("\n--- Entered Student Data ---\n");
    
    for (int i = 0; i < count; i++) {
        display_student(&students[i]);
    }
    
    printf("\n");
}

int main(void) {
    // Get number of students
    int number_of_students = get_number_of_students();
    
    // Create student array
    struct Student students[number_of_students];
    
    // Clear input buffer after reading integer
    clear_input_buffer();
    
    // Input all student data
    input_all_students(students, number_of_students);
    
    // Display all student data
    display_all_students(students, number_of_students);
    
    return 0;
}