// Purpose: Checks if a number is an Abundant Number and a Palindrome Number.
// Topic: Number Theory, String Manipulation, Loops

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For abs() if needed for negative numbers, though we'll validate for positive

// Function to check if a number is an Abundant Number
// An abundant number is a number for which the sum of its proper divisors is greater than the number itself.
int is_abundant(int num) {
    if (num <= 0) {
        return 0; // Abundant numbers are typically positive integers
    }
    int sum_of_proper_divisors = 0;
    // Iterate through possible divisors from 1 up to num/2
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum_of_proper_divisors += i;
        }
    }
    return sum_of_proper_divisors > num;
}

// Function to check if a number is a Palindrome Number
// A palindrome number reads the same forwards and backward.
int is_palindrome(int num) {
    if (num < 0) {
        // Palindromes are usually considered for non-negative numbers.
        // If negative numbers are allowed, one might consider the absolute value.
        // For simplicity, we'll treat negative numbers as not palindromes here.
        return 0;
    }
    
    char number_str[20]; // Buffer to hold the string representation of the number
    // Convert the integer to a string. A buffer size of 20 is sufficient for standard integer types.
    sprintf(number_str, "%d", num);
    
    int string_length = strlen(number_str);
    int half_length = string_length / 2;
    
    // Compare characters from the beginning and end, moving inwards
    for (int i = 0; i < half_length; i++) {
        if (number_str[i] != number_str[string_length - 1 - i]) {
            return 0; // Not a palindrome if characters don't match
        }
    }
    return 1; // It's a palindrome if all compared characters matched
}

int main() {
    int input_number;

    printf("Enter a positive integer: ");
    // Read input and validate that it's an integer
    if (scanf("%d", &input_number) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Validate that the input number is positive
    if (input_number <= 0) {
        fprintf(stderr, "Error: Please enter a positive integer.\n");
        return 0;
    }

    // Check and print if it's an Abundant Number
    if (is_abundant(input_number)) {
        printf("%d is an Abundant Number.\n", input_number);
    } else {
        printf("%d is not an Abundant Number.\n", input_number);
    }

    // Check and print if it's a Palindrome Number
    if (is_palindrome(input_number)) {
        printf("%d is a Palindrome Number.\n", input_number);
    } else {
        printf("%d is not a Palindrome Number.\n", input_number);
    }

    return 0;
}
