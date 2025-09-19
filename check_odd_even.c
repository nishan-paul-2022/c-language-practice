/*
 * Purpose: Reads a series of numbers and determines if each number is odd or even.
 * Topic: Input/Output, Loops, Conditional Statements, Modulo Operator
 */

#include <stdio.h>


int read_test_count() {
    int count;
    printf("Enter the number of test cases: ");
    
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Invalid number of test cases.\n");
        return -1;
    }
    
    return count;
}


int read_number(int test_num, int *number) {
    printf("Enter number for test case %d: ", test_num);
    
    if (scanf("%d", number) != 1) {
        printf("Failed to read number for test case %d.\n", test_num);
        return -1;
    }
    
    return 0;
}


void check_parity(int number, int test_num) {
    const char *result = (number % 2 == 0) ? "Even" : "Odd";
    printf("Result for test case %d: %s\n", test_num, result);
}

int main(void) {
    int num_test_cases = read_test_count();
    if (num_test_cases == -1) {
        return 0;
    }
    
    
    for (int i = 0; i < num_test_cases; i++) {
        int test_num = i + 1;
        int number;
        
        if (read_number(test_num, &number) == 0) {
            check_parity(number, test_num);
        }
    }
    
    return 0;
}
