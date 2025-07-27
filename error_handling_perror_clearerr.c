// Purpose: Demonstrates the use of `perror` to print system error messages and `clearerr` to clear stream error indicators.
// Topic: Error Handling, Standard Library Functions

#include <stdio.h>
#include <stdlib.h> // For exit()
#include <errno.h>  // For errno

int main() {
    FILE *file_ptr = NULL;
    const char *filename = "FH perror 1.txt";

    // --- Demonstrate perror after a failed file operation ---

    // Attempt to open a file that likely does not exist in read mode.
    // This will set errno if fopen fails.
    file_ptr = fopen(filename, "r");

    // Check if fopen failed
    if (file_ptr == NULL) {
        // perror prints the string passed to it, followed by ": ",
        // and then the system error message corresponding to the current errno value.
        perror("Error opening file (first call)");

        // clearerr clears the error indicators (EOF and error flags) for the given stream.
        // It does NOT reset errno. errno is a global variable that holds the last system error.
        // Calling clearerr on a NULL pointer is undefined behavior, so we check first.
        if (file_ptr != NULL) { // This condition will be false if fopen failed
            clearerr(file_ptr);
            // If we were to perform another operation on file_ptr and then check ferror(),
            // clearerr() would be useful. For perror, it doesn't directly change its output
            // as perror relies on errno, not the stream's error flags.
            printf("Called clearerr() on a valid file pointer (this part won't execute if fopen failed).\n");
        } else {
            printf("fopen failed, so clearerr() was not called on a valid file pointer.\n");
            // Even though clearerr wasn't called, errno is still set from fopen.
            // The next perror will likely print the same error message.
        }

        // Call perror again. Since errno is still set from the failed fopen,
        // this will likely print the same error message as the first call.
        // This demonstrates that clearerr does not affect errno.
        perror("Error after clearerr attempt (second call)");

    } else {
        // If fopen succeeded (e.g., if "FH perror 1.txt" exists)
        printf("Successfully opened file '%s'.\n", filename);
        // In a real scenario, you would perform operations here and then use clearerr/ferror.
        // For this example, we'll just close it.
        fclose(file_ptr);
    }

    return 0; // Indicate success (or failure handled by returning 1 earlier)
}
