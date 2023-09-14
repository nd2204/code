// bai4.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.
// 3. Hiển thị các số nguyên tố có trong mảng.
// 4. Nhập một số x từ bàn phím, kiểm tra xem x có trong mảng không?
// 5. Ghi vào tệp daysochan.txt những phần tử chẵn của dãy.
// Đọc dữ liệu từ tệp ra màn hình.
// Chương trình chính gọi thực hiện các hàm trên.

#include "helper.h"
#include "baitap.h"

int isPrime(int n);
void linearSearch(int arr[], int size, int key);
void daysochan(int arr[], int size);

void bai4() {
    // Testing
    int mang[] = {9, 5, 5, 21, 12, 2, 1, 5, 4, 11};
    int n = sizeof(mang) / sizeof(mang[0]);

    /* int n = geti("Nhap n: "); */
    /* int array[n]; */

    printf("Mang vua nhap la: ");
    printIntArray(mang, n);

    printf("\nCac so nguyen to co trong mang la: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(mang[i]))
            printf("%d ", mang[i]);
    }

    int x = geti("Nhap x: ");
    linearSearch(mang, n, x);

    daysochan(mang, n);
}

int isPrime(int n) {
    if (n == 0 || n == 1) return 0;
    else if (n == 2) return 1;

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void linearSearch(int arr[], int size, int key) {
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

void daysochan(int arr[], int arr_size) {
    char filename[] = "daysochan.txt"; 
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open file");
        exit(1);
    } 

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] % 2 == 0)
            fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
    file_print(filename);
}
