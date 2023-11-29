// bai10.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số thực một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một cột.

#include "helper.h"
#include "bt_mang.h"

// 3. Tìm vị trí các phần tử âm nhỏ nhất trong mảng
void mang_b10c3(int arr[], int arr_size) {
    printf("\nVi tri cac phan tu am nho nhat trong mang la: ");
    int min = arr[0];

    for (int i = 1; i < arr_size; i++) {
        if (min > arr[i])
            min = arr[i];
    }

    // linearSearch function
    mang_b4c4(arr, arr_size, min);
}

// 4. Sắp xếp mảng giảm dần.

// 5. Ghi vào tệp mangduong.txt những phần tử dương của mảng. Đọc dữ liệu từ tệp ra màn hình.

