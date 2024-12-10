#include <iostream>
#include <string>
#include <cstring>

// =========================== Bai 16 ===========================
/* Sinh viên hãy lập trình giải bài toán quản lý nhân viên, trong chương trình thực hiện các công */
/* việc sau: */
/* Câu 1. (2 -) Định nghĩa một cấu trúc nhân viên bao gồm các thông tin: Mã nhân viên, họ tên, */
/* ngày sinh (kiểu ngày/tháng/năm, ví dụ 10/10/2000), lương (đơn vị triệu đồng). */
/* Câu 2. (2 -) Viết hàm nhập vào một mảng gồm n nhân viên */
/* Câu 3. (1 -) Viết hàm xuất ra mảng n nhân viên vừa nhập. */
/* Câu 4. (2 -) Sử dụng phương pháp sắp xếp chèn trực tiếp(inserttion sort), viết hàm sắp xếp các */
/* nhân viên theo chiều tăng dần của lương */
/* Câu 5. (1.5 -). Áp dụng chiến lược chia để trị (bằng thuật toán tìm kiếm nhị phân). Viết hàm tìm */
/* kiếm các nhân viên có lương bằng X. */
/* Câu 6. (1.5 -). Viết hàm chính thực hiện: */
/* - (0.5 -) Nhập vào n nhân viên và hiển thị các nhân viên vừa nhập */
/* - (0.5 -) Sắp xếp n nhân viên theo chiều tăng dần của lương. */
/* - (0.5 -) Sử dụng hàm tìm kiếm hiển thị các nhân viên có lương bằng X (X do người dùng */
/* nhập vào) */
int partition(TaiLieu tla[], int low, int high) {

  // Choose the pivot
  int pivot = arr[high];

  // Index of smaller element and indicates 
  // the right position of pivot found so far
  int i = low - 1;

  // Traverse arr[;ow..high] and move all smaller
  // elements on left side. Elements from low to 
  // i are smaller after every iteration
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  // Move pivot after smaller elements and
  // return its position
  swap(arr[i + 1], arr[high]);  
  return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  if (low < high) {

    int pi = partition(arr, low, high);

    // Recursion calls for smaller elements
    // and greater or equals elements
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
}
