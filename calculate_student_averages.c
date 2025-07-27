/*
 * Purpose: Reads student scores from separate Bangla, Math, and English files,
 *          calculates the average score for each student, and writes the
 *          roll number and average to an output file.
 * Topic: File I/O, Data Processing, Basic Arithmetic
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE

// Define input and output filenames
#define BANGLA_FILE "bangla.txt"
#define MATH_FILE "math.txt"
#define ENGLISH_FILE "english.txt"
#define OUTPUT_FILE "FH_average.txt"

int main(void) {
    FILE *file_bangla, *file_math, *file_english, *file_output;
    double average_score;
    int roll_number;
    int bangla_score, math_score, english_score;

    // Open input files in read mode
    file_bangla = fopen(BANGLA_FILE, "r");
    if (file_bangla == NULL) {
        perror("Error opening Bangla scores file");
        return EXIT_FAILURE;
    }

    file_math = fopen(MATH_FILE, "r");
    if (file_math == NULL) {
        perror("Error opening Math scores file");
        fclose(file_bangla); // Close previously opened file
        return EXIT_FAILURE;
    }

    file_english = fopen(ENGLISH_FILE, "r");
    if (file_english == NULL) {
        perror("Error opening English scores file");
        fclose(file_bangla); // Close previously opened files
        fclose(file_math);
        return EXIT_FAILURE;
    }

    // Open output file in write mode
    file_output = fopen(OUTPUT_FILE, "w");
    if (file_output == NULL) {
        perror("Error opening output file");
        fclose(file_bangla); // Close previously opened files
        fclose(file_math);
        fclose(file_english);
        return EXIT_FAILURE;
    }

    // Read data from files and calculate averages
    // The loop continues as long as we can successfully read roll and Bangla score.
    // It assumes data in all files is synchronized by roll number.
    while (fscanf(file_bangla, "%d %d", &roll_number, &bangla_score) == 2) {
        // Read corresponding scores from Math and English files
        // We expect these reads to also succeed if files are synchronized.
        if (fscanf(file_math, "%d %d", &roll_number, &math_score) != 2) {
            fprintf(stderr, "Warning: Mismatch or error reading Math score for roll %d. Skipping.\n", roll_number);
            // Attempt to read the next line from English to maintain sync, though it might also fail.
            // A more robust solution would handle this error more gracefully.
            if (fscanf(file_english, "%d %d", &roll_number, &english_score) != 2) {
                 fprintf(stderr, "Warning: Mismatch or error reading English score for roll %d.\n", roll_number);
            }
            continue; // Skip to the next iteration if Math read failed
        }
        if (fscanf(file_english, "%d %d", &roll_number, &english_score) != 2) {
            fprintf(stderr, "Warning: Mismatch or error reading English score for roll %d. Skipping.\n", roll_number);
            continue; // Skip to the next iteration if English read failed
        }

        // Calculate the average score. Use 3.0 for floating-point division.
        average_score = (double)(bangla_score + math_score + english_score) / 3.0;

        // Print the average to the console
        printf("Roll: %d, Average: %.2lf\n", roll_number, average_score);

        // Write the roll number and average to the output file
        if (fprintf(file_output, "%d %.2lf\n", roll_number, average_score) < 0) {
            perror("Error writing to output file");
            // Continue processing other students if possible, but note the error.
        }
    }

    // Close all files
    fclose(file_bangla);
    fclose(file_math);
    fclose(file_english);
    fclose(file_output);

    printf("\nAverage calculation complete. Results saved to '%s'.\n", OUTPUT_FILE);

    return 0; // Indicate successful execution
}
