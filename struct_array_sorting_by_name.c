/*
 * Purpose: Sorts an array of structures based on a string member in lexicographical order.
 * Topic: Structures, Arrays of Structures, String Sorting
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int integer_value;
    double double_value;
    char string_data[100];
} Record;

void read_string(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        char *newline = strchr(buffer, '\n');
        if (newline) *newline = '\0';
    }
}

void input_record(Record *rec, int index) {
    printf("Record %d:\n", index + 1);
    printf("  Enter string (max 99 chars): ");
    read_string(rec->string_data, sizeof(rec->string_data));

    printf("  Enter an integer: ");
    if (scanf("%d", &rec->integer_value) != 1) {
        fprintf(stderr, "Error reading integer for record %d.\n", index + 1);
        exit(0);
    }

    printf("  Enter a double: ");
    if (scanf("%lf", &rec->double_value) != 1) {
        fprintf(stderr, "Error reading double for record %d.\n", index + 1);
        exit(0);
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void input_records(Record records[], int num_records) {
    printf("Enter data for %d records:\n", num_records);
    for (int i = 0; i < num_records; i++) {
        input_record(&records[i], i);
    }
}

void output_records(const Record records[], int num_records) {
    printf("\n--- Records ---\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i + 1);
        printf("  String: %s\n", records[i].string_data);
        printf("  Integer: %d\n", records[i].integer_value);
        printf("  Double: %.2lf\n", records[i].double_value);
    }
    printf("---------------\n");
}

void sort_records_by_name(Record records[], int num_records) {
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = 0; j < num_records - 1 - i; j++) {
            if (strcmp(records[j].string_data, records[j + 1].string_data) > 0) {
                Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int num_records;

    printf("Enter the number of records: ");
    if (scanf("%d", &num_records) != 1) {
        fprintf(stderr, "Invalid input for number of records.\n");
        return 0;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    Record records[num_records];

    input_records(records, num_records);
    sort_records_by_name(records, num_records);
    output_records(records, num_records);

    return 0;
}
