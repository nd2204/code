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
    "YEU",
    "TRUNG_BINH",
    "KHA",
    "TOT",
};

struct SinhVien {
public:
    std::string ten;
    std::string lop;
    f32 diem;
    i32 masv;
    hanh_kiem hanh_kiem;

    void nhap() {
        i32 hk;
        cout << "Nhap ten sv: "; getline(cin >> std::ws, ten);
        cout << "Nhap lop: "; cin >> lop;
        cout << "Nhap diem: "; cin >> diem;
        cout << "Nhap masv: "; cin >> masv;
        cout << "Nhap hanh kiem (1: Yeu, 2: Trung Binh, 3: Kha, 4: Tot): "; cin >> hk;
        hanh_kiem = static_cast<enum hanh_kiem>(hk);
    }

    void xuat() {
        cout << "Ten sv: " << ten << '\n';
        cout << "Lop: " << lop << '\n';
        cout << "Diem tong ket: " << diem << '\n';
        cout << "Masv: " << masv << '\n';
        cout << "Hanh kiem: " << hanh_kiem_str[hanh_kiem] << '\n';
    }
};

template<typename T>
struct Node {
    T data;
    Node* next;
};

template<typename T>
class List {
public:
    Node<T> *head, *tail;
    
};

int main (int argc, char *argv[]) {
    SinhVien sv;
    sv.nhap();
    sv.xuat();
    List<SinhVien> L;
    return 0;
}
