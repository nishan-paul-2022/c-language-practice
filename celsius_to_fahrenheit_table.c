/*
 * Purpose: Prints a table converting Celsius to Fahrenheit.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main(void) {
    int start, end;
    printf("Enter two integers for celsius (start and end of range, separated by space): ");
    scanf("%d %d", &start, &end);
    if (start > end) {
        printf("Invalid range. Start must be less than or equal to end.\n");
        return 0;
    }

    printf("Celsius\t\tFahrenheit\n");
    printf("-------\t\t----------\n");

    for (int celsius = start; celsius <= end; celsius += 10) {
        double fahrenheit = (1.8 * celsius) + 32;
        printf("%d\t\t%10.2f\n", celsius, fahrenheit);
    }

    return 0;
}
