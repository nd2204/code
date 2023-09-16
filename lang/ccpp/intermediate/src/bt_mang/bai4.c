// bai4.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.
// Đọc dữ liệu từ tệp ra màn hình.
// Chương trình chính gọi thực hiện các hàm trên.

#include "helper.h"
#include "bt_mang.h"

// 3. Hiển thị các số nguyên tố có trong mảng.
int mang_b4c3(int n) {
    if (n == 0 || n == 1) return 0;
    else if (n == 2) return 1;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// 4. Nhập một số x từ bàn phím, kiểm tra xem x có trong mảng không?
void mang_b4c4(int arr[], int size, int key) {
    int found = 0;
    int i = 0;
    while (i < size) {
        if (arr[i] == key) {
            printf("\nfound %d at index %d", key, i);
            found = 1;
        }
        i++;
    }
    if (!found) printf("value %d not found", key);
}

// 5. Ghi vào tệp daysochan.txt những phần tử chẵn của dãy.
void mang_b4c5(int arr[], int arr_size, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!isNullFilePtr(file)) {
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] % 2 == 0)
                fprintf(file, "%d ", arr[i]);
        }
        fclose(file);
    } 
    file_print(filename);
}
