/*
 * Purpose: Demonstrates the effect of the carriage return (\r) escape sequence in printf.
 *          The text after \r overwrites the beginning of the current line.
 * Topic: Basic I/O, Escape Sequences
 */

#include <stdio.h>
#include <unistd.h>

// Example 1: Basic carriage return behavior
void Example1() {
    printf("Example 1: Basic Carriage Return\n");
    printf("Before\rAfter\n");
    printf("Notice how 'After' overwrote 'Before'\n\n");
    
}

// Example 2: Carriage return with longer second text
void Example2() {
    printf("Example 2: Overwriting with shorter text\n");
    printf("Longer text\rShort\n");
    printf("Notice how 'Short' only overwrote part of 'Longer text'\n\n");
}

// Example 3: Simulating a countdown timer
void Example3() {
    printf("Example 3: Countdown Timer Simulation\n");
    printf("Counting down: ");
    for (int i = 5; i >= 0; i--) {
        printf("\rCounting down: %d seconds remaining", i);
        fflush(stdout); // Force output to be displayed immediately
        sleep(1);
    }
    printf("\nCountdown finished!\n\n");
}

// Example 4: Progress indicator
void Example4() {
    printf("Example 4: Progress Indicator\n");
    printf("Processing: ");
    for (int i = 0; i <= 100; i += 10) {
        printf("\rProcessing: %d%% complete", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\nProcessing complete!\n\n");
}

// Example 5: Overwriting with spaces
void Example5() {
    printf("Example 5: Clearing text with spaces\n");
    printf("This text will be partially cleared:\n");
    printf("This line has a lot of text\r                    \rJust this remains\n");
}

int main(void) {
    printf("Carriage Return Demonstration\n");
    printf("=============================\n\n");
    
    Example1();
    Example2();
    Example3();
    Example4();
    Example5();
    
    return 0;
}