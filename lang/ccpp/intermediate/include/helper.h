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
int get_int(const char*, ...);
float get_float(const char*, ...);
// Functions to prompt the user for input array elements for different data types
int* initIntArray(size_t);
float* initFloatArray(size_t);
int** initIntMatrix(size_t, size_t);
void free_matrix(void* matrix, size_t, size_t);
// Functions to print out the array on the screen
void printIntArray(int*, size_t);
void printFloatArray(float*, size_t);
void printIntMatrix(int**, size_t, size_t);

void file_print(const char*);
int compare(float*, int, int);

bool isNullFilePtr(FILE*);
bool isNullPtr(const void*);

#endif /* ifndef helper_h */
