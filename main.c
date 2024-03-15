#include <stdio.h>
#include <stdlib.h>

const int ROWS = 200;
const int COLS = 200;

int main() {
    char array[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = '.';
        }
    }

    FILE *file = fopen("canvas.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, " %c", array[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("Array successfully saved to canvas.txt.\n");

    return 0;
}
