/*
 * Purpose: Demonstrates string copying using strcpy and pointer manipulation.
 * Topic: Pointers, Strings, String Copying
 */

#include <stdio.h>
#include <string.h> // For strcpy and strlen

int main() {
    char dest_str[100] = "CUET";     // Destination string
    char src_str[100] = "CSE1604085"; // Source string
    char *str_ptr;                   // Pointer to character

    // Assign the base address of the destination string to the pointer.
    // 'dest_str' decays to a pointer to its first element ('C').
    str_ptr = dest_str;

    // Copy a portion of the source string to the destination string.
    // src_str + 3 points to the 4th character of src_str, which is 'E'.
    // So, "E1604085" will be copied into dest_str.
    // strcpy returns a pointer to the destination string.
    char *copy_result_ptr = strcpy(dest_str, src_str + 3);

    // Calculate the length of the copied string for demonstration.
    // The string copied is "E1604085", which has a length of 8.
    int copied_length = strlen(src_str + 3);

    // Print results:
    // (str_ptr + 1) points to the second character of the original dest_str ("UET").
    // copy_result_ptr is the pointer returned by strcpy (points to dest_str).
    // dest_str now contains the copied string "E1604085".
    printf("Substring of original dest_str: %s\n", (str_ptr + 1));
    printf("Pointer returned by strcpy: %p\n", copy_result_ptr);
    printf("Copied string in dest_str: %s\n", dest_str);
    printf("Length of copied string: %d\n", copied_length);

    return 0;
}
