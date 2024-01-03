/*
    Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng
    sau:
        1. (2 điểm) Nhập một dãy số nguyên gồm n phần tử vào bộ nhớ động.
        2. (2 điểm) Hiển thị dãy vừa nhập ra màn hình trên một hàng.
        3. (2 điểm) In ra màn hình các phần tử chia hết cho 3 và nhỏ hơn 50.
        4. (2 điểm) Nhập số nguyên x và k. Thêm phần tử x vào vị trí thứ k trong mảng.
        5. (1 điểm) Ghi vào tệp “D:/dayso08.txt” các phần tử  âm của dãy.
        6. (1 điểm) Viết hàm kiểm tra dãy số sau khi chèn thêm phần tử x có phải là dãy đối xứng không?
    Chương trình chính gọi thực hiện và hiển thịcác kết quả thực thi các hàm trên.
*/

#include <stdio.h>
#include <stdlib.h>

int* read_array(int n)
{
    int* array = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        printf("[%d]: ", i);scanf("%d", &array[i]);
    }
    return array;
}

void print_array(FILE* stream, int* arr, const int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i != size - 1) printf(",");
    }
    printf("]\n");
}

void print_cau3(int* arr, const int size)
{
    printf("Cac phan tu chia het cho 3 va nho hon 50:\n");
    for (int i = 0; i < size; i++)
    {
        if (arr[i]%3 == 0 && arr[i] < 50)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void add(int** arr, int* size)
{
    (*size)++;
    int x, k;
    *arr = reallocarray(*arr, *size, sizeof(int));

    printf("Nhap x: "); scanf("%d", &x);
    do {
        printf("Nhap k (0 <= k < %d): ", *size); scanf("%d", &k);
    } while (k >= *size || k < 0);

    for (int i = *size - 1; i > k; i--)
    {
        (*arr)[i] = (*arr)[i - 1]; 
    }
    (*arr)[k] = x;
}

void ghi_file(int* arr, const int size)
{
    FILE* fp = fopen("dayso08.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Khong the mo file");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            fprintf(fp, "%d ", arr[i]);
        }
    }

    fclose(fp); 
}

void check_doixung(int* arr, const int size)
{
    int mid = size / 2;
    for (int i = 0; i < mid; i++)
    {
        /* printf("%d-%d\n", arr[i], arr[size-i-1]); */
        if (arr[i] != arr[size - i - 1])
        {
            printf("Mang khong doi xung\n");
            return;
        }
    }
    printf("Mang doi xung\n");
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);

    int* arr = read_array(n);
    printf("Mang vua nhap la:\n");
    print_array(stdout, arr, n);
    print_cau3(arr, n);
    add(&arr, &n);
    print_array(stdout, arr, n);
    ghi_file(arr, n);
    check_doixung(arr, n);

    return 0;
}
