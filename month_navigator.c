// Purpose: Displays the current month and the next month based on user input.
// Topic: Switch Statement, Input Handling, Loops

#include <stdio.h>

// Function to get the name of the next month
const char* get_next_month_name(int current_month_num) {
    switch (current_month_num) {
        case 1: return "FEBRUARY";
        case 2: return "MARCH";
        case 3: return "APRIL";
        case 4: return "MAY";
        case 5: return "JUNE";
        case 6: return "JULY";
        case 7: return "AUGUST";
        case 8: return "SEPTEMBER";
        case 9: return "OCTOBER";
        case 10: return "NOVEMBER";
        case 11: return "DECEMBER";
        case 12: return "JANUARY"; // Special case for December
        default: return "Invalid Month"; // Should not be reached if input is validated
    }
}

// Function to get the name of the current month
const char* get_current_month_name(int month_num) {
    switch (month_num) {
        case 1: return "JANUARY";
        case 2: return "FEBRUARY";
        case 3: return "MARCH";
        case 4: return "APRIL";
        case 5: return "MAY";
        case 6: return "JUNE";
        case 7: return "JULY";
        case 8: return "AUGUST";
        case 9: return "SEPTEMBER";
        case 10: return "OCTOBER";
        case 11: return "NOVEMBER";
        case 12: return "DECEMBER";
        default: return "Invalid Month";
    }
}

int main() {
    int month_number;

    printf("Enter a month number (1-12) to see the current and next month.\n");
    printf("Enter 0 or a non-numeric value to exit.\n");

    // Loop to continuously read month numbers until invalid input or 0 is entered
    while (scanf("%d", &month_number) == 1) {
        if (month_number == 0) {
            printf("Exiting program.\n");
            break; // Exit loop if 0 is entered
        }

        if (month_number >= 1 && month_number <= 12) {
            const char* current_month = get_current_month_name(month_number);
            const char* next_month = get_next_month_name(month_number);
            
            printf("%s is followed by %s.\n", current_month, next_month);
        } else {
            printf("Invalid input: Please enter a number between 1 and 12.\n");
        }
        
        printf("\nEnter another month number (1-12) or 0 to exit: ");
    }
    
    // If the loop terminated due to non-numeric input other than 0
    if (month_number != 0) {
        printf("Invalid input detected. Exiting program.\n");
    }

    return 0; // Indicate successful execution
}
