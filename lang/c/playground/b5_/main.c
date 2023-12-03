/*
    Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng sau:
    Định nghĩa cấu trúc máy tính bao gồm các thông tin:
    - mã máy,
    - tên máy,
    - năm sản xuất,
    - hãng sản xuất,
    - giá nhập.
    Viết các hàm thực hiện các chức năng sau:
    1. (2 điểm) Viết hàm nhập từ bàn phím danh sách thông tin của n máy tính vào bộ nhớ động.
    2. (2 điểm) Viết hàm hiển thị danh sách máy tính ra màn hình. Mỗi máy tính trên một dòng.
    3. (2 điểm) Viết hàm hiển thị danh sách các máy tính của nhà sản xuất SAMSUNG.
    4. (2 điểm) Viết hàm hiển thị danh sách các máy tính có năm sản xuất 2019.
    5. (1 điểm) Ghi vào tệp “D:/maytinh04.txt” thông tin máy tính có giá nhập >2000. Thông tin mỗi máy tính trên một dòng.
    6. (1 điểm) Viết hàm nhập xóa thông tin của các máy tính có năm sản xuất trước năm 2000.
    Chương trình chính gọi thực hiện và hiển thị các kết quả thực thi các hàm trên.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char mamay[64];
    char tenmay[256];
    char hangsx[256];
    int namsx;
    int gia;
} maytinh;

maytinh* read_maytinh(const int n)
{
    maytinh* p = malloc(n * sizeof(maytinh));
    for (int i = 0; i < n; i++)
    {
        printf("[%d/%d] Nhap thong tin may tinh:\n", i+1, n);
        while(getchar() != '\n');
        printf("\tma may: ");         fgets(p[i].mamay, 64, stdin);
        printf("\tten may: ");        fgets(p[i].tenmay, 256, stdin);
        printf("\thang san xuat: ");  fgets(p[i].hangsx, 256, stdin);
        printf("\tnam san xuat: ");   scanf("%d", &p[i].namsx);
        printf("\tgia nhap: ");       scanf("%d", &p[i].gia);
        p[i].mamay[strcspn(p[i].mamay, "\n")] = '\0';
        p[i].tenmay[strcspn(p[i].tenmay, "\n")] = '\0';
        p[i].hangsx[strcspn(p[i].hangsx, "\n")] = '\0';
        printf("\n");
    }
    return p;
}

void print_maytinh(FILE* stream, maytinh* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(
            stream,
            "%s %s %s %d %d\n",
            p[i].mamay, p[i].tenmay, p[i].hangsx, p[i].namsx, p[i].gia
        );
    }
}

void print_samsung(maytinh* p, int n)
{
    int count = 0;
    printf("\nMay tinh co hangsx la SAMSUNG la:\n");
    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].hangsx, "SAMSUNG") == 0)
        {
            count++;
            print_maytinh(stdout, p+i, 1);
        }
    }
    if (!count)
    {
        printf("Khong co thong tin cho may tinh co hangsx = SAMSUNG\n");
    }
}

void print_2019(maytinh* p, int n)
{
    int count = 0;
    printf("\nMay tinh co namsx 2019 la:\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i].namsx == 2019)
        {
            count++;
            print_maytinh(stdout, p+i, 1);
        }
    }
    if (!count)
    {
        printf("Khong co thong tin cho may tinh co namsx = 2019\n");
    }
}

void ghi_file(maytinh* p, int n)
{
    FILE* fp = fopen("maytinh04.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Khong the mo file");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (p[i].gia > 2000)
        {
            print_maytinh(fp, p+i, 1);
        }
    }

    fclose(fp);
}

void delete_maytinh(maytinh** p, int* n)
{
    int count = 0;
    for (int i = 0; i < *n - count; i++)
    {
        if ((*p)[i].namsx < 2000)
        {
            for (int j = i; j < *n - count - 1; j++)
            {
                (*p)[j] = (*p)[j+1];
            }
            ++count;
            --i;
        }
    }
    *n -= count;
    *p = (maytinh*) realloc(*p, sizeof(maytinh) * (*n));
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);

    maytinh* p = read_maytinh(n);
    if (p == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return -1;
    }
    printf("Danh sach vua nhap:\n");
    print_maytinh(stdout, p, n);

    print_samsung(p, n);
    print_2019(p, n);

    ghi_file(p, n);

    delete_maytinh(&p, &n);
    printf("Danh sach sau khi xoa cac may tinh co nam < 2000:\n");
    print_maytinh(stdout, p, n);
    return 0;
}
