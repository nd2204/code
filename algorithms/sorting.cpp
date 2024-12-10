#include <iostream>

using namespace std;

// Bài 17:
// Sinh viên hãy lập trình giải bài toán quản lý tài liệu, trong chương trình thực hiện các công việc
// sau:
// Câu 1. (2 -) Định nghĩa một cấu trúc Tài liệu, bao gồm các trường thông tin như sau: Mã tài liệu
// (kiểu số nguyên), Tên tài liệu (kiểu chuỗi ký tự), Năm xuất bản (kiểu số nguyên), Giá bán
// (kiểu số thực).
struct TaiLieu {
  string ten;
  float gia;
  int ma;
  int nam;
};

void nhap(TaiLieu& tl) {
  cout << "-----------------------\n";
  cout << " Nhap ma: "; cin >> tl.ma;
  while (getchar() != '\n');
  cout << " Nhap ten: "; getline(cin, tl.ten);
  cout << " Nhap nam: "; cin >> tl.nam;
  cout << " Nhap gia: "; cin >> tl.gia;
}

void xuat(TaiLieu& tl) {
  cout << " ma: " << tl.ma
    << ",ten: " << tl.ten
    << ",nam: " << tl.nam
    << ",gia: " << tl.gia << endl;
}

void foreach(TaiLieu arr[], int n, void (*cb)(TaiLieu&)) {
  for (int i = 0; i < n; ++i) {
    cb(arr[i]);
  }
}

// Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n tài liệu
void nhapN(TaiLieu arr[], int n) {
  foreach(arr, n, nhap);
}

// Câu 3. (1 -) Viết hàm xuất ra mảng n tài liệu vừa nhập.
void xuatN(TaiLieu arr[], int n) {
  foreach(arr, n, xuat);
}

// Interchange Sort
void interchangeSort(TaiLieu arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i].gia > arr[j].gia) {
        swap(arr[i], arr[j]);
      }
    }
  }
}

// Bubble Sort
void bubbleSort(TaiLieu arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j].gia > arr[j + 1].gia) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Insertion Sort
void insertionSort(TaiLieu arr[], int n) {
  for (int i = 1; i < n; i++) {
    TaiLieu key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j].gia > key.gia) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Selection Sort
void selectionSort(TaiLieu arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j].gia < arr[minIdx].gia) {
        minIdx = j;
      }
    }
    swap(arr[minIdx], arr[i]);
  }
}

// Quick Sort
void quickSort(TaiLieu arr[], int left, int right) {
  int l = left, r = right;
  float pivot = arr[(left + right) / 2].gia;

  while (l <= r) {
    while (arr[l].gia < pivot) l++;
    while (arr[r].gia > pivot) r--;
    if (l <= r) {
      swap(arr[l], arr[r]);
      l++;
      r--;
    }
  }

  if (left < r) quickSort(arr, left, r);
  if (l < right) quickSort(arr, l, right);
}

// bsearch
int binarySearch(float gia, TaiLieu arr[], int n) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = (right + left) / 2;
    if (arr[mid].gia == gia)
      return mid;
    else if (arr[mid].gia < gia)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

void searchAll(float gia, TaiLieu arr[], int n) {
  int found = binarySearch(gia, arr, n);
  if (found == -1) {
    cout << "Khong tim thay tai lieu co gia ban = " << gia << endl;
  } else {
    cout << "Cac tai lieu co gia ban = " << gia << " la:" << endl;

    int i = found;
    while (i >= 0 && arr[i].gia == gia) {
      cout << "Ma tai lieu: " << arr[i].ma << endl;
      cout << "Ten tai lieu: " << arr[i].ten << endl;
      cout << "Nam xuat ban: " << arr[i].nam << endl;
      cout << "Gia ban: " << arr[i].gia << endl;
      cout << endl;
      i--;
    }

    i = found + 1;
    while (i < n && arr[i].gia == gia) {
      cout << "Ma tai lieu: " << arr[i].ma << endl;
      cout << "Ten tai lieu: " << arr[i].ten << endl;
      cout << "Nam xuat ban: " << arr[i].nam << endl;
      cout << "Gia ban: " << arr[i].gia << endl;
      cout << endl;
      i++;
    }
  }
}

// Câu 4. (2 -) Sử dụng phương pháp sắp xếp chèn trực tiếp(inserttion sort), viết hàm sắp xếp các
// tài liệu theo chiều tăng dần của giá bán
// Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm
// kiếm các tài liệu có giá bán bằng X.
// Câu 6. (1.5 -). Viết hàm chính thực hiện:
// - (0.5 -) Nhập vào n tài liệu và hiển thị các tài liệu vừa nhập
// - (0.5 -) Sắp xếp n tài liệu theo chiều tăng dần của giá bán.
// - (0.5 -) Sử dụng hàm tìm kiếm hiển thị các tài liệu có giá bán bằng X (X do người dùng
// nhập vào)

// 1) Interchange sort
// 2) Bubble sort
// 3) Insertion sort
// 4) Selection sort
// 5) Quick sort
int main (int argc, char *argv[]) {
  int n;
  do {
    cout << "Nhap n: "; cin >> n;
  } while (n <= 0);

  TaiLieu arr[n];

  nhapN(arr, n);

  cout << "\nMang vua nhap la:\n";
  cout << "-----------------------\n";
  xuatN(arr, n);

  int choice;
  cout << "\nChon phuong phap sap xep:"
    << "\n\t1. Interchange Sort"
    << "\n\t2. Bubble Sort"
    << "\n\t3. Insertion Sort"
    << "\n\t4. Selection Sort"
    << "\n\t5. Quick Sort"
    << "\nLua chon: ";
  cin >> choice;

  switch (choice) {
    case 1: interchangeSort(arr, n); break;
    case 2: bubbleSort(arr, n); break;
    case 3: insertionSort(arr, n); break;
    case 4: selectionSort(arr, n); break;
    case 5: quickSort(arr, 0, n - 1); break;
    default: cout << "Lua chon khong hop le.\n"; return 1;
  }

  cout << "\nDanh sach tai lieu sau khi sap xep theo gia ban tang dan:\n";
  xuatN(arr, n);

  float x;
  cout << "Nhap gia ban can tim: ";
  cin >> x;
  searchAll(x, arr, n);

  return 0;
}

