/*
 * Purpose: Demonstrates the use of the `remove()` function to delete a file and interpret its return value.
 * Topic: File System Operations, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    const char *filename_to_remove = "ironman+Batman.jpg";
    int remove_status;

    // Attempt to remove the file
    // The remove() function deletes a file. It returns 0 on success,
    // and a non-zero value on failure (setting errno)
    remove_status = remove(filename_to_remove);

    // Check the return status of remove()
    if (remove_status == 0) {
        printf("File '%s' deleted successfully.\n", filename_to_remove);
    } else {
        // If remove() failed, print an informative error message
        // perror() prints the string passed to it, followed by ": ",
        // and then the system error message corresponding to the current errno value
        perror("Error deleting file");
        // Optionally, you could print the raw return value as well:
        // printf("remove() returned %d\n", remove_status);
    }

    return remove_status; // Return 0 on success, non-zero on failure
}
