/*
 * Purpose: Calculates the time shown on an analog clock if viewed in a mirror.
 * Topic: Conditional Statements (if-else if), Arithmetic Operations, Time Calculation, Input/Output
 */

#include <stdio.h>

int main() {
    int number_of_test_cases;
    int i;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &number_of_test_cases) != 1 || number_of_test_cases < 0) {
        printf("Invalid input for number of test cases.\n");
        return 1;
    }

    for (i = 0; i < number_of_test_cases; i++) {
        int hours, minutes;
        int reflected_hours, reflected_minutes;

        printf("Enter time in HH:MM format for test case %d: ", i + 1);
        if (scanf("%d:%d", &hours, &minutes) != 2) {
            printf("Invalid time format. Please use HH:MM. Skipping this test case.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            continue;
        }

        // Validate input time
        if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59) {
            printf("Invalid time: Hours must be 1-12, minutes 0-59. Skipping this test case.\n");
            continue;
        }

        if (minutes == 0) {
            reflected_minutes = 0;
            if (hours == 12) {
                reflected_hours = 12; // 12:00 reflects to 12:00
            }
            else {
                reflected_hours = 12 - hours; // e.g., 3:00 reflects to 9:0
            }
        }
        else { // minutes != 0
            reflected_minutes = 60 - minutes;
            if (hours == 12) {
                reflected_hours = 11; // 12:XX reflects to 11:YY
            }
            else {
                reflected_hours = 11 - hours; // e.g., 3:XX reflects to 8:YY
            }
        }

        // Adjust reflected hours if it becomes 0 (e.g., 11:XX reflects to 00:YY, should be 12:YY)
        if (reflected_hours == 0) {
            reflected_hours = 12;
        }

        printf("Reflected time: %02d:%02d\n", reflected_hours, reflected_minutes);
    }

    return 0;
}