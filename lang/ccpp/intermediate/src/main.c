// main.c

#include "helper.h"
#include "baitap.h"

void initMatrix(int row, int col, int arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("a[%d][%d] = ", i, j); scanf("%d", &arr[i][j]);
        }
    } 
}

void printMatrix(int row, int col, int arr[row][col]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    } 
}

int main() {
    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    int m = geti("Nhap so hang: "); 
    int n = geti("Nhap so cot: "); 
    int arr[m][n];

    printf("Nhap mang:\n");
    initMatrix(m, n, arr);
    printMatrix(m, n, arr);
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
