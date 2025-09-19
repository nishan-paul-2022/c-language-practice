/*
 * Purpose: Reads an integer and repeatedly extracts its last digits by taking modulo with increasing powers of 10.
 * Topic: Loops, Arithmetic Operators (Modulo), Basic I/O
 */

#include <stdio.h>
#include <math.h>

void display_instructions() {
    printf("Enter integers to be processed (e.g., 12345):\n\n");
}

void process_number(int input_number) {
    printf("Processing number: %d\n", input_number);
    
    for (long long int power_of_10 = 10; power_of_10 <= input_number * 10; power_of_10 *= 10) {
        int extracted_digits = input_number % power_of_10;
        printf("  Digits (modulo %lld): %d\n", power_of_10, extracted_digits);
    }
    printf("  Original number: %d\n\n", input_number);
}

void process_input_stream() {
    int input_number;
    
    while (scanf("%d", &input_number) == 1) {
        process_number(input_number);
    }
    
    printf("Input stopped or invalid input received.\n");
}

int main(void) {
    display_instructions();
    process_input_stream();
    
    return 0;
}
