/*
 * Purpose: Converts a string representation of a number into an integer and finds all its divisors.
 * Topic: String to Integer Conversion, Loops, Divisors, Integer Arithmetic
 */

#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 7 


int read_number_string(char buffer[], int size, int test_case) {
    int c;
    printf("Enter number string for test case %d (max 6 digits): ", test_case);
    if (scanf("%6s", buffer) != 1) {
        return 0; 
    }
    while ((c = getchar()) != '\n' && c != EOF); 
    return 1;
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
    if (!read_number_string(input_string, MAX_DIGITS, test_case)) {
        printf("Error reading input for test case %d.\n", test_case);
        return;
    }

    long number = string_to_long(input_string, test_case);
    if (number != -1) {
        printf("Case %d: Divisors of %ld are:", test_case, number);
        print_divisors(number);
    }
}

int main(void) {
    int num_test_cases;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error reading number of test cases.\n");
        return 0;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF); 

    for (int t = 1; t <= num_test_cases; t++) {
        process_test_case(t);
    }

    return 0;
}
