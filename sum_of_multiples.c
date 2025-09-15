#include <stdio.h>

int sum_of_multiples_up_to(int limit) {
    int sum = 0; // sum of numbers divisible by 3 or 5

    for (int i = 1; i < limit; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main(void) {
    int limit = 1000; // upper limit (exclusive)
    int sum = sum_of_multiples_up_to(limit);

    printf("Sum of multiples of 3 or 5 below %d: %d\n", limit, sum);

    return 0;
}
