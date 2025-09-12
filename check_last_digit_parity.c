/*
 * Purpose: Reads strings and determines if the last character (assumed to be a digit) is odd or even.
 * Topic: String Input, String Length, Character to Integer Conversion, Modulo Operator
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 100
#define BUFFER_SIZE (MAX_STRING_LENGTH + 1)

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int read_test_count(void) {
    int count;
    printf("Enter the number of test cases: ");
    
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Error: Invalid number of test cases.\n");
        return -1;
    }
    
    clear_input_buffer();
    return count;
}

int read_string(char *buffer, int test_num) {
    printf("Enter string for test case %d: ", test_num);
    
    if (scanf("%100s", buffer) != 1) {
        printf("Error: Failed to read string for test case %d.\n", test_num);
        return -1;
    }
    
    clear_input_buffer();
    
    return 0;
}

void process_string(const char *str, int test_num) {
    size_t length = strlen(str);
    
    // Check for empty string
    if (length == 0) {
        printf("Invalid input for test case %d: String is empty.\n", test_num);
        return;
    }
    
    char last_char = str[length - 1];
    
    // Check if last character is a digit
    if (!isdigit(last_char)) {
        printf("Invalid input for test case %d: Last character is not a digit.\n", test_num);
        return;
    }
    
    // Convert digit character to integer and check parity
    int digit = last_char - '0';
    const char *result = (digit % 2 == 0) ? "Even" : "Odd";
    
    printf("Result for test case %d: %s\n", test_num, result);
}

int main(void) {
    char input_string[BUFFER_SIZE];
    
    int num_test_cases = read_test_count();
    if (num_test_cases == -1) {
        return 0;
    }
    
    // Process each test case
    for (int i = 0; i < num_test_cases; i++) {
        int test_num = i + 1;
        
        if (read_string(input_string, test_num) == 0) {
            process_string(input_string, test_num);
        }        
    }
    
    return 0;
}
