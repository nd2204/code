// bai5.c
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. Tính trung bình cộng các phần tử trong đoạn x và y. Với x và y nhập từ bàn phím.
void mang_b5c3(int arr[], int arr_size) {
    int x,y;
    float sum = 0, count = 0;

    do {
        printf("\nNhap x va y (1 <= x < y <= %d)\n", arr_size);
        x = get_int("x: ") - 1;
        y = get_int("y: ") - 1;
    } while (x >= arr_size || y >= arr_size || y < 0 || x < 0 || x >= y);

    for (int i = x; i <= y; i++) {
        sum += arr[i];
        count++;
    }

    float average = (!count)? 0 : sum/count;
    
    printf("\nTrung bình cộng các phần tử trong đoạn %d và %d: %f", x + 1, y + 1, average);
}

// 4. Tìm giá trị lớn nhất trong dãy.
int mang_b5c4(int arr[], int arr_size) {
    int max = arr[0];
    for (int i = 0; i < arr_size; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

// 5. Ghi vào tệp mangduong.txt những phần tử dương của mảng. Đọc dữ liệu từ tệp ra màn hình.
