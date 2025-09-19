/*
 * Purpose: Calculates the time shown on an analog clock if viewed in a mirror.
 * Topic: Conditional Statements, Arithmetic Operations, Time Calculation, Input/Output, Functions
 */

#include <stdio.h>


int read_number_of_test_cases() {
    printf("Enter the number of test cases: ");
    int number_of_test_cases;
    if (scanf("%d", &number_of_test_cases) != 1 || number_of_test_cases < 0) {
        printf("Invalid input for number of test cases.\n");
        return -1;
    }
    return number_of_test_cases;
}


int read_time(int test_case_index, int *hours, int *minutes) {
    printf("Enter time in HH:MM format for test case %d: ", test_case_index + 1);
    if (scanf("%d:%d", hours, minutes) != 2) {
        printf("Invalid time format. Please use HH:MM. Skipping this test case.\n");
        
        while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
        return -1;
    }
    return 0;
}


int validate_time(int hours, int minutes) {
    if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59) {
        printf("Invalid time: Hours must be 1-12, minutes 0-59. Skipping this test case.\n");
        return -1;
    }
    return 0;
}


void calculate_reflected_time(int hours, int minutes, int *reflected_hours, int *reflected_minutes) {
    if (minutes == 0) {
        *reflected_minutes = 0;
        if (hours == 12) {
            *reflected_hours = 12; 
        } else {
            *reflected_hours = 12 - hours; 
        }
    } else { 
        *reflected_minutes = 60 - minutes;
        if (hours == 12) {
            *reflected_hours = 11; 
        } else {
            *reflected_hours = 11 - hours; 
        }
    }

    
    if (*reflected_hours == 0) {
        *reflected_hours = 12;
    }
}


void display_reflected_time(int reflected_hours, int reflected_minutes) {
    printf("Reflected time: %02d:%02d\n", reflected_hours, reflected_minutes);
}

int main(void) {
    int number_of_test_cases = read_number_of_test_cases();
    if (number_of_test_cases < 0) {
        return 0;
    }

    for (int i = 0; i < number_of_test_cases; i++) {
        int hours, minutes;
        int reflected_hours, reflected_minutes;

        if (read_time(i, &hours, &minutes) == -1 || validate_time(hours, minutes) == -1) {
            continue;
        }

        calculate_reflected_time(hours, minutes, &reflected_hours, &reflected_minutes);
        display_reflected_time(reflected_hours, reflected_minutes);
    }

    return 0;
}
