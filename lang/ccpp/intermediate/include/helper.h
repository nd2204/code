// helper.h

#ifndef HELPER_H

#define HELPER_H
#include <ctype.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int randInt(const int range);
float randFloat(const float range);

// Functions to prompt for numeric input
int geti(const char string[]);
float getf(const char string[]);
double getd(const char string[]);

// Functions to prompt the user for input array elements for different data types
void initIntArray(int arr[], const int size);
void initFloatArray(float arr[], const int size);
void initDoubleArray(double arr[], const int size);

// Functions to print out the array on the screen
void printIntArray(int arr[], const int size);
void printFloatArray(float arr[], const int size);
void printDoubleArray(double arr[], const int size);

void file_print(const char string[]);

int compare(float array[], int elem1, int elem2);

#endif /* ifndef helper_h */
