/*
 * Purpose: Solves a variant of the Josephus problem using modular arithmetic.
 * Topic: Loops, Modular Arithmetic, Problem Solving
 */

#include <stdio.h>
#include <stdlib.h>

int calculate_josephus_position(int n) {
    int result_position = 0;
    
    for (int x = 2; x <= n; x++) {
        result_position = (result_position + n + 1 - x) % x;
    }
    
    return result_position + 1; 
}

int get_test_case_input(int case_num) {
    int n;
    
    printf("Enter value of n for test case %d: ", case_num);
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Invalid input for n. Skipping test case.\n");
        while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
        return -1;
    }
    
    return n;
}

void process_test_cases() {
    int number_of_test_cases;
    int current_test_case = 0;

    printf("Enter number of test cases: ");
    if (scanf("%d", &number_of_test_cases) != 1 || number_of_test_cases < 0) {
        printf("Invalid input for number of test cases.\n");
        exit(1);
    }

    while (current_test_case < number_of_test_cases) {
        int n = get_test_case_input(current_test_case + 1);
        
        if (n != -1) {
            int result = calculate_josephus_position(n);
            printf("Result for n = %d: %d\n", n, result);
        }
        
        current_test_case++;
    }
}

int main(void) {
    process_test_cases();
    return 0;
}
