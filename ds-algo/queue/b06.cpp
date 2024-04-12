/*
B06: Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:

Khai báo cấu trúc date gồm các thông tin: ngày, tháng, năm.
```cpp
struct date {
    int ngay, thang, nam;
};
```
Khai báo cấu trúc hàng hóa cần bốc xếp trên băng chuyền bao gồm các thông tin:
Mã hàng hóa, tên hàng hóa, ngày xuất hàng, giá xuất hàng đi (đơn vị triệu đồng):
```cpp
struct hang {
    char ID[6];
    char ten[256];
    date ngay_xuat;
    float gia_xuat;
};
```
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
        "%s\t%s\t%02d/%02d/%04d\t%.0f\n",
        h.ID, h.ten,
        h.ngay_xuat.ngay, h.ngay_xuat.thang, h.ngay_xuat.nam,
        h.gia_xuat
    );
}

#define QUEUE_MAX_SIZE 8
typedef hang NodeData;

struct queue {
    unsigned int first, last;
    NodeData nodes[QUEUE_MAX_SIZE];
};

void init(queue &q) {
    q.first = -1;
    q.last = -1;
}

bool isEmpty(const queue &q) {
    return (q.first == -1 || q.last == -1)
        || ((q.last + 1) % QUEUE_MAX_SIZE == q.first);
}

bool isFull(const queue &q) {
    return (q.last + 2) % QUEUE_MAX_SIZE == q.first;
}

void enqueue(queue &q, const NodeData &data) {
    if (isEmpty(q)) q.first = 0;
    if (!isFull(q)) {
        q.last = (q.last + 1) % QUEUE_MAX_SIZE;
        q.nodes[q.last] = data;
        return;
    }
    printf("Queue is full");
}

NodeData dequeue(queue &q) {
    NodeData x;
    if(!isEmpty(q)) {
        x = q.nodes[q.first];
        q.first = (q.first + 1) % QUEUE_MAX_SIZE;
        return x;
    }
    printf("Queue is empty");
    return {};
}

void traverse_queue(queue q) {
    printf("=========================================\n");
    printf("Ma_Hang Ten_Hang NSX Gia_SX\n");
    printf("=========================================\n");
    while (!isEmpty(q)) {
        xuat(dequeue(q));
    }
}

// 3. (2 điểm): Hiển thị lên màn hình thông tin tất cả các
//      hàng hóa trong hàng đợi có mã hàng hóa (trường ID) là “001”.

void b3(queue q) {
    printf("\nThong tin cac hang hoa co id = \"001\"\n");
    printf("=========================================\n");
    printf("Ma_Hang Ten_Hang NSX Gia_SX\n");
    printf("=========================================\n");
    NodeData hang;
    while(!isEmpty(q)) {
        hang = dequeue(q);
        if (strcmp(hang.ID, "001") == 0) {
            xuat(hang);
        }
    }
}



int main() {
    // 2. (4 điểm): Nhập vào 1 số nguyên dương n,
    //      sử dụng cấu trúc dữ liệu hàng đợi (queue)
    //      nhập vào băng chuyền gồm n hàng hóa cần bốc xếp.
    int N = 0;
    do {
        printf("Nhap N: ");
        scanf("%d", &N);
    } while (N <= 0);

    queue products;
    init(products);
    hang p;
    for (int i = 0; i < N; ++i) {
        while ('\n' != getchar());
        printf("[%d/%d]", i+1, N);
        nhap(p);
        enqueue(products, p);
    }

    printf("\nHang vua nhap la:\n");
    traverse_queue(products);

    b3(products);
    // 4. (2 điểm): Hiển thị lên màn hình thông tin hàng hóa đã bốc xếp
    //      (hiện tại băng chuyền đã rỗng).
    printf("\nThong tin hang hoa da boc xep la:\n");
    traverse_queue(products);
}
