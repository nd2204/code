// bai7.c
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// 3. In ra các phần tử chia hết cho 3 và nhỏ hơn 50 ra màn hình.
void mang_b7c3(int arr[], int size) {
    printf("\nCác phần tử chia hết cho 3 và nhỏ hơn 50: ");
    for (int i = 0; i < size; i++) {
        if (arr[i]%3 == 0 && arr[i] < 50)
            printf("%d ", arr[i]);
    }    
}

// 4. Nhập số nguyên x và k. Thêm phần tử x vào vị trí thứ k trong mảng.
void mang_b7c4(int arr[], int size) {
    int x, k;
    do {
        printf("Nhap vi tri k (1<=k<=%d)\n", size);
        k = geti("k: ") - 1;
    } while (k < 0 || k >= size);

    x = geti("Nhap gia tri x vi tri %d: ", k+1); 

    printf("\nMang moi sau khi them %d vao vi tri %d: ", x, k + 1);
    int temp[size+1];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    temp[k] = x;
    for (int i = k; i < size + 1; i++) {
        temp[i+1] = arr[i];
    }
    printIntArray(temp, size+1);
}

// 5. Ghi vào tệp daysoam.txt các phần tử âm của dãy. Đọc dữ liệu từ tệp ra màn hình.
void mang_b7c5(int arr[], int size, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!isNullFilePtr(file)) {
        for (int i = 0; i < size; i++) {
            if (arr[i] < 0)
                fprintf(file, "%d ", arr[i]);
        }
        fclose(file);
    }
}
