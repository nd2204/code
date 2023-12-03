/*
    Sử dụng ngôn ngữ lập trình C, viết chương trình dưới dạng hàm thực hiện các chức năng sau:
    1. (2 điểm) Nhập ma trận vuông gồm nxn phần tử có kiểu nguyên vào bộ nhớ động.
    2. (2 điểm) Hiển thị ma trận vừa nhập ra màn hình theo dạng bảng.
    3. (2 điểm) Tính tổng các phần tử nằm trên đường chéo  chính của ma trận.
    4. (2 điểm) Nhập h từ bàn phím. Tính tổng các phần tử trên cột h vừa nhập.
    5. (1 điểm) Ghi vào tệp D:/matran09.txt các phần tử chẵn của ma trận.
    6. (1 điểm) Viết hàm tạo ra một ma trận chuyển vị từ ma trận đã nhập
    Chương trình chính gọi thực hiện và hiển thị các kết quả thực thi các hàm trên.
*/
#include <stdio.h>
#include <stdlib.h>

int** read_matran(const int row, const int col)
{
    int** p = (int**) malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        p[i] = (int*) malloc(col * sizeof(int));
        for (int j = 0; j < col; j++)
        {
            printf("[%d][%d]: ", i, j); scanf("%d", &p[i][j]);
        }
    }
    return p;
}

void print_matran(int** matrix, const int row, const int col)
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

void free_matrix(void** matrix, const int row)
{
    for (int i = 0; i < row; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void print_tongcheo(int** matrix, const int row)
{
    int tong = matrix[0][0];
    for (int i = 1; i < row; i++)
    {
        tong += matrix[i][i];
    }
    printf("Tong duong cheo chinh: %d\n", tong);
}

void print_tongcoth(int** matrix, const int row, const int col)
{
    size_t h;
    do {
        printf("Nhap h (0->%d): ", col-1); scanf("%ld", &h);
    }
    while (h < 0 || h >= col);

    int tong = matrix[0][h];
    for (int i = 1; i < row; i++)
    {
        tong += matrix[i][h];
    }
    printf("Tong cot %ld: %d\n", h, tong);
}

void ghi_file(int** matrix, const int row, const int col)
{
    FILE* fp = fopen("matran09.txt", "w");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] %2 == 0)
            {
                fprintf(fp, "%d ", matrix[i][j]);
            }
        }
    }
    fclose(fp);
}

void chuyenvi(int*** matrix, int* row, int* col)
{
    int temp = *row; *row = *col; *col = temp;
    int** new = malloc(*row * sizeof(int*));
    for (int i = 0; i < *row; i++)
    {
        new[i] = malloc(*col * sizeof(int));
        for (int j = 0; j < *col; j++)
        {
            new[i][j] = (*matrix)[j][i];
        }
    }
    free_matrix((void**) *matrix, *col);
    *matrix = new;
}

int main()
{
    int n, m = 3;
    printf("Nhap n: "); scanf("%d", &n);

    int** p = read_matran(n, m);
    print_matran(p, n, m);
    /* print_tongcheo(p, n); */
    print_tongcoth(p, n, m);
    ghi_file(p, n, m);
    chuyenvi(&p, &n, &m);
    printf("Ma tran sau khi chuyen vi la:\n");
    print_matran(p, n, m);

    free_matrix((void**) p, n);
    return 0;
}
