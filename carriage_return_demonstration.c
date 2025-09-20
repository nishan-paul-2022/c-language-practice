/*
 * Purpose: Demonstrates the use of carriage return (\r) for text manipulation.
 * Topic: Text formatting and console output control
*/

#include <stdio.h>
#include <unistd.h>

void basic_carriage_return() {
    printf("Example 1: Basic Carriage Return\n");
    printf("Before\rAfter\n");
    printf("Notice how 'After' overwrote 'Before'\n\n");
}

void overwrite_with_shorter_text() {
    printf("Example 2: Overwriting with shorter text\n");
    printf("Longer text\rShort\n");
    printf("Notice how 'Short' only overwrote part of 'Longer text'\n\n");
}

void simulate_countdown_timer() {
    printf("Example 3: Countdown Timer Simulation\n");
    printf("Counting down: ");

    for (int i = 5; i >= 0; i--) {
        printf("\rCounting down: %d seconds remaining", i);
        fflush(stdout);
        sleep(1);
    }

    printf("\nCountdown finished!\n\n");
}

void show_progress_indicator() {
    printf("Example 4: Progress Indicator\n");
    printf("Processing: ");

    for (int i = 0; i <= 100; i += 10) {
        printf("\rProcessing: %d%% complete", i);
        fflush(stdout);
        sleep(1);
    }
    
    printf("\nProcessing complete!\n\n");
}

void clear_text_with_spaces() {
    printf("Example 5: Clearing text with spaces\n");
    printf("This text will be partially cleared:\n");
    printf("This line has a lot of text\r                    \rJust this remains\n");
}

int main(void) {
    printf("Carriage Return Demonstration\n");
    printf("=============================\n\n");
    
    basic_carriage_return();
    overwrite_with_shorter_text();
    simulate_countdown_timer();
    show_progress_indicator();
    clear_text_with_spaces();
    
    return 0;
}
