/*
 * Purpose: Calculates the multi-factorial (n!!!...k times) of a number,
 *          where k is determined by the number of exclamation marks in the input string.
 * Topic: String Parsing, Loops, Arithmetic Operations
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int read_input_string(char input_string[]) {
    printf("Enter a number followed by exclamation marks (e.g., 5!!): ");
    if (scanf("%[^\n]", input_string) != 1) {
        printf("Invalid input.\n");
        return -1;
    }
    return 0;
}

int count_exclamation_marks(const char input_string[]) {
    int k_value = 0;
    int i;
    for (i = 0; input_string[i] != '\0'; i++) {
        if (input_string[i] == '!') {
            k_value++;
        }
    }
    return k_value;
}

int parse_number(const char input_string[]) {
    int number;
    sscanf(input_string, "%d", &number);
    return number;
}

long long calculate_multi_factorial(int number, int k_value) {
    long long result = 1;
    int i;
    
    if (k_value == 0) {
        k_value = 1;
    }

    for (i = number; i >= 1; i -= k_value) {
        result *= i;
    }
    
    return result;
}

int main(void) {
    char input_string[100];
    int number, k_value;
    long long result;

    if (read_input_string(input_string) == -1) {
        return 0;
    }

    k_value = count_exclamation_marks(input_string);
    number = parse_number(input_string);
    result = calculate_multi_factorial(number, k_value);

    printf("The multi-factorial is: %lld\n", result);

    return 0;
}
