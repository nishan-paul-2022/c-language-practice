/*
 * Purpose: Calculates and compares costs for two different phone call billing plans (Mile and Juice) based on call durations.
 * Topic: Loops, Conditional Statements, Arithmetic Operations, Input/Output
 */

#include <stdio.h>

int read_test_cases() {
    int num;
    scanf("%d", &num);
    return num;
}

int read_call_count() {
    int num;
    scanf("%d", &num);
    return num;
}

int read_call_duration() {
    int duration;
    scanf("%d", &duration);
    return duration;
}

void clear_input_buffer() {
    while (getchar() != '\n');
}

int calculate_mile_cost(int duration) {
    return ((duration / 30) + 1) * 10;
}

int calculate_juice_cost(int duration) {
    return ((duration / 60) + 1) * 15;
}

void print_result(int case_num, int mile_cost, int juice_cost) {
    if (mile_cost < juice_cost) {
        printf("Case %d: Mile %d\n", case_num, mile_cost);
    } else if (juice_cost < mile_cost) {
        printf("Case %d: Juice %d\n", case_num, juice_cost);
    } else {
        printf("Case %d: Mile Juice %d\n", case_num, mile_cost);
    }
}

int main(void) {
    int test_cases = read_test_cases();
    if (test_cases < 0) {
        printf("Invalid test case count\n");
        return 0;
    }

    for (int i = 0; i < test_cases; i++) {
        printf("\n--- Test Case %d ---\n", i + 1);
        int call_count = read_call_count();
        if (call_count <= 0) {
            printf("Invalid call count\n");
            clear_input_buffer();
            continue;
        }

        printf("Enter %d call durations:\n", call_count);
        int mile_cost = 0, juice_cost = 0;
        for (int j = 0; j < call_count; j++) {
            int duration = read_call_duration();
            if (duration < 0) {
                printf("Invalid call duration\n");
                clear_input_buffer();
                break;
            }
            mile_cost += calculate_mile_cost(duration);
            juice_cost += calculate_juice_cost(duration);
        }
        print_result(i + 1, mile_cost, juice_cost);
    }

    return 0;
}
