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

float average_positive_int(float* array, const int arraySize);

void bai3() {
    int n = geti("Nhap n: ");
    float mang[n];

    initFloatArray(mang,n);
    printFloatArray(mang,n);

    printf("Trung bình cộng các số dương trong mảng là: %.2f", 
           average_positive_int(mang,n));
}

float average_positive_int(float* array, const int arraySize) {
    int total = 0;
    int count = 0;

    for (int i = 0; i < arraySize; i++) {
        if (array[i] > 0) {
            count++;
            total += array[i];
        }
    }

    return (count!=0)? total/count : 0;
}
