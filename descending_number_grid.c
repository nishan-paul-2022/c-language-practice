/*
 * Purpose: Prints a sequence of numbers in a descending order, formatted into a grid. The grid dimensions (start number, columns, total numbers) are specified by the user.
 * Topic: Nested Loops, User Input, Dynamic Grid Generation
 */

#include <stdio.h>

void print_number_grid(int start, int cols, int total) {
    int current_number = start;
    int numbers_printed = 0;

    for (int i = 0; numbers_printed < total; ++i) {
        for (int j = 0; j < cols && numbers_printed < total; ++j) {
            printf("%d\t", current_number--);
            numbers_printed++;
        }
        printf("\n");
    }
}

int main(void) {
    int start_num, num_cols, total_nums;

    printf("Enter the starting number: ");
    scanf("%d", &start_num);

    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);

    printf("Enter the total numbers to print: ");
    scanf("%d", &total_nums);

    if (num_cols <= 0 || total_nums <= 0) {
        printf("Number of columns and total numbers must be positive.\n");
        return 0;
    }

    printf("\n--- Descending Number Grid ---\n");
    print_number_grid(start_num, num_cols, total_nums);

    return 0;
}
