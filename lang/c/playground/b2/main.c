/*
    Định nghĩa cấu trúc sinh viên gồm các thông tin sau:
        - mã sinh viên      (kiểu xâu ký tự),
        - họ tên sinh viên  (kiểu xâu ký tự),
        - năm sinh          (kiểu số),
        - điểm tổng kết     (kiểu số thực).
    Xây dựng các hàm thực hiện các chức năng sau:
    1. Đọc thông tin của n sinh viên từ file vào bộ nhớ động.
    2. Hiển thị thông tin danh sách n sinh viên ra màn hình. Mỗi sinh viên trên một dòng.
    3. Sắp xếp danh sách sinh viên theo điểm tổng kết giảm dần.
    4. Đếm số sinh viên có năm sinh 2000 nếu không có thì đưa ra thông báo không có sinh viên nào.
    5. Ghi vào file D:/dulieu.txt thông tin những sinh viên có điểm tổng kết nhỏ hơn
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char masv[64];
    char hoten[256];
    int namsinh;
    float diem;
} sinhvien;

sinhvien* read_sinhvien(FILE* fp, size_t n)
{
    int c;
    size_t len = 0;
    while((c = fgetc(fp)) != EOF)
    {
        if (c == '\n') len++;
    }
    rewind(fp);

    if (n > len) {
        fprintf(stderr, "%ld is bigger than file max line %ld\n", n, len);
        return NULL;
    }

    sinhvien* p = malloc(n * sizeof(sinhvien));
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s", p[i].masv);
        fscanf(fp, "%s", p[i].hoten);
        fscanf(fp, "%d", &p[i].namsinh);
        fscanf(fp, "%f", &p[i].diem);
    }
    return p;
}

void fchecknull(FILE* fp, char* fname) {
    if (fp == NULL)
    {
        fprintf(stderr, "Couldn't open file %s\n", fname);
        exit(1);
    }
}

void print_sinhvien(FILE* stream, sinhvien* p, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(
            stream,
            "%s %s %d %.2f\n",
            p[i].masv, p[i].hoten, p[i].namsinh, p[i].diem
        );
    }
}

void count_sinhvien(sinhvien* p, size_t n)
{
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[i].namsinh == 2000) counter++;
    }
    if (counter)
        printf("so sinh vien co nam sinh 2000: %d", counter);
    else
        printf("khong co sinh vien nao co nam sinh 2000");

    return;
}

void sort(sinhvien* p, size_t n)
{
    sinhvien temp;
    int swapped = 0;
    for (int i = 0; i < n; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].diem < p[j+1].diem)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void ghi_file(sinhvien* p, size_t n)
{
    FILE* fp = fopen("dulieu.txt", "w");
    fchecknull(fp, "dulieu.txt");
    for (int i = 0; i < n; i++)
    {
        if (p[i].diem < 10)
            print_sinhvien(fp, p+i, 1);
    }
    fclose(fp);
}

int main(void)
{
    size_t n;
    printf("Nhap n: "); scanf("%ld", &n);

    FILE* fp = fopen("dssv.txt", "r");
    fchecknull(fp, "dssv.txt");

    sinhvien* p = read_sinhvien(fp, n);
    if (p == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        return EXIT_FAILURE;
    }

    print_sinhvien(stdout, p, n);
    sort(p, n);
    printf("\n");
    print_sinhvien(stdout, p, n);
    count_sinhvien(p, n);
    ghi_file(p, n);

    free(p);
    fclose(fp);
    return EXIT_SUCCESS;
}
