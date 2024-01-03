/*
    Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng sau:
        1. (2 điểm) Viết hàm nhập ma trận gồm m hàng và n cột kiểu nguyên vào bộ nhớ động.
        2. (2 điểm) Viết hàm hiển thị ma trận vừa nhập ra màn hình theo dạng bảng.
        3. (2 điểm) Viết hàm (dạng hàm có giá trị trả về) tính trung bình cộng các phần tử lẻ của ma trận.
        4. (2 điểm) Viết hàm tìm, hiển thị giá trị lớn nhất trên cột 0 của ma trận.
        5. (1 điểm) Viết hàm ghi vào tệp D:/matrannguyen06.txt các phần tử trong ma trận mà có giá trị nhỏ hơn 100.
        6. (1 điểm) Viết hàm kiểm tra một ma trận số nguyên có phải là ma trận đối xứng (ma trận đối xứng là ma trận vuông có phần tử ở hàng i cột j bằng phần tử hàng j cột i) hay không?
    Chương trình chính gọi thực hiện và hiển thị các kết quả thực thi các hàm trên.
*/

#include <stdio.h>
#include <stdlib.h>

void free_matrix(int** matrix, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int** read_matrix(const int row, const int col)
{
    int** p = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        p[i] = malloc(col * sizeof(int)); 
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j); scanf("%d", &p[i][j]);
        }
    }
    return p;
}

void print_matrix(int** matrix, const int row, const int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }
}

float avg(int** matrix, const int row, const int col)
{
    int total = 0, count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j]%2 != 0)
            {
                count++;
                total+=matrix[i][j];
            }
        }
    }
    if (count != 0) return (float) total / count;
    else return 0;
}

void print_cau4(int** matrix, const int row, const int col)
{
    int best = matrix[0][0];
    for (int i = 1; i < row; i++)
    {
        best = best < matrix[i][0] ? matrix[i][0] : best;
    }
    printf("Gia tri lon nhat cot 0 la: %d\n", best);
}

void ghi_file(int** matrix, const int row, const int col)
{
    FILE* fp = fopen("matrannguyen06.txt", "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Loi mo file"); return;
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] < 100)
            {
                fprintf(fp, "%d ", matrix[i][j]);
            }
        }
    }
    fclose(fp);
    printf("Da ghi vao file matrannguyen06.txt\n");
}

void check_doixung(int** matrix, const int row, const int col)
{
    if (row != col || row == 1 && col == 1)
    {
        printf("Khong phai la ma tran vuong\n");
        return;
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                printf("Khong doi xung\n");
                return;
            }
        }
    }
    printf("Doi xung\n");
}

int main()
{
    int m, n;
    printf("hang: "); scanf("%d", &m);
    printf("cot: "); scanf("%d", &n);

    int** mat = read_matrix(m, n);
    print_matrix(mat, m, n); 
    printf("tbc cac phan tu le trong ma tran: %.2f\n", avg(mat, m, n));
    print_cau4(mat, m, n);
    ghi_file(mat, m, n);
    check_doixung(mat, m, n);

    free_matrix(mat, m);
    return 0;
}
