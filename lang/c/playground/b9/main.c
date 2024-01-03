/*
    Bài tập
    Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng sau:
        1) (2 điểm) Viết hàm nhập ma trận gồm m hàng và n cột các phần tử thực vào bộ nhớ động.
        2) (2 điểm) Viết hàm hiển thị ma trận theo dạng bảng.
        3) (2 điểm) Viết hàm (dạng hàm có giá trị trả về) tính tổng các phần tử của ma trận.
        4) (2 điểm) Viết hàm tìm, hiển thị giá trị lớn nhất trên hàng 0 của ma trận.
        5) (1 điểm) Viết hàm ghi vào tệp D:/matran03.txt các phần tử trong ma trận dạng bảng.
        6) (1 điểm) Viết hàm kiểm tra ma trận có phải là ma trận đơn vị (ma trận đơn vị là ma trận vuông có các phần tử thuộc đường chéo chính =1 và các phần tử ngoài đường chéo chính =0) hay không?
    Chương trình chính gọi thực hiện và hiển thị các kết quả thực thi các hàm trên.
*/

#include <stdio.h>
#include <stdlib.h>

float** read_matrix(const int row, const int col)
{
    float** p = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        p[i] = malloc(col * sizeof(int));
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j); scanf("%f", &p[i][j]);
        }
    }
    return p;
}

void print_matrix(FILE* stream, float** matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fprintf(stream, "%8.2f", matrix[i][j]);
        }
        fprintf(stream, "\n");
    }
}

void free_matrix(float** matrix, const int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

float sum(float** matrix, const int row, const int col)
{
    float sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

void print_cau4(float** matrix, const int row, const int col)
{
    float best = matrix[0][0];
    for (int i = 0; i < col; i++)
    {
        best = (best < matrix[0][i]) ? matrix[0][i] : best;
    }
    printf("Phan tu lon nhat hang 0: %.2f\n", best);
}

void ghi_file(float** matrix, const int row, const int col)
{
    FILE* fp = fopen("matran03.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Khong the mo file");
        return;
    }
    print_matrix(fp, matrix, row, col);
    printf("Da ghi vao file matran03.txt\n");
    fclose(fp);
}

void check_matrandonvi(float** matrix, const int row, const int col)
{
    if (row != col || row == 1 && col == 1)
    {
        printf("Khong phai la ma tran vuong");
        return;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][i] != 1 || i != j && matrix[i][j] != 0)
            {
                printf("Khong phai la ma tran don vi\n");
                return;
            }
        }
    }
    printf("La ma tran don vi\n");
}

int main()
{
    int m, n;
    printf("hang: "); scanf("%d", &m);
    printf("cot: "); scanf("%d", &n);

    float** mat = read_matrix(m, n);
    printf("Ma tran vua nhap la:\n");
    print_matrix(stdout, mat, m, n);
    printf("Tong cac phan tu: %.2f\n", sum(mat, m, n));
    print_cau4(mat, m, n);
    ghi_file(mat, m, n);
    check_matrandonvi(mat, m, n);

    free_matrix(mat, m);
    return 0;
}
