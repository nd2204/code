// helper.c
#include "helper.h"
#include <float.h>
#include <limits.h>
#include <stdarg.h>

static int get_terminal_width() {
    int width = 0;
    FILE *fp = popen("tput cols", "r"); // Run 'tput cols' command and read the output

    if (fp == NULL) {
        perror("popen");
        exit(1);
    }

    // Read the terminal width from the command output
    if (fscanf(fp, "%d", &width) != 1) {
        fprintf(stderr, "Failed to read terminal width.\n");
        exit(1);
    }

    pclose(fp); // Close the pipe

    return width;
}

static void draw_title(const char title[]) {
    /* int length = strlen(title); */
    /* int width = get_terminal_width(); */
    int length = strlen(title);
    int width = 100;
    printf("\n");
    for (int i = 0; i < width / 2 - length / 2 - 1; i++) {
        printf("=");
    }
    printf(" %s ", title);
    for (int i = 0; i < width / 2 - length / 2 - 1; i++) {
        printf("=");
    }
    printf("\n");
}

int randInt(const int range) {
    int sign = (rand()%2 == 0) ? 1 : -1;
    return rand()%range;
}

float randFloat(const float range) {
    int sign = (rand()%2 == 0) ? 1 : -1;
    return ((float)rand()/(float)RAND_MAX) * range * sign;
}

int get_int(const char* format, ...) {
    int input;
    int validate;

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    validate = scanf("%d", &input);
    // Consume all character in stdin to handle invalid input (similar to fflush(stdin))
    while (getchar() != '\n');
    // Check for invalid input
    if (validate != 1) {
        return INT_MAX;
    }
    return input; 
}

float get_float(const char* format, ...) {
    float input;
    int validate;

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    validate = scanf("%f", &input);

    // Consume all character in stdin to handle invalid input (similar to fflush(stdin))
    while (getchar() != '\n');

    // Check for invalid input
    if (validate != 1) {
        return FLT_MAX; 
    }
    return input;
}

int* initIntArray(size_t size) {
    int* arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        /* arr[i] = geti("Nhap gia tri phan tu thu %d: ", i+1); */
        arr[i] = randInt(10);
    }
    return arr;
}

float* initFloatArray(size_t size) {
    float* arr = malloc(sizeof(float) * size);
    for (int i = 0; i < size; i++) {
        /* arr[i] = getf("Nhap gia tri phan tu thu %d: ", i+1); */
        arr[i] = randFloat(10);
    }
    return arr;
}


void printIntArray(int* arr, size_t size) {
    printf("\n{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(",");
        }
    }
    printf("}\n");
}

void printFloatArray(float* arr, size_t size) {
    printf("\n{");
    for (int i = 0; i < size; i++) {
        printf("%.2f", arr[i]);
        if (i != size-1) {
            printf(",");
        }
    }
    printf("}\n");
}

int** malloc_matrix(size_t row, size_t col) {
    int **matrix = (int**)malloc(sizeof(int*)*row);

    for (int i = 0; i < row; i++) {
        *(matrix+i) = (int*)malloc(sizeof(int)*col);
    }

    return matrix;
}

void printIntMatrix(int** matrix, size_t row, size_t col) {
    printf("\n{\n");
    for (int i = 0; i < row; i++) {
        printf("{");
        for (int j = 0; j < col; j++) {
            printf("%d", matrix[i][j]);
            if (j != col-1) {
                printf(",");
            }
        }
        printf("}\n");
    }
    printf("}\n");
}

void free_matrix(void** matrix, size_t row) {
    for (int i = 0; i < row; i++) {
        free(*(matrix+i));
    }
    free(matrix);
}

void file_print(const char filename[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error! Can not open file."); return;
    }

    char ch;
    draw_title(filename);
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}

void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isNullFilePtr(FILE* fileptr) {
    if (fileptr == NULL) {
        fprintf(stderr, "Could not open file");
        return true;
    }
    return false;
}

bool isNullPtr(const void* ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Could not allocate memory");
        return true;
    }
    return false;
}
