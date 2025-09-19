/*
 * Purpose: Generates and prints a table of exponential decay values (e^-k) based on a user-defined limit.
 * Topic: Loops, Mathematical Functions, User Input
 */

#include <stdio.h>
#include <math.h>

int get_input_limit() {
    int input_limit;
    printf("Enter the limit for the outer loop: ");
    scanf("%d", &input_limit);
    return input_limit;
}

void print_exponential_values(float k_start, int count) {
    for (int i = 0; i < count; i++) {
        float current_k = k_start + (i * 0.1f);
        printf("%1.2f ", exp(-current_k));
    }
    printf("\n");
}

void generate_exponential_table(int limit) {
    for (int outer_loop_counter = 0; outer_loop_counter <= limit; outer_loop_counter++) {
        float k_start_value = outer_loop_counter * 1.0f;
        print_exponential_values(k_start_value, 10);
    }
    printf("\n\n");
}

int main(void) {
    int input_limit = get_input_limit();
    generate_exponential_table(input_limit);
    
    return 0;
}
