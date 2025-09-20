/*
 * Purpose: Converts a string representation of a number into an integer and finds all its divisors.
 * Topic: String to Integer Conversion, Loops, Divisors, Integer Arithmetic
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 8

void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int read_num_test_cases() {
    int num_test_cases;

    printf("Enter the number of test cases: ");
    
    if (scanf("%d", &num_test_cases) == -1) {
        printf("Error reading number of test cases.\n");
        return -1;
    }

    consume_newline();
    
    return num_test_cases;
}

void read_numeric_string(char buffer[], int size, int test_case) {    
    printf("\nEnter numeric string for test case %d (max %d digits): ", test_case, MAX_DIGITS-1);

    if (scanf("%7s", buffer) == -1) {
        printf("Error reading input for test case %d.\n", test_case);
        exit(1);
    }

    consume_newline();
}

long string_to_long(const char str[], int test_case) {
    long value = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            value = value * 10 + (str[i] - '0');
        } else {
            printf("Invalid input for test case %d: '%s' contains non-digit characters.\n", test_case, str);
            return -1;
        }
    }

    return value;
}

void print_divisors(long number) {
    for (long i = 1; i <= number; i++) {
        if (number % i == 0) {
            printf(" %ld", i);
        }
    }

    printf("\n");
}

void process_test_case(int test_case) {
    char input_string[MAX_DIGITS];
    read_numeric_string(input_string, MAX_DIGITS, test_case);

    long number = string_to_long(input_string, test_case);
    if (number != -1) {
        printf("Case %d: Divisors of %ld:", test_case, number);
        print_divisors(number);
    }
}

int main(void) {
    int num_test_cases = read_num_test_cases();
    if (num_test_cases == -1) {
        return 0;
    }

    for (int t = 1; t <= num_test_cases; t++) {
        process_test_case(t);
    }

    return 0;
}
