/*
 * Purpose: Simple demonstration of sscanf parsing and sprintf formatting
 * Topic: String parsing and formatting
 */

#include <stdio.h>

void demo_sscanf() {
    printf("=== sscanf Examples ===\n");
    
    // Parse numbers
    char data1[] = "25 3.14 A";
    int age; float gpa; char grade;
    sscanf(data1, "%d %f %c", &age, &gpa, &grade);
    printf("Parsed: age=%d, gpa=%.2f, grade=%c\n", age, gpa, grade);
    
    // Parse strings
    char data2[] = "John Berkeley CS";
    char name[20], city[20], major[20];
    sscanf(data2, "%s %s %s", name, city, major);
    printf("Parsed: %s from %s, major: %s\n", name, city, major);
    
    // Parse with format
    char data3[] = "ID:12345 Score:95.5";
    int id; float score;
    sscanf(data3, "ID:%d Score:%f", &id, &score);
    printf("Parsed: ID=%d, Score=%.1f\n", id, score);
}

void demo_sprintf() {
    printf("\n=== sprintf Examples ===\n");
    
    char buffer[100];
    
    // Basic formatting
    sprintf(buffer, "Name: %s, Age: %d", "Alice", 22);
    printf("Formatted: %s\n", buffer);
    
    // Numbers with precision
    sprintf(buffer, "Price: $%.2f, Quantity: %d", 15.99, 3);
    printf("Formatted: %s\n", buffer);
    
    // Table-like formatting
    sprintf(buffer, "%-10s | %5d | %6.2f", "Student", 12345, 3.85);
    printf("Table row: %s\n", buffer);
}

void demo_combined() {
    printf("\n=== Combined sscanf + sprintf ===\n");
    
    char input[] = "Alice 21 3.75 CS";
    char name[20], major[10];
    int age;
    float gpa;
    
    sscanf(input, "%s %d %f %s", name, &age, &gpa, major);
    
    char output[100];
    sprintf(output, "%s (%d years old) | GPA: %.2f in %s", name, age, gpa, major);
    printf("Result: %s\n", output);
}

int main() {
    printf("Simple sscanf and sprintf Demo\n");
    printf("==============================\n\n");
    
    demo_sscanf();
    demo_sprintf();
    demo_combined();
    
    return 0;
}
