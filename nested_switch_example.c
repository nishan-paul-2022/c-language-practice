/*
 * Purpose: Demonstrates the use of nested switch statements to handle different input ranges and values.
 * Topic: Switch Statements, Nested Control Flow, Type Casting (double to int)
 */

#include <stdio.h>
#include <stdlib.h>

double read_floating_point_input() {
    double input_value;
    printf("Enter a floating-point number: ");
    if (scanf("%lf", &input_value) != 1) {
        printf("Invalid input. Please enter a valid floating-point number.\n");
        return -1.0;
    }
    return input_value;
}

int read_secondary_input() {
    int secondary_input;
    printf("Enter an integer (e.g., 20): ");
    if (scanf("%d", &secondary_input) != 1) {
        printf("Invalid secondary input.\n");
        return -1;
    }
    return secondary_input;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void process_secondary_input(int secondary_input) {
    switch (secondary_input) {
        case 20:
            printf("CAUGHT\n");
            break;
        default:
            printf("GOOD\n");
            break;
    }
}

void process_input_range(int scaled_value) {
    switch (scaled_value) {
        case 1:
        case 2:
        case 3: {
            int secondary_input = read_secondary_input();
            if (secondary_input == -1) {
                return;
            }
            clear_input_buffer();
            process_secondary_input(secondary_input);
            break;
        }
        default:
            printf("F\n");
            break;
    }
}

int main(void) {
    double input_value = read_floating_point_input();
    
    if (input_value == -1.0) {
        return 0;
    }
    
    clear_input_buffer();
    
    int scaled_value = input_value / 10.0;
    process_input_range(scaled_value);

    return 0;
}
