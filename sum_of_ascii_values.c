/*
 * Purpose: Reads string and prints the sum of ASCII values of its characters.
 * Topic: Strings, Loops, ASCII values
 */

#include <stdio.h>
#include <string.h>

int ascii_sum(const char *str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        printf("%c %d\n", str[i], str[i]);
        sum += str[i];
    }
    return sum;
}

int main(void) {
    printf("Enter the number of test cases: ");
    int num_test_cases;
    scanf("%d", &num_test_cases);

    for (int t = 0; t < num_test_cases; t++) {
        printf("Enter a string: ");
        char input_string[100];
        scanf("%s", input_string);
        int sum = ascii_sum(input_string);
        printf("%d\n", sum);
    }

    return 0;
}
