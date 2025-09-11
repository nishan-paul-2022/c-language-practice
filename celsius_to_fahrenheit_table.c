/*
 * Purpose: To print a table converting Celsius to Fahrenheit.
 * Topic: Loops, Basic I/O
 */

#include <stdio.h>

int main() {
    printf("Celsius\t\tFahrenheit\n");
    printf("-------\t\t----------\n");

    for (int celsius = 0; celsius <= 500; celsius += 10) {
        double fahrenheit = (1.8 * celsius) + 32;
        printf("%d\t\t%10.2f\n", celsius, fahrenheit);
    }

    return 0;
}
