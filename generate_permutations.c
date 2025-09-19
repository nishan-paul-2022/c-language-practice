/*
 * Purpose: Generates and prints all permutations of three distinct numbers from 1 to 3.
 * Topic: Nested Loops, Permutations, Conditional Logic
 */

#include <stdio.h>

void generate_permutations() {
    for (int num1 = 1; num1 <= 3; num1++) {
        for (int num2 = 1; num2 <= 3; num2++) {
            if (num2 != num1) {
                for (int num3 = 1; num3 <= 3; num3++) {
                    if (num3 != num1 && num3 != num2) {
                        printf("%d, %d, %d\n\n", num1, num2, num3);
                    }
                }
            }
        }
    }
}

int main(void) {
    generate_permutations();
    return 0;
}
