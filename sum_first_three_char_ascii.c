#include <stdio.h>
#include <string.h> // For strlen

int main() {
    int num_test_cases;
    char input_string[100]; // Buffer to store the input string
    int ascii_sum;          // Variable to store the sum of ASCII values

    // Read the total number of test cases
    scanf("%d", &num_test_cases);
    // Consume the newline character left by scanf
    getchar(); 

    // Process each test case
    while (num_test_cases--) {
        ascii_sum = 0;
        // Read a string containing only alphabetic characters
        // %[a-zA-Z] reads characters until a non-alphabetic character is encountered
        scanf("%[a-zA-Z]", input_string);
        // Consume the newline character after reading the string
        getchar(); 

        // Calculate the sum of ASCII values of the first three characters
        // Ensure the string has at least 3 characters before accessing them
        int len = strlen(input_string);
        if (len >= 1) {
            ascii_sum += input_string[0];
        }
        if (len >= 2) {
            ascii_sum += input_string[1];
        }
        if (len >= 3) {
            ascii_sum += input_string[2];
        }

        // Print the calculated sum
        printf("%d\n", ascii_sum);
    }

    return 0;
}
