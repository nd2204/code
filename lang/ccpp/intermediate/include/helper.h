// helper.h

#ifndef HELPER_H

#define HELPER_H
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int randInt(const int);
void swap_int(int *, int  *);
float randFloat(const float);

// Functions to prompt for numeric input
int geti(const char*, ...);
float getf(const char*, ...);

// Functions to prompt the user for input array elements for different data types
int* initIntArray(size_t);
float* initFloatArray(size_t);
int** initIntMatrix(size_t, size_t);

// Functions to print out the array on the screen
void printIntArray(int arr[], const int size);
void printFloatArray(float arr[], const int size);
void printIntMatrix(int**, int row, int col);

void file_print(const char string[]);
int compare(float array[], int elem1, int elem2);

bool isNullFilePtr(FILE*);
bool isNullPtr(void* ptr);

#endif /* ifndef helper_h */
