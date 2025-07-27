/*
 * Purpose: Calculates the time shown on an analog clock if viewed in a mirror.
 * Topic: Conditional Statements (if-else if), Arithmetic Operations, Time Calculation, Input/Output
 */

#include <stdio.h>

int main()
{
    int numberOfTestCases; // T in original
    int i;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &numberOfTestCases) != 1 || numberOfTestCases < 0)
    {
        printf("Invalid input for number of test cases.\n");
        return 1;
    }

    for (i = 0; i < numberOfTestCases; i++)
    {
        int hours, minutes; // h, m in original
        int reflectedHours, reflectedMinutes;

        printf("Enter time in HH:MM format for test case %d: ", i + 1);
        if (scanf("%d:%d", &hours, &minutes) != 2)
        {
            printf("Invalid time format. Please use HH:MM. Skipping this test case.\n");
            // Clear input buffer
            while (getchar() != '\n' && !feof(stdin) && !ferror(stdin));
            continue;
        }

        // Validate input time
        if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59)
        {
            printf("Invalid time: Hours must be 1-12, minutes 0-59. Skipping this test case.\n");
            continue;
        }

        if (minutes == 0)
        {
            reflectedMinutes = 0;
            if (hours == 12)
            {
                reflectedHours = 12; // 12:00 reflects to 12:00
            }
            else
            {
                reflectedHours = 12 - hours; // e.g., 3:00 reflects to 9:00
            }
        }
        else // minutes != 0
        {
            reflectedMinutes = 60 - minutes;
            if (hours == 12)
            {
                reflectedHours = 11; // 12:XX reflects to 11:YY
            }
            else
            {
                reflectedHours = 11 - hours; // e.g., 3:XX reflects to 8:YY
            }
        }

        // Adjust reflected hours if it becomes 0 (e.g., 11:XX reflects to 00:YY, should be 12:YY)
        if (reflectedHours == 0)
        {
            reflectedHours = 12;
        }

        printf("Reflected time: %02d:%02d\n", reflectedHours, reflectedMinutes);
    }

    return 0;
}
