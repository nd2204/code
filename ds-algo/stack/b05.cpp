/*
B05: Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:

Khai báo cấu trúc date gồm các thông tin: ngày, tháng, năm.
```cpp
struct date {
    int ngay, thang, nam;
};
```
Khai báo cấu trúc loại hàng hóa bao gồm các thông tin:
Mã hàng hóa, tên hàng hóa, ngày xuất hàng (kiểu ngày/tháng/năm), ví dụ 10/10/2000), giá xuất hàng đi (đơn vị triệu đồng):
```
struct hang {
    char ID[6];
    char ten[256];
    date ngay_xuat;
    float gia_xuat;
};
```
---
*/

#include <stdio.h>
#include <string.h>

void my_getline(char *name, size_t size) {
    if (name) {
        fgets(name, size, stdin);
        int len;
        name[(len = strcspn(name, "\n"))] = '\0';
        if (len >= size - 1) {
            while (getchar() != '\n');
        }
    }
}

struct date {
    int ngay, thang, nam;
};

struct hang {
    date ngay_xuat;
    float gia_xuat;
    char ten[256];
    char ID[6]; // 5 char for id 1 char for \0
};

void get_date_from_input(date *d) {
    printf("Nhap ngay: "); scanf("%d", &d->ngay);
    printf("Nhap thang: "); scanf("%d", &d->thang);
    printf("Nhap nam: "); scanf("%d", &d->nam);
}

// 1. (2 điểm): Viết các hàm nhập vào từ bàn phím giá trị
//     của một biến cấu trúc hàng hóa, hiển thị lên màn hình.

void nhap(hang &h) {
    printf("--------------------------------------\n");
    printf("Nhap ma hang: "); my_getline(h.ID, 6);
    printf("Nhap ten hang: "); my_getline(h.ten, 256);
    get_date_from_input(&h.ngay_xuat);
    printf("Nhap gia xuat: "); scanf("%f", &h.gia_xuat);
}

void xuat(const hang &h) {
    printf(
        "%s\t%s\t%02d/%02d/%04d\t%.2f\n",
        h.ID,
        h.ten,
        h.ngay_xuat.ngay, h.ngay_xuat.thang, h.ngay_xuat.nam,
        h.gia_xuat
    );
}

#define STACK_MAX_SIZE 256
typedef hang NodeData;

struct Stack {
    int top = -1;
    NodeData nodes[STACK_MAX_SIZE];
};

bool isEmpty(const Stack &s) {
    return s.top < 0;
}

bool isFull(const Stack &s) {
    return s.top == STACK_MAX_SIZE;
}

void push(Stack &s, const NodeData &data) {
    if (isFull(s)) {
        printf("Stack is full!");
        return;
    }
    s.nodes[++(s.top)] = data;
}

NodeData pop(Stack &s) {
    if (!isEmpty(s)) {
        return s.nodes[(s.top)--];
    }
    printf("Stack is empty!");
    return {};
}

void traverse_stack(Stack s_copy) {
    printf("=========================================\n");
    printf("Ma_Hang Ten_Hang NSX Gia_SX\n");
    printf("=========================================\n");
    while (!isEmpty(s_copy)) {
        xuat(pop(s_copy));
    }
}

// 3. (3 điểm): Hiển thị lên màn hình thông tin các hàng hóa trong
//    chồng hàng có giá xuất hàng (trường gia_xuat) > 1.0.
void b3(Stack s) {
    NodeData hang;
    printf("\nThong tin cac hang hoa co gia xuat > 1.0\n");
    printf("=========================================\n");
    printf("Ma_Hang Ten_Hang NSX Gia_SX\n");
    printf("=========================================\n");
    while(!isEmpty(s)) {
        hang = pop(s);
        if (hang.gia_xuat > 1.0f) {
            xuat(hang);
        }
    }
}

// 4. (1 điểm):
//     Xuất kho chồng hàng hóa cần ghi lại thông tin hàng hóa mỗi khi xuất hàng cho
//     đến hết hàng vào một file text là hanghoa.txt theo cách ghi như sau (1đ):
//     Giá trị các phần của chồng hàng theo từng dòng (mỗi hàng hóa 1 dòng, mỗi giá
//     trị trường cấu trúc hàng hóa cách nhau 1 dấu tab, tức kí tự ‘\t’) Ví dụ :
//     ```
//     001 TV1 10/09/2019 20
//     002 TV2 10/09/2019 6
//     ```
void b4(Stack s) {
    FILE *fp = fopen("hanghoa.txt", "wt");
    if (!fp) {
        printf("Khong the mo file");
        return;
    }
    NodeData hang;
    while (!isEmpty(s)) {
        hang = pop(s);
        fprintf(
            fp,
            "%s\t%s\t%02d/%02d/%04d\t%.0f\n",
            hang.ID, hang.ten,
            hang.ngay_xuat.ngay, hang.ngay_xuat.thang, hang.ngay_xuat.nam,
            hang.gia_xuat
        );
    }
    printf("\nDa luu vao file hanghoa.txt\n");
}

int main() {
    // 2. (4 điểm): Nhập vào một số nguyên dương n,
    //     sử dụng cấu trúc dữ liệu ngăn xếp (stack)
    //     nhập vào một chồng hàng gồm n hàng hóa.
    int N = 0;
    do {
        printf("Nhap N: ");
        scanf("%d", &N);
    } while (N <= 0);

    Stack products;
    hang p;
    for (int i = 0; i < N; ++i) {
        while ('\n' != getchar());
        printf("[%d/%d]", i+1, N);
        nhap(p);
        push(products, p);
    }
    printf("\nHang vua nhap la:\n");
    traverse_stack(products);

    b3(products);
    b4(products);
}
