#include <iostream>
#include "utils/defines.h"

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

  void nhap();
  void xuat();
};

void SinhVien::nhap() {
    i32 hk;
    cout << "Nhap masv: "; cin >> this->masv;
    cout << "Nhap ten sv: "; getline(cin >> std::ws, this->ten);
    cout << "Nhap lop: "; getline(cin >> std::ws,  this->lop);
    cout << "Nhap diem: "; cin >> this->diem;
    cout << "Nhap hanh kiem (1: Yeu, 2: Trung Binh, 3: Kha, 4: Tot): "; cin >> hk;
    this->hanh_kiem = static_cast<enum hanh_kiem>(hk % HANH_KIEM_MAX);
}

void SinhVien::xuat() {
    printf("%8d %s\t%s\t%.2f %s\n",
           masv, ten.c_str(), lop.c_str(), diem, hanh_kiem_str[hanh_kiem]);
}

// Cai dat danh sach node;
template<typename T>
struct Node {
  T data;
  Node* next;

  static Node* create_node(T &data);
};

template<typename T>
Node<T>* Node<T>::create_node(T &data) {
  Node* p = (Node*) malloc(sizeof(Node));
  p->data = data;
  p->next = nullptr;
  return p;
}

// Cai dat danh sach lien ket don;
template<typename T>
class List {
public:
  Node<T> *head, *tail;
  List();

  void insertHead(T &data);
  void insertTail(T &data);
  void insertBefore(b8 (*compare)(const T&, const T&), T &data);
  void insertAfter (b8 (*compare)(const T&, const T&), T &data);
  b8 isEmpty();

  void print();
};

template<typename T>
List<T>::List() {
  this->head = nullptr;
  this->tail = nullptr;
}

template<typename T>
b8 List<T>::isEmpty() {
  return !(this->head || this->tail);
}

template<typename T>
void List<T>::insertHead(T &data) {
  Node<T>* p =  Node<T>::create_node(data);
  if (isEmpty()) {
    this->head = this->tail = p;
  } else {
    p->next = this->head;
    this->head = p;
  }
}

template<typename T>
void List<T>::insertTail(T &data) {
  Node<T>* p = Node<T>::create_node(data);
  if (isEmpty()) {
    this->head = this->tail = p;
  } else {
    this->tail->next = p;
    this->tail = p;
  }
}

template<typename T>
void List<T>::insertAfter(b8 (*compare)(const T&, const T&), T &data) {
  for (Node<T>* p = this->head; p != nullptr; p = p->next) {
    if (compare(p->data, data)) {
      if (p == this->tail) {
        insertTail(data);
        return;
      } else {
        Node<T> *ptr = Node<T>::create_node(data);
        ptr->next = p->next;
        p->next = ptr;
        return;
      }
    }
  }
}

template<typename T>
void List<T>::insertBefore(b8 (*compare)(const T&, const T&), T &data) {
  if (compare(this->head->data, data)) {
    insertHead(data);
    return;
  }
  for (Node<T> *p = head; p != tail; p = p->next) {
    if (compare(p->next->data, data)) {
      Node<T> *ptr = Node<T>::create_node(data);
      ptr->next = p->next;
      p->next = ptr;
      return;
    }
  }
}

template<typename T>
void List<T>::print() {
  for (Node<T> *p = this->head; p != nullptr; p = p->next) {
    p->data.xuat();
  }
}

b8 target_has_bigger_masv_than_data(const SinhVien &target, const SinhVien &sv) {
  return target.masv > sv.masv;
}

int main (int argc, char *argv[]) {
  SinhVien sv, sv1;
  sv.nhap();
  List<SinhVien> L;
  L.insertHead(sv);
  L.insertHead(sv);
  L.insertHead(sv);
  L.insertHead(sv);
  L.insertHead(sv);
  sv1.nhap();
  L.insertBefore(target_has_bigger_masv_than_data, sv1);
  L.print();
  return 0;
}
