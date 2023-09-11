// helper.c

#include "helper.h"
#include <string.h>

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
    return sign * rand()%range;
}

float randFloat(const float range) {
    int sign = (rand()%2 == 0) ? 1 : -1;
    return ((float)rand()/(float)RAND_MAX) * range * sign;
}

int geti(const char string[]) {
    int input;
    int validate;

    do {

        printf("%s", string);
        validate = scanf("%d", &input);

        // Consume all character in stdin to handle invalid input (similar to fflush(stdin))
        while (getchar() != '\n');

        // Check for invalid input
        if (validate != 1) {
            printf("Nhap sai. Vui long nhap so nguyen!\n");
        }

    } while (validate != 1);

    return input; 
}

float getf(const char string[]) {
    float input;
    int validate;

    do {

        printf("%s", string);
        validate = scanf("%f", &input);

        // Consume all character in stdin to handle invalid input (similar to fflush(stdin))
        while (getchar() != '\n');

        // Check for invalid input
        if (validate != 1) {
            printf("Nhap sai. Vui long nhap so thuc!\n");
        }

    } while (validate != 1);

    return input; 
}

double getd(const char string[]) {
    double input;
    int validate;

    do {

        printf("%s", string);
        validate = scanf("%lf", &input);

        // Consume all character in stdin to handle invalid input (similar to fflush(stdin))
        while (getchar() != '\n');

        // Check for invalid input
        if (validate != 1) {
            printf("Nhap sai. Vui long nhap so thuc!\n");
        }

    } while (validate != 1);

    return input; 
}

void initIntArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i+1);
        /* arr[i] = geti(""); */
        arr[i] = randInt(10);
    }
} 

void initFloatArray(float arr[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i+1);
        arr[i] = getf("");
        /* arr[i] = randFloat(10); */
    }
} 

void initDoubleArray(double arr[], const int size) {
    for (int i = 0; i < size; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i+1);
        /* arr[i] = getd(""); */
        arr[i] = randFloat(100);
    }
} 

void printIntArray(int arr[], const int size) {
    printf("\n{");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(",");
        }
    }
    printf("}\n");
}

void printFloatArray(float arr[], const int size) {
    printf("\n{");
    for (int i = 0; i < size; i++) {
        printf("%.2f", arr[i]);
        if (i != size-1) {
            printf(",");
        }
    }
    printf("}\n");
}

void printDoubleArray(double arr[], const int size) {
    printf("\n{");
    for (int i = 0; i < size; i++) {
        printf("%lf", arr[i]);
        if (i != size-1) {
            printf(",");
        }
    }
    printf("}\n");
}

void file_print(const char filename[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error! Can not open file."); return;
    }

    char ch;
    int length = strlen(filename);
    draw_title(filename);
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);
}
