/*
 * Purpose: Demonstrates dynamic string allocation and handling.
 * Topic: Dynamic memory allocation, String handling, malloc/free
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    printf("Dynamic String Allocation Demo\n");
    printf("==============================\n");
    
    int length;

    printf("Enter text length: ");

    if (scanf("%d", &length) == 1 && length > 0) {
        clear_input_buffer();
        
        char *dynamic_str = (char*)malloc((length + 1) * sizeof(char));

        if (dynamic_str != NULL) {
            printf("Enter text (max %d chars): ", length);

            if (fgets(dynamic_str, length + 1, stdin) != NULL) {
                dynamic_str[strcspn(dynamic_str, "\n")] = '\0';
                printf("Dynamic string: '%s'\n", dynamic_str);
            }
            
            free(dynamic_str);
        } else {
            printf("Memory allocation failed\n");
        }
    }

    clear_input_buffer();
    
    return 0;
}
