/*
 * Purpose: Demonstrates dynamic memory allocation for an array of structures using calloc,
 *          and how pointers within structures can link elements sequentially.
 * Topic: Structures, Pointers, Dynamic Memory Allocation (calloc, free), Input/Output
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long int id;
    char name[100];
    float value;
    struct Record *next;
} Record;

void clear_input_buffer() {
    while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
}

int get_record_count() {
    int number_of_records;
    printf("Enter the number of records to store: ");
    
    if (scanf("%d", &number_of_records) != 1 || number_of_records <= 0) {
        printf("Invalid number of records. Please enter a positive integer.\n");
        return -1;
    }
    clear_input_buffer();
    return number_of_records;
}

Record *allocate_records(int count) {
    Record *records_array = (Record *)calloc(count, sizeof(Record));
    
    if (records_array == NULL) {
        fprintf(stderr, "Memory allocation failed. Unable to create records array.\n");
        return NULL;
    }
    return records_array;
}

void link_records(Record *records_array, int count) {
    for (int i = 0; i < count - 1; i++) {
        records_array[i].next = &records_array[i + 1];
    }
    records_array[count - 1].next = NULL;
}

int input_records(Record *records_array, int count) {
    printf("Enter %d records (ID, Value, Name) separated by commas (e.g., 123, 45.67, JohnDoe):\n", count);
    
    for (int i = 0; i < count; i++) {
        printf("Record %d: ", i + 1);
        if (scanf("%ld, %f, %99s", &records_array[i].id, &records_array[i].value, records_array[i].name) != 3) {
            fprintf(stderr, "Invalid input format for record %d. Exiting.\n", i + 1);
            clear_input_buffer();
            return -1;
        }
        clear_input_buffer();
    }
    return 0;
}

void output_records(Record *records_array, int count) {
    printf("\n--- Stored Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Record %d | Name: %s, ID: %ld, Value: %.2f\n", i + 1, records_array[i].name, records_array[i].id, records_array[i].value);
    }
}

void free_records(Record **records_array) {
    free(*records_array);
    *records_array = NULL;
}

int main(void) {
    int number_of_records = get_record_count();
    if (number_of_records <= 0) {
        return 0;
    }
    
    Record *records_array = allocate_records(number_of_records);
    if (records_array == NULL) {
        return 0;
    }
    
    link_records(records_array, number_of_records);
    
    if (input_records(records_array, number_of_records) == 0) {
        free_records(&records_array);
        return 0;
    }
    
    output_records(records_array, number_of_records);
    free_records(&records_array);
    
    return 0;
}
