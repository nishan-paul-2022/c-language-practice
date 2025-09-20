/*
 * Purpose: Reads sets of four integers, calculates two sums based on alternating signs, and prints "BANGLADESH" or "MISS" based on whether both sums are positive.
 * Topic: Input/Output, Loops, Conditional Statements, Basic Arithmetic
 */

#include <stdio.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int read_test_count() {
    int count;
    printf("=== Hit/Miss Calculator ===\n");
    printf("This program evaluates (k1-k2+k3-k4) and (m1-m2+m3-m4) for each test case.\n");
    printf("Result is HIT if both sums are positive, otherwise MISS.\n\n");
    
    printf("Enter the number of test cases: ");
    if (scanf("%d", &count) != 1 || count < 0) {
        printf("Invalid input for number of test cases.\n");
        return -1;
    }

    return count;
}

int read_four_integers(int *a, int *b, int *c, int *d, const char *prompt) {
    printf("%s", prompt);
    if (scanf("%d %d %d %d", a, b, c, d) != 4) {
        printf("Invalid input. Please enter four integers.\n");
        clear_input_buffer();
        return -1;
    }
    return 0;
}

int calculate_sum(int a, int b, int c, int d) {
    return a - b + c - d;
}

void print_result(int sum1, int sum2, int test_num) {
    const char *result = (sum1 > 0 && sum2 > 0) ? "HIT" : "MISS";
    printf("Test Case %d Result: %s (Sum1=%d, Sum2=%d)\n", test_num, result, sum1, sum2);
}

int process_test_case(int test_num) {
    int k1, k2, k3, k4;
    int m1, m2, m3, m4;
    
    printf("\n--- Test Case %d ---\n", test_num);
    
    if (read_four_integers(&k1, &k2, &k3, &k4, "Enter first set (k1 k2 k3 k4): ") == -1) {
        return -1;
    }
    
    if (read_four_integers(&m1, &m2, &m3, &m4, "Enter second set (m1 m2 m3 m4): ") == -1) {
        return -1;
    }
    
    int sum1 = calculate_sum(k1, k2, k3, k4);
    int sum2 = calculate_sum(m1, m2, m3, m4);
    
    print_result(sum1, sum2, test_num);

    return 0;
}

int main(void) {
    int number_of_test_cases = read_test_count();
    if (number_of_test_cases == -1) {
        return 0;
    }
    
    for (int i = 0; i < number_of_test_cases; i++) {
        if (process_test_case(i + 1) == -1) {
            printf("Error in test case %d. Continuing to next test case...\n", i + 1);
        }
    }
    
    printf("\nCalculation completed.\n");
    return 0;
}
