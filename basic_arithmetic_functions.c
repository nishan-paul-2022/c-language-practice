/*
 * Purpose: Demonstrates basic arithmetic operations (addition and subtraction) using functions.
 * Topic: Functions, Basic Arithmetic
 */

#include <stdio.h>

// Function prototypes
int add(int num1, int num2);
int subtract(int num1, int num2);

int main()
{
    int x = 10;
    int y = 20;
    int sumResult;
    int subtractResult;

    sumResult = add(x, y);
    subtractResult = subtract(y, x); // Changed to y - x for positive result as in original output

    printf("%d + %d = %d\n", x, y, sumResult);
    printf("%d - %d = %d\n", y, x, subtractResult); // Changed output format for clarity

    return 0;
}

// Function to add two integers
int add(int num1, int num2)
{
    return num1 + num2;
}

// Function to subtract two integers
int subtract(int num1, int num2)
{
    return num1 - num2;
}
