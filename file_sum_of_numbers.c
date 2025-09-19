/*
 * Purpose: Reads integers from a specified text file and calculates their sum.
 * Topic: File I/O, Reading Integers, Summation, File Pointer
 */

#include <stdio.h>

long sum_numbers_in_file(const char *filename) {
    FILE *file_ptr = fopen(filename, "r"); // open file in read mode
    if (file_ptr == NULL) {
        perror("Error opening file");
        fprintf(stderr, "Could not open file: %s\n", filename);
        return -1;
    }

    long number;
    long total_sum = 0;

    while (fscanf(file_ptr, "%ld", &number) == 1) {
        total_sum += number;
    }

    if (ferror(file_ptr)) {
        perror("Error reading from file");
        fprintf(stderr, "An error occurred while reading from %s.\n", filename);
        fclose(file_ptr);
        return -1;
    }

    fclose(file_ptr);
    return total_sum;
}

int main(void) {
    const char *filename = "files/28-input.txt";
    long sum = sum_numbers_in_file(filename);

    if (sum == -1) {
        return 0;
    }

    printf("The sum of numbers in the file is: %ld\n", sum);
    return 0;
}
