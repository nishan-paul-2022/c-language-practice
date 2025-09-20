/*
 * Purpose: Demonstrates table formatting and multiple string handling.
 * Topic: Creating tables, reports, multiple strings in formatted output
 */

#include <stdio.h>

void display_section_header(const char *title) {
    printf("\n=== %s ===\n\n", title);
}

void demonstrate_table_formatting() {
    char names[][15] = {"Alice", "Bob", "Charlie", "Diana", "Edward"};
    char courses[][10] = {"CS61A", "CS61B", "CS61C", "CS70", "EECS16A"};
    char unis[][20] = {"UC Berkeley", "Stanford", "MIT", "CMU", "Caltech"};
        
    printf("Simple two-column table:\n");
    printf("%-12s | %15s\n", "Name", "Course");
    printf("%-12s-+--%15s\n", "------------", "---------------");
    for (int i = 0; i < 3; i++) {
        printf("%-12s | %15s\n", names[i], courses[i]);
    }
    
    printf("\nThree-column table with mixed alignment:\n");
    printf("%-10s | %-12s | %10s\n", "Student", "University", "Course");
    printf("%-10s-+-%-12s-+-%10s\n", "----------", "------------", "----------");
    for (int i = 0; i < 5; i++) {
        printf("%-10.8s | %-12.10s | %10s\n", names[i], unis[i], courses[i]);
    }
    
    printf("\nCompact table with truncation:\n");
    printf("%-8.8s | %-8.8s | %-6.6s\n", "Name", "University", "Course");
    printf("%-8s-+-%-8s-+-%-6s\n", "--------", "--------", "------");
    for (int i = 0; i < 5; i++) {
        printf("%-8.8s | %-8.8s | %-6.6s\n", names[i], unis[i], courses[i]);
    }
}

int main(void) {
    display_section_header("Table Formatting Examples");
    demonstrate_table_formatting();
    return 0;
}
