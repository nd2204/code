/*
    Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng sau:
    Định nghĩa cấu trúc học viên bao gồm các thông tin:
        - mã học viên   (kiểu xâu kí tự)
        - họ tên        (kiểu xâu kí tự)
        - điểm toán     (kiểu số thực)
        - điểm tin      (kiểu số thực)
    Xây dựng các hàm thực hiện các chức năng sau:
    1. Đọc một danh sách gồm n học viên từ file vào bộ nhớ động.
    2. Hiển thị danh sách gồm n học viên ra màn hình cùng với tổng điểm, cho biết
    tổng điểm = điểm toán + điểm tin. Mỗi thí sinh trên một dòng.
    3. Đếm số học viên có tổng điểm = 20 
    4. Đưa ra màn hình thông tin của các sinh viên có tổng điểm lớn nhất.
    5. Ghi vào file “D:/hocvien.txt” thông tin của danh sách học viên có tổng điểm > 15.
    Thông tin mỗi thí sinh trên một dòng.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char mahv[64];
    char hoten[256];
    float diemtoan;
    float diemtin;
} hocvien;

hocvien* read_hocvien(FILE* file, size_t n) {
    if (file == NULL)
    {
        fprintf(stderr, "Couldn't open file");
        return NULL;
    }

    int c;
    size_t len = 0;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') len++;
    }
    rewind(file);

    if (n > len) {
        fprintf(stderr, "%ld is bigger than file's max_length (%ld)", n, len);
        return NULL;
    }

    hocvien* p = malloc(n * sizeof(hocvien));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s", p[i].mahv);
        fscanf(file, "%s", p[i].hoten);
        fscanf(file, "%f", &p[i].diemtoan);
        fscanf(file, "%f", &p[i].diemtin);
    }

    return p;
}

void print_hocvien(FILE* stream, hocvien* p, size_t n) {
    for (int i = 0; i < n; i++) {
        fprintf(
            stream,
            "%s %s %.2f %.2f",
            p[i].mahv, p[i].hoten, p[i].diemtoan, p[i].diemtin
        );
        if (n > 1) fprintf(stream, "\n");
    }
}

void print_tongdiem(hocvien* p, size_t n) {
    float tong;
    printf("\nTong diem:\n");
    for (int i = 0; i < n; i++) {
        tong = p[i].diemtoan + p[i].diemtin;
        print_hocvien(stdout, p+i, 1);
        printf(" %.2f\n", tong);
    }
}

void count_hocvien(hocvien* p, size_t n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if ( p[i].diemtoan + p[i].diemtin == 20.0f )
        {
            counter++;
        }
    }
    printf("\nSo hoc vien co diem = 20: %d\n", counter);
}

void print_max(hocvien* p, size_t n) {
    float best = 0;
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong = p[i].diemtoan + p[i].diemtin;
        if (best < tong) best = tong;
    }

    printf("\nSinh vien co diem cao nhat:\n");
    for (int i = 0; i < n; i++) {
        tong = p[i].diemtoan + p[i].diemtin;
        if (best == tong) {
            print_hocvien(stdout, p+i, 1);
            printf("\n");
        }
    }
}

void ghi_file(hocvien* p, size_t n) {
    int tong = 0;
    FILE* fp = fopen("hocvien.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Khong the mo file");
        return;
    }
    for (int i = 0; i < n; i++) {
        tong = p[i].diemtoan + p[i].diemtin;
        if (tong > 15) {
            print_hocvien(fp, p+i, 1);
            fprintf(fp, "\n");
        }
    }
    printf("\nDa ghi vao file hocvien.txt\n");
    fclose(fp);
}

int main() {
    size_t n;
    printf("Nhap n: "); scanf("%ld", &n);

    FILE* fp = fopen("dshv.txt", "r");

    if (fp == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    hocvien* dshv = read_hocvien(fp, n);
    print_hocvien(stdout, dshv, n);
    print_tongdiem(dshv, n);
    count_hocvien(dshv, n);
    print_max(dshv, n);
    ghi_file(dshv, n);

    fclose(fp);
    free(dshv);
    return 0;
}
