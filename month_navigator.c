/*
 * Purpose: Displays the current month and the next month based on user input.
 * Topic: Switch Statement, Input Handling, Loops
 */

#include <stdio.h>


const char* MONTHS[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};


const char* get_month_name(int month_num) {
    if (month_num >= 1 && month_num <= 12) {
        return MONTHS[month_num];
    }
    return "Invalid";
}


int get_next_month_number(int current_month) {
    return (current_month == 12) ? 1 : current_month + 1;
}


int is_valid_month(int month) {
    return (month >= 1 && month <= 12);
}


void display_month_sequence(int month_number) {
    if (is_valid_month(month_number)) {
        const char* current_month = get_month_name(month_number);
        const char* next_month = get_month_name(get_next_month_number(month_number));
        printf("Result: %s is followed by %s.\n", current_month, next_month);
    } else {
        printf("Please enter a valid month number (1-12).\n");
    }
}


int get_month_input() {
    int month;
    
    printf("Enter month number (1-12, or 0 to exit): ");
    
    if (scanf("%d", &month) != 1) {
        return -1;
    }
    
    return month;
}

void clear_input_buffer() {
    while (getchar() != '\n');
}

int main(void) {
    printf("Month Sequence Display Program\n");
    printf("==============================\n");

    int month_number;

    printf("This program shows the current month and next month based on input.\n\n");
        
    while ((month_number = get_month_input()) != -1) {
        if (month_number == 0) {
            printf("Program terminated successfully.\n");
            break;
        }
        
        display_month_sequence(month_number);
        printf("\n");
    }
    
    if (month_number == -1) {
        printf("Invalid input detected. Program terminated.\n");
        clear_input_buffer();
    }
    
    return 0;
}
