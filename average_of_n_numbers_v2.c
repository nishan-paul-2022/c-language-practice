/*
 * Purpose: Reads a sequence of double values until a non-numeric value is entered,
 *          then calculates and prints the average of the entered numbers.
 * Topic: Loops, Input Handling, Floating-Point Numbers, Average Calculation
*/

#include <stdio.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    double current_value;
    double sum_of_values = 0.0;
    int count = 0;

    printf("Enter a sequence of double values (Ctrl+D to finish and see the average).\n");
    
    while (scanf("%lf", &current_value) != -1) {
        count++;
        sum_of_values += current_value;
        clear_input_buffer();
    }

    if (count > 0) {
        double average = sum_of_values / count;
        printf("The average of the entered numbers is %.2f\n", average);
    }

    return 0;
}
