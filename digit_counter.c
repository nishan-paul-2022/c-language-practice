/*
 * Purpose: Counts the number of digits in a given non-negative integer.
 * Topic: Integer Arithmetic, Loops, Basic Math
 */

#include <stdio.h>

int count_digits(long long int number) {
    if (number == 0) {
        return 1;
    }
    
    int count = 0;
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

void process_test_cases() {
    int num_test_cases;
    printf("Enter number of test cases: ");
    scanf("%d", &num_test_cases);
    
    for (int case_num = 1; case_num <= num_test_cases; case_num++) {
        long long int number;
        printf("Enter number: ");
        scanf("%lld", &number);
        
        int digit_count = count_digits(number);
        printf("%d\n", digit_count);
    }
}

int main(void) {
    process_test_cases();
    return 0;
}
