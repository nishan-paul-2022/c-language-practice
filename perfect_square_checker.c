/*
 * Purpose: Checks if a given non-negative integer is a perfect square.
 * Topic: Number Theory, Math Functions (sqrt), Integer Arithmetic, Conditional Logic
 */

#include <stdio.h>
#include <math.h>

int is_perfect_square(long long int number) {
    if (number < 0) {
        return 0;
    }
    
    long long int integer_sqrt = (long long int)sqrt(number);
    return (integer_sqrt * integer_sqrt == number);
}

int get_test_cases(void) {
    int num_test_cases;
    scanf("%d", &num_test_cases);
    return num_test_cases;
}

long long int get_number(void) {
    long long int number;
    scanf("%lld", &number);
    return number;
}

void print_result(int case_num, int is_perfect) {
    printf("Case %d: %s\n", case_num, is_perfect ? "YES" : "NO");
}

int main(void) {
    int num_test_cases = get_test_cases();
    
    for (int case_num = 1; case_num <= num_test_cases; case_num++) {
        long long int number_to_check = get_number();
        int result = is_perfect_square(number_to_check);
        print_result(case_num, result);
    }

    return 0;
}
