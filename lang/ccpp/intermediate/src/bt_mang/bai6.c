// bai6.c
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.

#include "helper.h"
#include "bt_mang.h"

// Kiểm tra trong dãy có hai số dương bằng nhau mà cạnh nhau hay không. Đưa thông báo ra màn hình.
void mang_b6c3(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > 0 && arr[i] == arr[i+1])
            printf("%d ", arr[i]);
    }
}

static void merge(int arr[], int l, int m, int r) {
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l+i];
    for (j = 0; j < n2; j++)
        R[j] = arr[j+m+1];

    printf("\nLeft: "); printIntArray(L, n1);
    printf("Right "); printIntArray(R, n2);

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] > R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

// Sắp xếp giá trị của dãy theo chiều giảm dần. (mergeSort) (int)
void mang_b6c5(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mang_b6c5(arr, l, m);
        mang_b6c5(arr, m+1, r);
        
        merge(arr, l, m, r);
    }
}
