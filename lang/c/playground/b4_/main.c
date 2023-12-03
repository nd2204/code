/*
Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng sau:
Định nghĩa cấu trúc thí sinh bao gồm các thông tin:
    - mã thí sinh,
    - họ tên thí sinh,
    - điểm toán,
    - điểm anh,
    - điểm văn.
Viết các hàm thực hiện các chức năng sau:
1. (2 điểm) Nhập từ bàn phím danh sách gồm n thí sinh với đầy đủ các thông tin được mô tả như trên vào bộ nhớ động.
2. (2 điểm) Hiển thị danh sách thông tin của n thí sinh ra màn hình cùng với tổng điểm, cho biết tổng điểm = điểm toán + điểm anh + điểm văn. Mỗi thí sinh trên một dòng.
3. (2 điểm) Hiển thị đầy đủ thông tin những thí sinh có điểm toán >=8.
4. (2 điểm) Nhập số thực x từ bàn phím. Đưa ra màn hình danh sách những thí sinh có điểm tổng điểm  bằng điểm x vừa nhập .
5. (1 điểm) Ghi vào tệp “D:/thisinh07.txt” thông tin của danh sách n thí sinh. Thông tin mỗi thí sinh trên một dòng.
6. (1 điểm) Viết hàm nhập thông tin một thí sinh, sau đó bổ sung thí sinh đó vào trong danh sách thí sinh tại vị trí K (K nhập từ bàn phím thỏa mãn 0<=K<n)
Chương trình chính gọi thực hiện và hiển thị các kết quả thực thi các hàm trên.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct thisinh{
    char mats[64];
    char hoten[256];
    int toan;
    int anh;
    int van;
} thisinh;

thisinh* read_thisinh(size_t n)
{
    thisinh* p = malloc(n * sizeof(thisinh));
    for (int i = 0; i < n; i++)
    {
        printf("Nhap thi sinh %d:\n", i + 1);
        while (getchar() != '\n');
        printf("mats: ");       fgets(p[i].mats, 64, stdin);
        p[i].mats[strcspn(p[i].mats,"\n")] = '\0';
        printf("hoten: ");      fgets(p[i].hoten, 256, stdin);
        p[i].hoten[strcspn(p[i].hoten,"\n")] = '\0';

        printf("diem toan: ");  fscanf(stdin, "%d", &p[i].toan);
        printf("diem anh: ");   fscanf(stdin, "%d", &p[i].anh);
        printf("diem van: ");   fscanf(stdin, "%d", &p[i].van);
    }
    return p;
}

void print_thisinh(FILE* stream, thisinh* p, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(
            stream,
            "%s %s %d %d %d",
            p[i].mats, p[i].hoten, p[i].toan, p[i].anh, p[i].van
        );
        if (n != 1) fprintf(stream, "\n");
    }
}

int sum(thisinh p)
{
    return p.toan + p.anh + p.van;
}

void print_tongdiem(thisinh* p, size_t n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong = sum(p[i]);
        print_thisinh(stdout, p+i, 1);
        printf(" %d\n", tong);
    }
}

void print_diemtoan(thisinh* p, size_t n)
{
    printf("Sinh vien co diem toan >= 8:\n");
    for (int i = 0; i < n; i++)
    {
        if (p[i].toan >= 8)
        {
            print_thisinh(stdout, p+i, 1);
            printf("\n");
        }
    }
}

void print_match(thisinh* p, size_t n)
{
    int x;
    printf("Nhap x: "); scanf("%d", &x);
    printf("Sinh vien co tong diem = %d:\n", x);
    for (int i = 0; i < n; i++)
    {
        if (sum(p[i]) == x)
        {
            print_thisinh(stdout, p+i, 1);
            printf("\n");
        }
    }
}

// IMPORTANT
void add_thisinh(thisinh** p, size_t* n)
{
    *n += 1;
    *p = realloc(*p, *n * sizeof(thisinh));
    int k;
    do
    {
        printf("Nhap k (0 <= k < %ld): ", *n - 1); scanf("%d", &k);
    }
    while (k < 0 || k >= *n - 1);

    for (int i = *n - 1; i > k; i--)
    {
        (*p)[i] = (*p)[i-1];
    }
    thisinh* new = read_thisinh(1);
    (*p)[k] = *new;
    free(new);
}

int main()
{
    size_t n;
    printf("Nhap n: "); scanf("%ld", &n);

    thisinh* p = read_thisinh(n);
    print_thisinh(stdout, p, n);

    printf("\nTong diem cua cac thi sinh:\n");
    print_tongdiem(p, n);

    print_diemtoan(p, n);
    print_match(p, n);

    FILE* fp = fopen("thisinh07.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Khong the mo file\n");
        return 1;
    }
    else {
        print_thisinh(fp, p, n);
    }

    add_thisinh(&p, &n);
    print_thisinh(stdout, p, n);

    free(p);
    fclose(fp);
    return 0;
}
