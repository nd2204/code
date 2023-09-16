// bai3.c
// 1. Nhập một mảng số thực một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. Tính trung bình cộng các số dương trong mảng.
float mang_b3c3(float* array, const int arraySize) {
    float total = 0;
    int count = 0;

    for (int i = 0; i < arraySize; i++) {
        if (array[i] > 0) {
            count++;
            total += array[i];
        }
    }

    return (count!=0)? total/count : 0;
}

// 4. Sắp xếp mảng tăng dần. In mảng sau khi sắp xếp ra màn hình.
static void merge(float arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1; // left - mid
    int n2 = right - mid; // mid - right

    float L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + j + 1];

    i = 0, j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mang_b3c4(float arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mang_b3c4(arr, left, mid);
        mang_b3c4(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

// 5. Ghi vào tệp D:/data.txt những phần tử nhỏ hơn 10 trong mảng.
void mang_b3c5(float arr[], int arr_size, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!isNullFilePtr(file)) {
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] < 10) {
                fprintf(file ,"%.2f ", arr[i]);
            }
        }
        fclose(file);
        file_print(filename);
    }
}
