#include <stdio.h>
#include <string.h>

int main(void) {
    int num_test_cases;
    char input_line[1000]; // Buffer to store the input line
    char *token;           // Pointer to store each token (word)
    int word_count;        // Counter for the number of words

    // Read the total number of test cases
    scanf("%d", &num_test_cases);
    // Consume the newline character left by scanf
    getchar(); 

    // Process each test case
    while (num_test_cases--) {
        word_count = 0;
        // Read a line of text from input
        // %[^\n] reads characters until a newline is encountered
        scanf("%[^\n]", input_line);
        // Consume the newline character after reading the line
        getchar(); 

        // Use strtok to tokenize the string by spaces
        // The first call to strtok needs the string itself
        token = strtok(input_line, " ");

        // Loop through all tokens
        while (token != NULL) {
            word_count++;
            // Subsequent calls to strtok use NULL to continue tokenizing the same string
            token = strtok(NULL, " ");
        }

        // Print the word count for the current line
        printf("%d\n", word_count);
    }

    return 0;
}
