/*
 * Purpose: Demonstrates sorting an array of structures by a string member (name) using bubble sort, with improved clarity and input handling.
 * Topic: Arrays of Structures, Sorting, String Comparison
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100]; 
    int roll;       
    double cgpa;    
} StudentInfo;

void consume_newline() {
    while (getchar() != '\n'); 
}

void sort_students_by_name(StudentInfo students[], int num_students) {
    StudentInfo temp;
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void print_students(const StudentInfo students[], int num_students) {
    printf("\n--- Sorted Student Data ---\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s | Roll: %d | CGPA: %.2lf\n", students[i].name, students[i].roll, students[i].cgpa);
    }
    printf("\n");
}

void input_students(StudentInfo students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("Student %d: \n", i + 1);

        scanf("%100[^\n]", students[i].name);
        scanf("%d", &students[i].roll);
        scanf("%lf", &students[i].cgpa);

        consume_newline();
    }
}

int main(void) {
    int num_students;
    printf("Enter the number of students: ");
    if (scanf("%d", &num_students) != 1 || num_students <= 0) {
        fprintf(stderr, "Invalid input for number of students.\n");
        return 0;
    }
    consume_newline();

    StudentInfo students[num_students];

    printf("Enter student details (Name Roll CGPA):\n");
    input_students(students, num_students);

    sort_students_by_name(students, num_students);
    print_students(students, num_students);

    return 0;
}
