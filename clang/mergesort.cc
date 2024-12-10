#include <iostream>
#include <cstring>

// =========================== Bai 17 ===========================
// Sinh viên hãy lập trình giải bài toán quản lý tài liệu,
// trong chương trình thực hiện các công việc sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Tài liệu, bao gồm các trường thông tin như sau: Mã tài liệu
// (kiểu số nguyên), Tên tài liệu (kiểu chuỗi ký tự), Năm xuất bản (kiểu số nguyên), Giá bán
// (kiểu số thực).

struct TaiLieu {
  std::string m_name;
  float       m_price;
  int         m_year;
  int         m_id;
};

void tailieu_foreach(TaiLieu tla[], int n, void (*cb)(TaiLieu& tl)) {
  for (int i = 0; i < n; ++i) {
    cb(tla[i]);
  }
}

// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm
// kiếm các tài liệu có giá bán bằng X.
// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// - (0.5 -) Nhập vào n tài liệu và hiển thị các tài liệu vừa nhập
// - (0.5 -) Sắp xếp n tài liệu theo chiều tăng dần của giá bán.
// - (0.5 -) Sử dụng hàm tìm kiếm hiển thị các tài liệu có giá bán bằng X (X do người dùng
// nhập vào)


// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n tài liệu
void tailieu_nhap(TaiLieu& kh) {
  std::cout << "  id: ";
  std::cin >> kh.m_id;
  while(getchar() != '\n') {}

  std::cout << "  title: ";
  std::getline(std::cin >> std::ws, kh.m_name);

  std::cout << "  year: ";
  std::cin >> kh.m_year;

  std::cout << "  price: ";
  std::cin >> kh.m_price;
}

void tailieu_nhapn(TaiLieu kha[], int n) {
  if (kha == nullptr) kha = new TaiLieu[n];

  tailieu_foreach(kha, n, tailieu_nhap);
}

// Câu 3. (1 -) Viết hàm xuất ra mảng n tài liệu vừa nhập.
void tailieu_xuat(TaiLieu& kh) {
  std::cout
    << "id: "    << kh.m_id    << ", " 
    << "name: "  << kh.m_name  << ", "
    << "year: "  << kh.m_year << ", "
    << "price: " << kh.m_price << '\n';
}

void tailieu_xuatn(TaiLieu kha[], int n) {
  tailieu_foreach(kha, n, tailieu_xuat);
}

// Câu 4. (2 -) Sử dụng phương pháp sắp xếp quick sort, viết hàm sắp xếp các
// tài liệu theo chiều tăng dần của giá bán
template <typename T>
void swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm
// kiếm các khách hàng có tổng tiền thanh toán bằng X.

int binary_search(TaiLieu kha[], int low, int high, double X) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (kha[mid].m_price == X)
      return mid;
    if (kha[mid].m_price < X)
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

  TaiLieu* kha = new TaiLieu[n]; 

  tailieu_nhapn(kha, n);
  std::cout << "\nMang vua nhap\n";
  tailieu_xuatn(kha, n);

  std::cout << "\nMang sau khi sap xep\n";
  heapsort(kha, n);
  tailieu_xuatn(kha, n);

  double x;
  std::cout << "Nhap X: ";
  std::cin >> x;

  int found_idx = binary_search(kha, 0, n - 1, x);
  if (found_idx == -1) {
    std::cout << "Khong co khach hang nao co tong tien thanh toan bang " << x << '\n';
  } else {
    std::cout << "Khach hang co tong tien thanh toan bang " << x << ":\n";
    for (int i = found_idx; i > 0 && kha[i].m_price == x; --i) {
      tailieu_xuat(kha[i]);
    }
    for (int i = found_idx + 1; i < n && kha[i].m_price == x; ++i) {
      tailieu_xuat(kha[i]);
    }
  }

  delete[] kha;
}
