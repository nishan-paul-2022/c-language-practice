/*
 * Purpose: Demonstrates accessing a specific character within a 2D array of characters.
 * Topic: 2D Arrays, Character Arrays, Input/Output
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_LEN 100


typedef struct {
    int rows;
    int cols;
} Dimensions;

typedef struct {
    char **data;
    int rows;
    int cols;
} Grid;

typedef struct {
    int row;
    int col;
} Index;

typedef struct {
    int success;
    char *error_message;
} Result;


Dimensions create_dimensions(int rows, int cols) {
    Dimensions dim = {rows, cols};
    return dim;
}

Index create_index(int row, int col) {
    Index idx = {row, col};
    return idx;
}

Result create_success_result() {
    Result result = {1, NULL};
    return result;
}

Result create_error_result(const char *message) {
    Result result = {0, (char*)message};
    return result;
}


Result read_dimensions(Dimensions *dim) {
    printf("Enter the number of rows and columns (e.g., 3 4): ");
    if (scanf("%d %d", &dim->rows, &dim->cols) != 2) {
        return create_error_result("Invalid input for dimensions.");
    }
    while (getchar() != '\n'); 
    return create_success_result();
}

Result read_indices(Index *idx) {
    printf("\nEnter the row and column index to access (e.g., 1 2): ");
    if (scanf("%d %d", &idx->row, &idx->col) != 2) {
        return create_error_result("Invalid input for indices.");
    }
    return create_success_result();
}


Grid create_empty_grid(Dimensions dim) {
    Grid grid;
    grid.rows = dim.rows;
    grid.cols = dim.cols;
    grid.data = (char**)malloc(dim.rows * sizeof(char*));
    
    if (grid.data != NULL) {
        for (int i = 0; i < dim.rows; i++) {
            grid.data[i] = (char*)malloc((dim.cols + 1) * sizeof(char));
            if (grid.data[i] == NULL) {
                
                for (int j = 0; j < i; j++) {
                    free(grid.data[j]);
                }
                free(grid.data);
                grid.data = NULL;
                break;
            }
        }
    }
    
    return grid;
}

void destroy_grid(Grid *grid) {
    if (grid->data != NULL) {
        for (int i = 0; i < grid->rows; i++) {
            free(grid->data[i]);
        }
        free(grid->data);
        grid->data = NULL;
    }
}

Result is_valid_grid(Grid grid) {
    if (grid.data == NULL) {
        return create_error_result("Memory allocation failed for character grid.");
    }
    return create_success_result();
}


Result fill_grid_row(Grid grid, int row_num, const char *input) {
    if (row_num < 0 || row_num >= grid.rows) {
        return create_error_result("Row index out of bounds.");
    }
    
    if ((int)strlen(input) > grid.cols) {
        return create_error_result("Input row is too long.");
    }
    
    strncpy(grid.data[row_num], input, grid.cols);
    
    
    for (int j = strlen(input); j < grid.cols; j++) {
        grid.data[row_num][j] = ' ';
    }
    grid.data[row_num][grid.cols] = '\0'; 
    
    return create_success_result();
}

Result populate_grid(Grid grid) {
    char input_buffer[MAX_ROW_LEN];
    
    printf("Enter the characters for the %d x %d grid, one row per line:\n", 
           grid.rows, grid.cols);
    
    for (int i = 0; i < grid.rows; i++) {
        printf("Row %d: ", i);
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            return create_error_result("Failed to read row input.");
        }
        
        input_buffer[strcspn(input_buffer, "\n")] = 0; 
        
        Result fill_result = fill_grid_row(grid, i, input_buffer);
        if (!fill_result.success) {
            return fill_result;
        }
    }
    
    return create_success_result();
}


Result validate_index(Index idx, Dimensions dim) {
    if (idx.row < 0 || idx.row >= dim.rows || 
        idx.col < 0 || idx.col >= dim.cols) {
        return create_error_result("Indices out of bounds.");
    }
    return create_success_result();
}


void display_grid(Grid grid) {
    printf("\nGrid entered:\n");
    for (int i = 0; i < grid.rows; i++) {
        for (int j = 0; j < grid.cols; j++) {
            putchar(grid.data[i][j]);
        }
        putchar('\n');
    }
}

void display_character_at_index(Grid grid, Index idx) {
    printf("\nCharacter at [%d][%d]: %c\n", 
           idx.row, idx.col, grid.data[idx.row][idx.col]);
}

void display_error(const char *message) {
    fprintf(stderr, "%s\n", message);
}

int main(void) {
    Dimensions dim;
    Index idx;
    Result result;
    
    
    result = read_dimensions(&dim);
    if (!result.success) {
        display_error(result.error_message);
        return 0;
    }
    
    
    Grid grid = create_empty_grid(dim);
    result = is_valid_grid(grid);
    if (!result.success) {
        display_error(result.error_message);
        return 0;
    }
    
    
    result = populate_grid(grid);
    if (!result.success) {
        display_error(result.error_message);
        destroy_grid(&grid);
        return 0;
    }
    
    
    display_grid(grid);
    
    
    result = read_indices(&idx);
    if (!result.success) {
        display_error(result.error_message);
        destroy_grid(&grid);
        return 0;
    }
    
    
    result = validate_index(idx, dim);
    if (!result.success) {
        display_error(result.error_message);
        destroy_grid(&grid);
        return 0;
    }
    
    
    display_character_at_index(grid, idx);
    
    
    destroy_grid(&grid);

    return 0;
}
