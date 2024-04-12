/*
B04: Trên ngôn ngữ C/C++, viết chương trình thực hiện yêu cầu sau:

1. (1 điểm): Định nghĩa một cấu trúc Học viên bao gồm các trường thông tin như sau:
    Mã học viên (kiểu số nguyên), tên học viên (kiểu chuỗi ký tự), lớp (kiểu chuỗi ký tự),
    chuyên ngành (Khoa học máy tính, Thương mại điện tử, Quản trị an ninh mạng), điểm tổng kết (kiểu số thực).

2 (4 điểm): Cài đặt một cấu trúc danh sách liên kết đơn cho kiểu dữ liệu Học viên, với các thao tác:
    1) Khởi tạo danh sách; 2) Tạo mới một nút chứa dữ liệu; 3) Chèn nút vào cuối danh sách;
    4) Tìm kiếm phần tử trong danh sách; 5) Duyệt danh sách.

3 (5 điểm): Chương trình chính: Sử dụng cấu trúc danh sách liên kết đôi và các thao tác đã tạo để:
    - Nhập và 1 danh sách gồm n Học viên (n bất kỳ).
    - Hiển thị danh sách đã nhập ra màn hình.
    - Liệt kê ra màn hình danh sách tất cả những Học viên thuộc chuyên ngành “Thương mại điện tử” và có điểm tổng kết ≥ 8.0.
    - Sắp xếp danh sách đã nhập theo tên học viên (thứ tự alphabet), hiện thị danh sách đã sắp ra màn hình.
*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct HocVien {
    string ten;
    string lop;
    string chng;
    int id;
    float dtk;
};

typedef HocVien NodeData;

void NodeData_nhap(NodeData &data) {
    cout << "---------------------------------------------------\n";
    cout << "Masv: "; cin >> data.id;
    while (getchar() != '\n');
    cout << "Tensv: "; getline(cin, data.ten);
    cout << "Chuyen nganh: "; getline(cin, data.chng);
    cout << "Lop: "; getline(cin, data.lop);
    cout << "Diem Tong Ket: "; cin >> data.dtk;
}

void NodeData_xuat(const NodeData &data) {
    printf("%d\t%s\t%s\t%s\t%.2f\n",
        data.id,
        data.ten.c_str(),
        data.chng.c_str(),
        data.lop.c_str(),
        data.dtk
    );
}

struct node {
    NodeData data;
    node *next;
};

node* createNode(const NodeData &data) {
    node* p = new node;
    p->data = data;
    p->next = NULL;
    p->next = NULL;
    return p;
}

struct List {
    node *head, *tail;
};

void ListInit(List &L) {
    L.head = L.tail = NULL;
}

bool isEmpty(const List &L) {
    return !(L.head && L.tail);
}

void insertTail(List &L, const NodeData &data) {
    node *p = createNode(data);
    if (isEmpty(L)) {
        L.head = L.tail = p;
    } else {
        L.tail->next = p;
        L.tail = p;
    }
}

List search(const List &L, bool (*condition)(const NodeData& list_elem)) {
    List matches;
    ListInit(matches);
    for (node *p = L.head; p != NULL; p = p->next) {
        if (condition(p->data)) {
            insertTail(matches, p->data);
        }
    }
    return matches;
}

void sort(List &L) {
    NodeData temp;
    for (node *p = L.head; p != L.tail; p = p->next) {
        for (node *q = p->next; q != NULL; q = q->next) {
            if (p->data.ten > q->data.ten) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

void traverse(const List &L) {
    cout << "===================================================\n"
         << "Ma_SV\tHo_Ten\tChuyen_Nganh\tLop\tDTK\n"
         << "===================================================\n";
    for (node *p = L.head; p != NULL; p = p->next) {
        NodeData_xuat(p->data);
    }
}


bool so_sanh_theo_dtk_va_chuyen_nganh(const NodeData &list_elem) {
    return list_elem.chng == "Thuong Mai Dien Tu" && list_elem.dtk >= 8.0f;
}

int main() {
    int N;
    do {
        cout << "Nhap N: "; cin >> N;
    } while (N <= 0);

    List L;
    ListInit(L);
    NodeData hv;
    for (int i = 0; i < N; ++i) {
        NodeData_nhap(hv);
        insertTail(L, hv);
    }
    cout << "\n";
    traverse(L);

    cout << "\nThong tin cua cac sinh vien hoc Thuong Mai Dien Tu va DTK >= 8.0:\n";
    traverse(search(L, so_sanh_theo_dtk_va_chuyen_nganh));

    cout << "\nDanh sach sinh vien sau khi sap xep:\n";
    sort(L);
    traverse(L);
}
