#include <iostream>
#include "defines.h"

using std::cin, std::cout, std::getline;

enum hanh_kiem {
    HANH_KIEM_UNKNOWN,
    HANH_KIEM_YEU,
    HANH_KIEM_TRUNG_BINH,
    HANH_KIEM_KHA,
    HANH_KIEM_TOT,
    HANH_KIEM_MAX
};

const char* hanh_kiem_str[HANH_KIEM_MAX] = {
    "",
    "Yeu",
    "Trung Binh",
    "Kha",
    "Tot",
};

struct SinhVien {
public:
    std::string ten;
    std::string lop;
    f32 diem;
    i32 masv;
    enum hanh_kiem hanh_kiem;

    void nhap() {
        i32 hk;
        cout << "Nhap masv: "; cin >> masv;
        cout << "Nhap ten sv: "; getline(cin >> std::ws, ten);
        cout << "Nhap lop: "; getline(cin,  lop);
        cout << "Nhap diem: "; cin >> diem;
        cout << "Nhap hanh kiem (1: Yeu, 2: Trung Binh, 3: Kha, 4: Tot): "; cin >> hk;
        hanh_kiem = static_cast<enum hanh_kiem>(hk);
    }

    void xuat() {
        printf("%d\t%s\t%s\t%f\t%s",
               masv, ten.c_str(), lop.c_str(), diem, hanh_kiem_str[hanh_kiem]);
    }
};

// Cai dat danh sach node;
template<typename T>
struct Node {
    T data;
    Node* next;

    static Node* create_node(T &data)
    {
        Node* p = (Node*) malloc(sizeof(Node));
        p->data = data;
        p->next = NULL;
        return p;
    }
};


// Cai dat danh sach lien ket don;
template<typename T>
class List {
public:
    Node<T> *head, *tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    b8 isEmpty() {
        return !(head || tail);
    }

    void insertHead(T &data) {
        Node<T>* p =  Node<T>::create_node(data);
        if (isEmpty()) {
            head = tail = p;
        } else {
            p->next = head;
            head = p;
        }
    }

    void insertTail(T &data) {
        Node<T>* p = Node<T>::create_node(data);
        if (isEmpty()) {
            head = tail = p;
        } else {
            tail->next = p;
            tail = p;
        }
    }

    void insertAfter(b8 (*compare)(const T&, const T&), T &data) {
        for (Node<T>* p = head; p != NULL; p = p->next)
        {
            if (compare(p->data, data))
            {
                if (p == tail) {
                    insertTail(data);
                } else {
                    Node<T>* ptr = Node<T>::create_node(data);
                    ptr->next = p->next;
                    p->next = ptr;
                }
            }
        }
    }

    void insertBefore(b8 (*compare)(const T&, const T&), T &data) {
        for (Node<T>* p = head; p != tail; p = p->next)
        {
            if (compare(p->next->data, data))
            {
                if (p == head) {
                    insertHead(data);
                } else {
                    Node<T>* ptr = Node<T>::create_node(data);
                    ptr->next = p->next;
                    p->next = ptr;
                }
            }
        }
    }
};

int main (int argc, char *argv[]) {
    SinhVien sv;
    sv.nhap();
    sv.xuat();
    List<SinhVien> L;
    return 0;
}
