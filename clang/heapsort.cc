#include <iostream>
#include <cstring>

// bài số 16 với Quick Sort, bài số 17 với Merge Sort
// =========================== Bai 15 ===========================
// Sinh viên hãy lập trình giải bài toán quản lý khách hàng,
// trong chương trình thực hiện các công việc sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Khách hàng, bao gồm các trường thông tin như sau: Mã
// khách hàng (kiểu số nguyên), tên khách hàng (kiểu chuỗi ký tự), số điện thoại (kiểu chuỗi
// ký tự), tổng tiền thanh toán (kiểu số).
struct KhachHang {
  std::string m_name;
  std::string m_phone;
  double      m_total;
  int         m_id;
};

void khachhang_foreach(KhachHang kha[], int n, void (*cb)(KhachHang& kh)) {
  for (int i = 0; i < n; ++i) {
    cb(kha[i]);
  }
}

// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n khách hàng
void khachhang_nhap(KhachHang& kh) {
  std::cout << "  ID: ";
  std::cin >> kh.m_id;
  while(getchar() != '\n') {}
  
  std::cout << "  Name: ";
  std::getline(std::cin >> std::ws, kh.m_name);

  std::cout << "  Phone Number: ";
  std::getline(std::cin >> std::ws, kh.m_phone);

  std::cout << "  Total: ";
  std::cin >> kh.m_total;
}

void khachhang_nhapn(KhachHang kha[], int n) {
  if (kha == nullptr) kha = new KhachHang[n];

  khachhang_foreach(kha, n, khachhang_nhap);
}

// Câu 3. (1 -) Viết hàm xuất ra mảng n khách hàng vừa nhập.
void khachhang_xuat(KhachHang& kh) {
  std::cout
    << "id: "    << kh.m_id    << ", " 
    << "name: "  << kh.m_name  << ", "
    << "phone: " << kh.m_phone << ", "
    << "total: " << kh.m_total << '\n';
}

void khachhang_xuatn(KhachHang kha[], int n) {
  khachhang_foreach(kha, n, khachhang_xuat);
}

// Câu 4. (2 -) Sử dụng phương pháp heap sort, viết hàm sắp xếp các
// khách hàng theo chiều tăng dần của tổng tiền thanh toán
template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

void heapify(KhachHang kha[], int n, int i) {
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if (l < n && kha[l].m_total > kha[largest].m_total)
    largest = l;

  if (r < n && kha[r].m_total > kha[largest].m_total)
    largest = r;

  if (largest != i) {
    swap<KhachHang>(kha[i], kha[largest]);
    heapify(kha, n, largest);
  }
}

void heapsort(KhachHang kha[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(kha, n, i);

  for (int i = n - 1; i > 0; i--) {
    swap(kha[0], kha[i]);
    heapify(kha, i, 0);
  }
}

// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm
// kiếm các khách hàng có tổng tiền thanh toán bằng X.

int binary_search(KhachHang kha[], int low, int high, double X) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (kha[mid].m_total == X)
      return mid;
    if (kha[mid].m_total < X)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// - (0.5 -) Nhập vào n khách hàng và hiển thị các khách hàng vừa nhập
// - (0.5 -) Sắp xếp n khách hàng theo chiều tăng dần của tổng tiền thanh toán.
// - (0.5 -) Sử dụng hàm tìm kiếm hiển thị các khách hàng có tổng tiền thanh toán bằng X (X
// do người dùng nhập vào)
int main() {
  int n;
  std::cout << "Nhap n: ";
  std::cin >> n;

  KhachHang* kha = new KhachHang[n]; 

  khachhang_nhapn(kha, n);
  std::cout << "\nMang vua nhap\n";
  khachhang_xuatn(kha, n);

  std::cout << "\nMang sau khi sap xep\n";
  heapsort(kha, n);
  khachhang_xuatn(kha, n);

  double x;
  std::cout << "Nhap X: ";
  std::cin >> x;

  int found_idx = binary_search(kha, 0, n - 1, x);
  if (found_idx == -1) {
    std::cout << "Khong co khach hang nao co tong tien thanh toan bang " << x << '\n';
  } else {
    std::cout << "Khach hang co tong tien thanh toan bang " << x << ":\n";
    for (int i = found_idx; i > 0 && kha[i].m_total == x; --i) {
      khachhang_xuat(kha[i]);
    }
    for (int i = found_idx + 1; i < n && kha[i].m_total == x; ++i) {
      khachhang_xuat(kha[i]);
    }
  }

  delete[] kha;
}
