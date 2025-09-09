/*
 * Purpose: Calculates the Greatest Common Divisor (GCD), Least Common Multiple (LCM),
 *          and lists all common divisors of two integers.
 * Topic: Number Theory, Loops, Conditional Statements, Functions, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>

// Function to calculate GCD using Euclidean algorithm
long int calculate_gcd(long int num1, long int num2)
{
    // Take absolute values to handle negative inputs
    num1 = abs(num1);
    num2 = abs(num2);

    while (num2 != 0)
    {
        long int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

// Function to calculate LCM using GCD
long int calculate_lcm(long int num1, long int num2)
{
    if (num1 == 0 || num2 == 0)
    {
        return 0; // LCM is 0 if any number is 0
    }
    // LCM(a, b) = |a * b| / GCD(a, b)
    return (long int)abs(num1 * num2) / calculate_gcd(num1, num2);
}

// Function to list common divisors
void list_common_divisors(long int num1, long int num2)
{
    num1 = abs(num1);
    num2 = abs(num2);

    if (num1 == 0 && num2 == 0)
    {
        printf("Common divisors: All integers (undefined for 0,0)\n");
        return;
    }
    if (num1 == 0)
    {
        printf("Common divisors of 0 and %ld: All divisors of %ld\n", num2, num2);
        for (long int i = 1; i <= num2; i++)
        {
            if (num2 % i == 0)
            {
                printf("%ld ", i);
            }
        }
        printf("\n");
        return;
    }
    if (num2 == 0)
    {
        printf("Common divisors of %ld and 0: All divisors of %ld\n", num1, num1);
        for (long int i = 1; i <= num1; i++)
        {
            if (num1 % i == 0)
            {
                printf("%ld ", i);
            }
        }
        printf("\n");
        return;
    }

    printf("Common divisors: ");
    long int smaller = (num1 < num2) ? num1 : num2;
    for (long int i = 1; i <= smaller; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            printf("%ld ", i);
        }
    }
    printf("\n");
}

int main()
{
    long int numA, numB;

    printf("Enter two integers separated by a comma (e.g., 48, 18) (or Ctrl+D to exit): ");
    while (scanf("%ld, %ld", &numA, &numB) == 2)
    {
        printf("\nFor numbers %ld and %ld:\n", numA, numB);

        list_common_divisors(numA, numB);

        long int gcd = calculate_gcd(numA, numB);
        printf("GREATEST COMMON DIVISOR (GCD): %ld\n", gcd);

        long int lcm = calculate_lcm(numA, numB);
        printf("LEAST COMMON MULTIPLE (LCM): %ld\n", lcm);

        printf("\n----------------------------------------\n");
        printf("Enter two integers separated by a comma (e.g., 48, 18) (or Ctrl+D to exit): ");
    }

    printf("\nExiting program.\n");
    return EXIT_SUCCESS;
}
