// Bài số 11
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. Xóa phần tử âm có trong mảng.
void mang_b11c3(int arr[], int arr_size) {
    int count = 0;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < 0) count++;
    }

    int j = 0;
    int temp[arr_size - count]; 
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] >= 0) {
            temp[j] = arr[i];
            j++;
        }
    }

    printIntArray(temp, arr_size-count);
}

// 5. Ghi vào tệp daysoam.txt các phần tử âm của dãy. Đọc dữ liệu từ tệp ra màn hình.
