// main.c

#include "helper.h"
#include "baitap.h"
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 30

char cells[HEIGHT][WIDTH];
const char backgroundASCIIChar = '.';
const char cellASCIIChar = '#';

void initCells() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) { 
            if (rand()%2 == 0) {
                cells[row][col] = cellASCIIChar;
            } else {
                cells[row][col] = backgroundASCIIChar;
            }
        }
    }
}

void printCells() {
    // decor printer
    printf("    ┌");
    for (int i = 0; i < WIDTH; i++) {
        printf("─");
    }
    printf("┐\n");

    // Main printer
    for (int i = 0; i < HEIGHT; i++) {
        printf("%3d │",i);
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", cells[i][j]);
        }
        printf("│\n");
    }

    // decor printer
    printf("    └");
    for (int i = 0; i < WIDTH; i++) {
        printf("─");
    }
    printf("┘\n");
}

int calculateNeighbors(int row, int col, char copy[HEIGHT][WIDTH]) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue; // skip the current cell
            
            int ni = row + i;
            int nj = col + j;

            if (ni >= 0 && nj >= 0 && ni < HEIGHT && nj < WIDTH) {
                if (copy[ni][nj] == cellASCIIChar) {
                    count++;
                }
            }
        }
    }
    return count;
}

void calculateStep() {
    char copy[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            copy[i][j] = cells[i][j];
        }
    }

    for (int x = 0; x < HEIGHT; x++) {
        for (int y = 0; y < WIDTH; y++) {
            // Tính những tế bào còn sống xung quanh nó

            int activeNeighbors = calculateNeighbors(x, y, copy);
            /* printf("%3d,%3d = %d\t", x, y, activeNeighbors); */

            // Đặt trạng thái cho tế bào theo quy luật của Game of Life
            if (copy[x][y] == cellASCIIChar && (activeNeighbors == 2 || activeNeighbors == 3)) {
                // tế bào còn sống với 2 hoặc 3 tế bào cạnh nó còn sống thì tiếp tục sống
                cells[x][y] = cellASCIIChar;
        }
            else if (copy[x][y] == backgroundASCIIChar && activeNeighbors == 3) {
                // tế bào chết với 2 hoặc 3 tế bào cạnh nó còn sống thì nó sẽ sống
                cells[x][y] = cellASCIIChar;
            }
            else {
                // Các tế bào còn lại sẽ chết hoặc tiếp tục chết
                cells[x][y] = backgroundASCIIChar;
            }
        }
    }
}

int main() {
    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    initCells();
    printf("\x1B[2J");
    while (1) {
        printf("\x1B[2J");
        printCells();
        calculateStep();
        printf("\x1b[H");
        usleep(8000 * 10);
    }
}

// Yeu cau nguoi dung nhap kich thuoc cho mang
/* int n = geti("Nhap n: "); */

// Khai bao mang nguyen
/* int mang[n]; */
// Testing
/* int mang[] = {9, 5, 5, 21, 12, 2, 1, 5, 4, 11, -2, -21, -11}; */
/* int n = sizeof(mang) / sizeof(mang[0]); */

// Khai bao mang thuc
/* float mang[n]; */
// Testing
/* float mang[] = {9.20, 5.10, 5.00, 21.50, 12.60, 2.20, 1.00, 5.00, 4.00, 11.00, -11.00, -21.00, -21.00, -30.50}; */
/* int n = sizeof(mang) / sizeof(mang[0]); */
