/*
 * Purpose: Demonstrates the use of `perror` to print system error messages and `clearerr` to clear stream error indicators.
 * Topic: Error Handling, Standard Library Functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE *file_ptr = NULL;
    const char *filename = "FH perror 1.txt";

    // --- Demonstrate perror after a failed file operation ---

    // Attempt to open a file that likely does not exist in read mode.
    file_ptr = fopen(filename, "r");

    // Check if fopen failed
    if (file_ptr == NULL) {
        // perror prints the string followed by ": " and the system error message
        perror("Error opening file (first call)");

        // clearerr clears the error indicators for the given stream.
        // It does NOT reset errno.
        if (file_ptr != NULL) { // This condition will be false if fopen failed
            clearerr(file_ptr);
            printf("Called clearerr() on a valid file pointer (this part won't execute if fopen failed).\n");
        } else {
            printf("fopen failed, so clearerr() was not called on a valid file pointer.\n");
        }

        // Call perror again. Since errno is still set from the failed fopen,
        // this will likely print the same error message as the first call.
        perror("Error after clearerr attempt (second call)");

    } else {
        // If fopen succeeded (e.g., if "FH perror 1.txt" exists)
        printf("Successfully opened file '%s'.\n", filename);
        // In a real scenario, you would perform operations here and then use clearerr/ferror.
        // For this example, we'll just close it.
        fclose(file_ptr);
    }

    return 0;
}
