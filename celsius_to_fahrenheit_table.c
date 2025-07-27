/*
 * Purpose: To print a table converting Celsius to Fahrenheit.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main() {
    double fahrenheit, celsius;

    printf("Celsius\t\tFahrenheit\n");
    printf("-------\t\t----------\n");

    for (celsius = 0; celsius <= 500; celsius += 10) {
        fahrenheit = (1.8 * celsius) + 32;
        printf("%6.2f\t\t%10.2f\n", celsius, fahrenheit);
    }

    return 0;
}
