/*
    Sử dụng ngôn ngữ lập trình C, viết chương trình như sau:
    Định nghĩa cấu trúc nhân viên bao gồm các thông tin:
    - mã nhân viên  (kiểu xâu kí tự)
    - họ tên        (kiểu xâu kí tự)
    - năm sinh      (kiểu số)
    - lương         (kiểu số).
    Xây dựng các hàm thực hiện các chức năng sau:
    1. Đọc một danh sách gồm n nhân viên từ một file vào bộ nhớ động.
    2. Hiển thị danh sách gồm n nhân viên ra màn hình. Mỗi nhân viên trên một dòng.
    3. Hiển thị thông tin của các nhân viên có lương cao nhất.
    4. In ra màn hình thông tin nhân viên có mã NV0120 nếu không có thì đưa ra thông báo là không có nhân viên nào.
    5. Ghi vào file trocap.txt thông tin nhân viên có lương nhỏ hơn 500. Thông tin mỗi nhân viên trên một dòng
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nhanvien {
    char manv[64];
    char hoten[256];
    int namsinh;
    int luong;
} nhanvien;

nhanvien* read_nhanvien(FILE* fp, size_t n)
{
    size_t len = 0;
    int c;
    while((c = fgetc(fp)) != EOF)
    {
        if (c == '\n') len++;
    }
    rewind(fp);

    if (n > len)
    {
        fprintf(stderr, "%ld larger than file max line (%ld)\n", n, len);
        return NULL;
    }

    nhanvien* p = malloc(n * sizeof(nhanvien));
    int stat = 0;
    for (int i = 0; i < n; i++)
    {
        stat = fscanf(
            fp,
            "%s %s %d %d",
            p[i].manv, p[i].hoten, &p[i].namsinh, &p[i].luong
        );
    }
    if (stat != 4)
    {
        fprintf(stderr, "%d\n", stat);
        return NULL;
    }

    return p;
}

int print_nhanvien(FILE* stream, nhanvien* p, size_t n)
{
    int stat = 0;
    for (int i = 0; i < n; i++)
    {
        stat = fprintf(
            stream,
            "%s %s %d %d\n",
            p[i].manv, p[i].hoten, p[i].namsinh, p[i].luong
        );
    }
    return stat;
}

void print_max(nhanvien* p, size_t n)
{
    int best = p->luong;
    for (int i = 1; i < n; i++)
    {
        if (best < p[i].luong) best = p[i].luong;
    }

    printf("\nNhan vien co luong cao nhat la:\n");
    for (int i = 0; i < n; i++)
    {
        if (best == p[i].luong)
            print_nhanvien(stdout, p+i, 1);
    }
}

void ghi_file(nhanvien* p, size_t n)
{
    FILE* fp = fopen("trocap.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (p[i].luong < 500)
        {
            print_nhanvien(fp, p+i, 1);
        }
    }
    fclose(fp);
}

int main()
{
    int stat = 1;
    size_t n;
    printf("Nhap n: ");
    stat = scanf("%ld", &n);

    FILE* fp = fopen("dsnv.txt", "r");
    nhanvien* p = read_nhanvien(fp, n);
    if (p == NULL)
    {
        fprintf(stderr, "Malloc failed\n");
        return stat;
    }

    stat <<= print_nhanvien(stdout, p, n);

    print_max(p, n);

    printf("\nThong tin nhan vien co manv NV0120 la:\n");
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        /* printf("%d", strcmp(p[i].manv, "NV0120")); */
        if (strcmp(p[i].manv, "NV0120") == 0)
        {
            count++;
            print_nhanvien(stdout, p+i, 1);
        }
    }
    if (!count) printf("Khong co nhan vien nao co ma NV0120");

    ghi_file(p, n);

    free(p);
    fclose(fp);

    stat >>= 1;
    return stat;
}
