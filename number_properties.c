/*
 * Purpose: Checks if a number is an Abundant Number and a Palindrome Number.
 * Topic: Number Theory, String Manipulation, Loops
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_abundant(int num) {
    if (num <= 0) {
        return 0;
    }
    int sum_of_proper_divisors = 0;
    int i;
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum_of_proper_divisors += i;
        }
    }
    return sum_of_proper_divisors > num;
}

int is_palindrome(int num) {
    if (num < 0) {
        return 0;
    }
    
    char number_str[20];
    sprintf(number_str, "%d", num);
    
    int string_length = strlen(number_str);
    int half_length = string_length / 2;
    int i;
    
    for (i = 0; i < half_length; i++) {
        if (number_str[i] != number_str[string_length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int read_positive_integer() {
    int input_number;
    printf("Enter a positive integer: ");
    if (scanf("%d", &input_number) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        return 0;
    }

    if (input_number <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        return 0;
    }
    
    return input_number;
}

void check_abundant_number(int input_number) {
    if (is_abundant(input_number)) {
        printf("%d is an Abundant Number.\n", input_number);
    } else {
        printf("%d is not an Abundant Number.\n", input_number);
    }
}

void check_palindrome_number(int input_number) {
    if (is_palindrome(input_number)) {
        printf("%d is a Palindrome Number.\n", input_number);
    } else {
        printf("%d is not a Palindrome Number.\n", input_number);
    }
}

int main(void) {
    int input_number = read_positive_integer();
    
    if (input_number == 0) {
        return 0;
    }

    check_abundant_number(input_number);
    check_palindrome_number(input_number);

    return 0;
}
