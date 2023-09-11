// bai1.c
// Viết chương trình dưới dạng hàm thực hiện các chức năng sau:
// 1. Nhập một mảng số nguyên một chiều gồm n phần tử vào bộ nhớ động.
// 2. Hiển thị dãy vừa nhập ra màn hình trên một hàng.
// 3. Tính trung bình cộng các số âm trong mảng
// 4. Sắp xếp mảng tăng dần.In mảng sau khi sắp xếp ra màn hình.
// 5. Ghi vào tệp mangnguyen.txt những phần tử lẻ của mảng.
// Đọc dữ liệu từ tệp ra màn hình.
// Viết chương trình chính gọi thực hiện các hàm trên.

#include "helper.h"
#include "baitap.h"

static void swap(int* elem1, int* elem2) {
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

void bubbleSort(int arr[], const int size, const char mode[3]) {
    int i,j;
    int swapped;
    if (strcmp(mode, "asc") == 0) {
        for (i = 0; i < size - 1; i++) {
            swapped = 0;
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                    swapped = 1;
                }
            }
            if (swapped == 0) {
                break;       
            }
        }
    } else if (strcmp(mode, "des") == 0) {
        for (i = 0; i < size - 1; i++) {
            swapped = 0;
            for (j = 0; j < size - i - 1; j++) {
                if (arr[j] < arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                    swapped = 1;
                }
            }
            if (swapped == 0) {
                break;       
            }
        }
    } else {
        printf("\nError! Invalid sorting method.\nArray remain unsorted\n");
        return;
    }
}

static float avgNeg(int arr[], const int size) {
    int count = 0;
    float total = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            total += arr[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return total/count;
}

static void LogOdds(int arr[], const int size) {
    char filename[] = "mangnguyen.txt";
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error! Can not open file."); return;
    }
    
    for (int i = 0; i < size; i++) {
        if (arr[i]%2 != 0) {
            fprintf(file, "%d ", arr[i]);
        }
    }
    printf("\nDa luu mang vao tep %s\n", filename);
    fclose(file);
    file_print(filename); 
}

void bai1() {
    // Prompt the user for input
    int n = geti("Nhap so phan tu: ");
    int array[n];

    // Prompt the user for input array values and print it out afterward
    initIntArray(array, n);
    printIntArray(array, n);
    
    // print out the average of negative values inside an array
    printf("Trung binh cong cac so am trong mang la: %f", avgNeg(array, n));
    bubbleSort(array, n, "asc");
    printIntArray(array,n);

    LogOdds(array, n); 
}
