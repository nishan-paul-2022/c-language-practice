/*
 * Purpose: Calculates the sum of digits and reverses a given integer.
 * Topic: Number Manipulation, Loops, Functions, Input/Output
*/

#include <stdio.h>
#include <math.h>

int sum_digits(int num) {
    int sum = 0;
    int temp_num = num;
    
    if (temp_num < 0) {
        temp_num = -temp_num;
    }
    
    while (temp_num > 0) {
        sum += temp_num % 10;
        temp_num /= 10;
    }

    return sum;
}

int reverse_number(int num) {
    int reversed_num = 0;
    int temp_num = num;
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

int main(void) {
    int number;
    printf("Enter an integer: ");
    
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a long integer.\n");
        return 0;
    }
    
    int sum_of_digits = sum_digits(number);
    int reversed_number = reverse_number(number);
    
    printf("Sum of digits: %d\n", sum_of_digits);
    printf("Reversed number: %d\n", reversed_number);

    return 0;
}
