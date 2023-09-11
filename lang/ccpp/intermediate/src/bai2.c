// bai2.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số thực một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.
// 3. Kiểm tra trong dãy có hai số âm bằng nhau mà cạnh nhau hay không. Đưa thông báo ra màn hình.
// 4. Nhập vào một số x kiểu nguyên. Tính trung bình cộng của x giá trị đầu tiên trong mảng.
// 5. Ghi vào tệp mangthuc.txt những phần tử dương của mảng. Đọc dữ liệu từ tệp ra màn hình.
// Chương trình chính gọi thực hiện các hàm trên.

#include "helper.h"
#include "baitap.h"
#include <stdio.h>

static void print_equal_adjacent_negative(float array[], const int size);
static float average_first_x(float array[], const int size);
static void file_write_positive(float array[], const int size);

void bai2() {
    int n = geti("Nhap n: ");
    float mang[n];

    initFloatArray(mang,n);
    printFloatArray(mang,n);
    
    print_equal_adjacent_negative(mang,n);
    printf("Trung bình cộng x giá trị đầu tiên là: %.2f", average_first_x(mang, n)); 

    file_write_positive(mang,n);
    file_print("mangthuc.txt");
}

static void file_write_positive(float array[], const int size) {
    FILE* file = fopen("mangthuc.txt", "w");
    if (file == NULL) {
        printf("Error! File can not be open or created.");
        return;
    }

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            fputc(array[i], file); 
        }
    }

    fclose(file);
}

static float average_first_x(float array[], const int size) {
    int x;
    float total = 0;
    int count = 0;
    do {
        x  = geti("Nhap gia tri x: "); 
    } while (x > size || x < 1);

    for (int i = 0; i < x; i++) {
        total += array[i]; 
        count++;
    }

    return (count != 0)? total/count : 0;
} 

static void print_equal_adjacent_negative(float array[], const int size) {
    int buffer[size];
    int index = 0;
    for (int i = 0; i < size - 1; i++) {
        if ((array[i] < 0) && (array[i] == array[i+1])) {
            buffer[index] = array[i];
            index++;
        }
    }

    if (index == 0) {
        printf("\nKhông tồn tại hai số âm bằng nhau và nằm cạnh nhau trong mảng\n");
        return;
    }
    printf("\nCác số âm có phần tử nằm cạnh nó bằng nhau trong mảng là: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", buffer[i]);
    }
}

