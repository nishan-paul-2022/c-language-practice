/*
 * Purpose: Demonstrates the use of the `remove()` function to delete a file and interpret its return value.
 * Topic: File System Operations, Error Handling
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int remove_file(const char *filename) {
    int remove_status = remove(filename);
    
    if (remove_status == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }
    
    return remove_status;
}

int main(void) {
    const char *filename_to_remove = "files/file_remove.jpg";
    
    return remove_file(filename_to_remove);
}
