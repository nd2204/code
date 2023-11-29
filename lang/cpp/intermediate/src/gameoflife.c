/*|====================================|*/
/*| gameoflife.c                       |*/
/*|                                    |*/
/*| nd2204@github.com                  |*/
/*|====================================|*/

#include "gameoflife.h"
#include "helper.h"

#define WIDTH 80
#define HEIGHT 30
#define max(a,b) (a) > (b) ? a : b

const int backgroundASCIIChar = ' ';
const int cellASCIIChar = '#';

void generate_map(unsigned int seed, char* filename, size_t width, size_t height) {
    srand(seed);
    char* name = malloc(strlen(filename) + 1);
    if (filename == NULL) {
        strcpy(name, "mapgen.txt");
    } else {
        strcpy(name, filename);
    }

    FILE* file = fopen(name, "w");
    if (file == NULL) {
        fprintf(stderr, "Can not open file");
    }

    fprintf(file, "%d\n", seed);

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) { 
            if (rand()%2 == 0) {
                fputc('1', file);
            } else {
                fputc('0', file);
            }
        }
        fputc('\n', file);
    }

    free(name);
    fclose(file);
}

static int get_col(FILE* file) {
    int c, col = 0;
    int max = 0;
    fseek(file, 0, SEEK_SET);

    while (fgetc(file) != '\n')
        ;

    while ((c = fgetc(file)) != EOF) {
        if (c != '\n') {
            col++;
        } else {
            max = max(max, col);
            col = 0;
        }
    }
    return max;
}

static int get_row(FILE* file) {
    int c, row = 0;
    fseek(file, 0, SEEK_SET);
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            row++;
        }
    }
    return row - 1;
}

static int** fetch_map(FILE* file) {
    int c;
    int row = get_row(file);
    int col = get_col(file);

    // Allocating cells table (don't forget to free)
    int** cells = malloc_matrix(row, col);
    // Skip first row
    while (fgetc(file) != '\n')
        ;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            c = fgetc(file);
            if (c == '0') {
                cells[i][j] = backgroundASCIIChar;
            } else if (c == '1') {
                cells[i][j] = cellASCIIChar;
            }
        }
    }

    return cells;
}

void printCells(int** cells, size_t row, size_t col) {
    // decor printer
    printf("    ┌");
    for (int i = 0; i < col; i++) {
        printf("─");
    }
    printf("┐\n");

    // Main printer
    for (int i = 0; i < row; i++) {
        printf("%3d │",i);
        for (int j = 0; j < col; j++) {
            printf("%c", cells[i][j]);
        }
        printf("│\n");
    }

    // decor printer
    printf("    └");
    for (int i = 0; i < col; i++) {
        printf("─");
    }
    printf("┘\n");
}

static int calculateNeighbors(int row, int col, size_t width ,size_t height,int** copy) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // skip the current cell

            int ni = row + i;
            int nj = col + j;

            if (ni >= 0 && nj >= 0 && ni < height && nj < width) {
                if (copy[ni][nj] == cellASCIIChar) {
                    count++;
                }
            }
        }
    }
    return count;
}

static void calculateStep(int** cells, size_t height, size_t width) {
    int** copy = malloc_matrix(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = cells[i][j];
        }
    }

    for (int x = 0; x < height; x++) {
        for (int y = 0; y < width; y++) {
            // Tính những tế bào còn sống xung quanh nó

            int activeNeighbors = calculateNeighbors(x, y, width, height, copy);
            /* printf("%3d,%3d = %d\t", x, y, activeNeighbors); */

            // Đặt trạng thái cho tế bào theo quy luật của Game of Life
            if (copy[x][y] == cellASCIIChar && (activeNeighbors == 2 || activeNeighbors == 3)) {
                // tế bào còn sống với 2 hoặc 3 tế bào cạnh nó còn sống thì tiếp tục sống
                cells[x][y] = cellASCIIChar;
            } else if (copy[x][y] == backgroundASCIIChar && activeNeighbors == 3) {
                // tế bào chết với 2 hoặc 3 tế bào cạnh nó còn sống thì nó sẽ sống
                cells[x][y] = cellASCIIChar;
            } else {
                // Các tế bào còn lại sẽ chết hoặc tiếp tục chết
                cells[x][y] = backgroundASCIIChar;
            }
        }
    }

    free_matrix((void**)copy, height);
}

void execute(unsigned int seed) {
    generate_map(seed, "mapgen.txt", WIDTH, HEIGHT);
    FILE* file = fopen("mapgen.txt", "r");
    int height = get_row(file);
    printf("height: %d\n", height);
    int width = get_col(file);
    printf("width: %d\n", width);
    int** cells = fetch_map(file);
    fclose(file);
    printf("\n%p", cells);
    printf("\x1B[2J");
    while (1) {
        printf("\x1B[2J");
        printCells(cells, height, width);
        calculateStep(cells, height, width);
        printf("\x1b[H");
        usleep(8000 * 10);
    }
    free_matrix((void**)cells, height);
}
