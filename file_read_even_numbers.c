/*
 * Purpose: Reads unsigned long long integers from a file and prints only the even numbers.
 * Topic: File I/O, Loops, Conditional Statements
 */

#include <stdio.h>
#include <stdlib.h>

FILE* open_file(const char *filename) {
    FILE *file_pointer = fopen(filename, "r");
    if (file_pointer == NULL) {
        perror("Error opening file");
    }
    return file_pointer;
}

int is_even(unsigned long long int number) {
    return number % 2 == 0;
}

void process_even_numbers(FILE *file_pointer, const char *filename) {
    unsigned long long int number;
    int found_even = 0;
    
    printf("Reading numbers from '%s' and printing even numbers:\n", filename);
    
    while (fscanf(file_pointer, "%llu", &number) == 1) {
        if (is_even(number)) {
            printf("%llu ", number);
            found_even = 1;
        }
    }
    
    if (!found_even) {
        printf("No even numbers found");
    }
    printf("\n");
}

int main(void) {
    const char *filename = "files/file_read_even_numbers.txt";
    FILE *file_pointer;

    file_pointer = open_file(filename);
    if (file_pointer == NULL) {
        return 0;
    }

    process_even_numbers(file_pointer, filename);

    fclose(file_pointer);

    return 0;
}
