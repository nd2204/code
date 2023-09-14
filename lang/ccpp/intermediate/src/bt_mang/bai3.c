// bai3.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số thực một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.
// 3. Tính trung bình cộng các số dương trong mảng.
// 4. Sắp xếp mảng tăng dần. In mảng sau khi sắp xếp ra màn hình.
// 5. Ghi vào tệp D:/data.txt những phần tử nhỏ hơn 10 trong mảng.
// Chương trình chính gọi thực hiện các hàm trên.

#include "helper.h"
#include "baitap.h"

static float average_positive_int(float* array, const int arraySize);
void mergeSortFloat(float array[], int left, int right);
void Write2File(float arr[], int arr_size);

void bai3() {
    // Testing
    /* float mang[] = {9.20, 5.10, 5.00, 21.50, 12.60, 2.20, 1.00, 5.00, 4.00, 11.00}; */
    /* int n = sizeof(mang) / sizeof(mang[0]); */

    int n = geti("Nhap n: ");
    float mang[n];
    initFloatArray(mang,n);

    printf("Mang vua nhap la:\n");
    printFloatArray(mang,n);

    printf("Trung bình cộng các số dương trong mảng là: %.2f", 
           average_positive_int(mang,n));

    mergeSortFloat(mang, 0, n - 1);
    printf("Mang sau khi duoc sap xep:\n");
    printFloatArray(mang, n);

    Write2File(mang, n);
    file_print("/mnt/d/data.txt"); 
}

void Write2File(float arr[], int arr_size) {
    FILE* file = fopen("/mnt/d/data.txt", "w");
    if (file == NULL) {
        fprintf(stderr ,"Could not open file!");
        exit(1);
    }

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < 10) {
            fprintf(file ,"%.2f ", arr[i]);
        }
    }

    fclose(file);
}

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

void mergeSortFloat(float arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortFloat(arr, left, mid);
        mergeSortFloat(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

static float average_positive_int(float* array, const int arraySize) {
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
