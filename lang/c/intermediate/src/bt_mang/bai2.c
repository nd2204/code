// bai2.c
// 1. Nhập một mảng số thực một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. Kiểm tra trong dãy có hai số âm bằng nhau mà cạnh nhau hay không. Đưa thông báo ra màn hình.
void mang_b2c3(float array[], const int size) {
    float buffer[size];
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
        printf("%f ", buffer[i]);
    }
    printf("\n");
}

// 4. Nhập vào một số x kiểu nguyên. Tính trung bình cộng của x giá trị đầu tiên trong mảng.
float mang_b2c4(float array[], const int size) {
    int x, count = 0;
    float total = 0;
    do {
        x  = get_int("Nhap gia tri x: "); 
    } while (x > size || x < 1);

    for (int i = 0; i < x; i++) {
        total += array[i]; 
        count++;
    }

    return (count != 0)? total/count : 0;
} 

// 5. Ghi vào tệp mangthuc.txt những phần tử dương của mảng. Đọc dữ liệu từ tệp ra màn hình.
void mang_b2c5(float array[], int size, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!isNullFilePtr(file)) {
        fprintf(file, "Các giá trị dương trong mảng là:\n");
        for (int i = 0; i < size; i++) {
            if (array[i] > 0) {
                fprintf(file, "%.2f ", array[i]);
            }
        }
        fclose(file);
        file_print(filename);
    }
}
