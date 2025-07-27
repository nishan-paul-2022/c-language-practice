/*
 * Purpose: Calculates the average of a specified number of double-precision floating-point numbers.
 * Topic: Input/Output, Loops, Basic Statistics
 */

#include <stdio.h>

int main()
{
    int count; // n in original
    double sum = 0.0; // z in original
    double number; // x in original

    printf("Enter the number of values you want to average: ");
    if (scanf("%d", &count) != 1 || count <= 0)
    {
        printf("Invalid input. Please enter a positive integer for the count.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", count);
    for (int i = 0; i < count; i++) // Loop 'count' times to read numbers
    {
        if (scanf("%lf", &number) != 1)
        {
            printf("Invalid input. Please enter a numeric value.\n");
            return 1;
        }
        sum += number;
    }

    printf("The average of the %d numbers is: %.3lf\n", count, sum / count);

    return 0;
}
