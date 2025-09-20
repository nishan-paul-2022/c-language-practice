/*
 * Purpose: Demonstrates reading user input into a string and assigning it to a structure member using functions, highlighting safe input practices.
 * Topic: Structures, String Input
 */

#include <stdio.h>
#include <string.h>


typedef struct {
    int i;
    double d;
    char str[100];
} DataRecord;


void read_string(char *str, int size) {
    printf("Enter a string: ");

    if (fgets(str, size, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        str[0] = '\0';  
    } else {
        str[strcspn(str, "\n")] = '\0';
    }
}


DataRecord initialize_structure(int i, double d, const char *str) {
    DataRecord record;
    record.i = i;
    record.d = d;
    strcpy(record.str, str);
    return record;
}


void print_structure(const DataRecord *s) {
    printf("Integer: %d\n", s->i);
    printf("Double: %.2lf\n", s->d);
    printf("String: %s\n", s->str);
}

int main(void) {
    int i = 10;
    double d = 3.1416;
    char str[100];
    read_string(str, 100);
    DataRecord record = initialize_structure(i, d, str);
    print_structure(&record);

    return 0;
}