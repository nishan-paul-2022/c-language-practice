/*
 * Purpose: Reads string and prints the sum of ASCII values of its characters.
 * Topic: Strings, Loops, ASCII values
 */

#include <stdio.h>
#include <string.h>

int ascii_sum(const char *str) {
    int sum = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        printf("index %d - character: %c | ASCII: %d\n", i, str[i], str[i]);
        sum += str[i];
    }

    return sum;
}

int main(void) {
    int num_test_cases;

    printf("Enter the number of test cases: ");

    scanf("%d", &num_test_cases);

    for (int t = 0; t < num_test_cases; t++) {
        char input_string[100];
        printf("Enter a string: ");
        scanf("%s", input_string);

        int sum = ascii_sum(input_string);
        printf("\nSum of ASCII values: %d\n", sum);
    }

    return 0;
}
