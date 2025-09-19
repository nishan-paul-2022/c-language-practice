/*
 * Purpose: Demonstrates sorting an array of characters using the Bubble Sort algorithm.
 * Topic: Arrays, sorting algorithms, characters, loops, input/output.
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void clear_input_buffer();
int get_array_size();
int get_valid_input(char characters[], int array_size);
void bubble_sort_chars(char arr[], int size);
void display_sorted_characters(char arr[], int size);

int main(void) {    
    int array_size = get_array_size();
    if (array_size == -1) {
        return 0;
    }
    
    char characters[BUFFER_SIZE];
    int actual_count = get_valid_input(characters, array_size);
    if (actual_count != array_size) {
        printf("Expected %d characters but got %d.\n", array_size, actual_count);
        return 0;
    }
    
    bubble_sort_chars(characters, array_size);
    display_sorted_characters(characters, array_size);
    
    return 0;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_array_size() {
    int size;
    printf("Enter the number of characters to sort (max %d): ", BUFFER_SIZE - 1);

    if (scanf("%d", &size) != 1 || size <= 0 || size >= BUFFER_SIZE) {
        printf("Invalid input. Please enter a positive integer less than %d.\n", BUFFER_SIZE);
        return -1;
    }

    clear_input_buffer();

    return size;
}


int get_valid_input(char characters[], int array_size) {
    printf("Enter %d characters as a string:\n", array_size);
    
    
    if (fgets(characters, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input string.\n");
        return -1;
    }
    
    
    characters[strcspn(characters, "\n")] = '\0';
    
    
    int count = 0;
    for (int i = 0; characters[i] != '\0'; i++) {
        if (characters[i] != ' ') {
            characters[count++] = characters[i];
        }
    }
    
    return count;
}


void bubble_sort_chars(char arr[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        
        for (int j = 0; j < size - 1 - i; j++) {
            
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display_sorted_characters(char characters[], int size) {
    printf("Sorted characters (ascending order):\n");

    for (int i = 0; i < size; i++) {
        printf("%c ", characters[i]);
    }
    
    printf("\n");
}
