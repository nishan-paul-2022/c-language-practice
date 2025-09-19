/*
 * Purpose: Calculates the sum of digits and reverses a given integer.
 * Topic: Number Manipulation, Loops, Functions, Input/Output
*/

#include <stdio.h>
#include <math.h>

long int sum_digits(long int num) {
    long int sum = 0;
    long int temp_num = num;
    
    if (temp_num < 0) {
        temp_num = -temp_num;
    }
    
    while (temp_num > 0) {
        sum += temp_num % 10;
        temp_num /= 10;
    }
    return sum;
}

long int reverse_number(long int num) {
    long int reversed_num = 0;
    long int temp_num = num;
    int sign = 1;
    
    if (temp_num < 0) {
        sign = -1;
        temp_num = -temp_num;
    }
    
    while (temp_num > 0) {
        reversed_num = reversed_num * 10 + temp_num % 10;
        temp_num /= 10;
    }
    return sign * reversed_num;
}

void process_number() {
    long int number;
    printf("Enter an integer: ");
    
    if (scanf("%ld", &number) != 1) {
        printf("Invalid input. Please enter a long integer.\n");
        return;
    }
    
    long int sum_of_digits = sum_digits(number);
    long int reversed_number = reverse_number(number);
    
    printf("Sum of digits: %ld\n", sum_of_digits);
    printf("Reversed number: %ld\n", reversed_number);
}

int main(void) {
    process_number();
    return 0;
}
