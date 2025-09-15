/*
 * Purpose: Reverses a given string, including spaces.
 * Topic: Strings, Loops, Character Swapping, Input/Output
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    int num_test_cases;
    scanf("%d", &num_test_cases);
    getchar(); // Consume leftover newline

    for (int t = 0; t < num_test_cases; t++) {
        char str[1000];
        scanf("%[^\n]", str);
        getchar(); // Consume newline

        int left = 0, right = strlen(str) - 1;
        while (left < right) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }

        printf("%s\n", str);
    }

    return 0;
}
