/*
 * Purpose: Demonstrates sorting an array of characters using the Bubble Sort algorithm.
 * Topic: Arrays, sorting algorithms, characters, loops, input/output.
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function prototypes
void bubble_sort_chars(char arr[], int size);
int get_valid_input(char characters[], int array_size);

int main(void) {
    int array_size;
    char characters[BUFFER_SIZE];
    
    // Prompt user for the number of characters to sort
    printf("Enter the number of characters to sort (max %d): ", BUFFER_SIZE - 1);
    
    // Validate input for array size
    if (scanf("%d", &array_size) != 1 || array_size <= 0 || array_size >= BUFFER_SIZE) {
        printf("Invalid input. Please enter a positive integer less than %d.\n", BUFFER_SIZE);
        return 0;
    }
    
    // Clear input buffer
    while (getchar() != '\n');
    
    // Get characters from user with validation
    int actual_count = get_valid_input(characters, array_size);
    if (actual_count != array_size) {
        printf("Error: Expected %d characters but got %d.\n", array_size, actual_count);
        return 0;
    }
    
    // Sort the characters using bubble sort
    bubble_sort_chars(characters, array_size);
    
    // Display the sorted characters
    printf("Sorted characters (ascending order):\n");
    for (int i = 0; i < array_size; i++) {
        printf("%c ", characters[i]);
    }
    printf("\n");
    
    return 0;
}

/**
 * Function to perform bubble sort on an array of characters
 * @param arr: Array of characters to sort
 * @param size: Number of elements in the array
 */
void bubble_sort_chars(char arr[], int size) {
    int swapped; // Flag to track if any swaps occurred
    
    // Bubble sort algorithm with early termination optimization
    for (int i = 0; i < size - 1; i++) {
        swapped = 0; // Reset flag for each pass
        
        // In each pass, the largest unsorted character "bubbles up" to its correct position
        for (int j = 0; j < size - 1 - i; j++) {
            // If current character is greater than the next character, swap them
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set flag to indicate a swap occurred
            }
        }
        
        // If no swaps occurred, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

/**
 * Function to get valid input from user
 * @param characters: Array to store the characters
 * @param array_size: Expected number of characters
 * @return: Actual number of characters entered
 */
int get_valid_input(char characters[], int array_size) {
    printf("Enter %d characters, separated by spaces or newlines:\n", array_size);
    
    // Use fgets for safe input to read the characters
    if (fgets(characters, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input string.\n");
        return -1;
    }
    
    // Remove the trailing newline character if it exists
    characters[strcspn(characters, "\n")] = '\0';
    
    // Count actual characters (excluding spaces)
    int count = 0;
    for (int i = 0; characters[i] != '\0'; i++) {
        if (characters[i] != ' ') {
            characters[count++] = characters[i];
        }
    }
    
    return count;
}