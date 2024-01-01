// bai1.c
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. Tính trung bình cộng các số âm trong mảng
float mang_b1c3(int arr[], int size) {
    int count = 0;
    float total = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            total += arr[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return total/count;
}

static void swap(int* elem1, int* elem2) {
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

// 4. Sắp xếp mảng tăng dần. In mảng sau khi sắp xếp ra màn hình.
void mang_b1c4(int arr[], int size) {
    int i,j;
    int swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;       
        }
    }
    printIntArray(arr, size);
}

// 5. Ghi vào tệp mangnguyen.txt những phần tử lẻ của mảng.
void mang_b1c5(int arr[], int size, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!isNullFilePtr(file)) {
        for (int i = 0; i < size; i++) {
            if (arr[i]%2 != 0) {
                fprintf(file, "%d ", arr[i]);
            }
        }
        printf("\nDa luu mang vao tep %s\n", filename);
        fclose(file);
        file_print(filename);
    }
}
