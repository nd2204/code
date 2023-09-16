// bai9.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. Tính tổng các phần tử âm và lẻ trong mảng
int mang_b9c3(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && arr[i]%2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}
