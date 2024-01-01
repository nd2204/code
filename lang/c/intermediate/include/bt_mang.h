#ifndef BT_MANG
#define BT_MANG

// Cau 3
    float mang_b1c3(int arr[], int size); // Tính trung bình cộng các số âm trong mảng
    void mang_b2c3(float array[], const int size); // Kiểm tra có hai số âm bằng nhau mà cạnh nhau trong mảng
    float mang_b3c3(float* array, const int arraySize); // Trung bình cộng các số dương trong mảng.
    int mang_b4c3(int n); // Hiển thị các số nguyên tố có trong mảng. (isPrime) (int)
    void mang_b5c3(int arr[], int arr_size); // Tính trung bình cộng các phần tử trong đoạn x và y. Với x và y nhập từ bàn phím.
    void mang_b6c3(int arr[], int size); // Kiểm tra trong dãy có hai số dương bằng nhau mà cạnh nhau hay không. Đưa thông báo ra màn hình.
    void mang_b7c3(int arr[], int size); // In ra các phần tử chia hết cho 3 và nhỏ hơn 50 ra màn hình.
    // no implementation (b8c3 tuong tu b1c3)
    int mang_b9c3(int arr[], int size); // Tính tổng các phần tử âm và lẻ trong mảng
    void mang_b10c3(int arr[], int arr_size); // Tìm vị trí các phần tử âm nhỏ nhất trong mảng
    void mang_b11c3(int arr[], int arr_size); // Xóa phần tử âm có trong mảng.

// Cau 4
    void mang_b1c4(int arr[], int size); // SẮP XẾP mảng TĂNG DẦN. In mảng sau khi sắp xếp ra màn hình. (bubbleSort) (int)
    float mang_b2c4(float array[], const int size); // Nhập x kiểu nguyên. TRUNG BÌNH CỘNG của x giá trị đầu tiên trong mảng.
    void mang_b3c4(float arr[], int left, int right); // SẮP XẾP mảng TĂNG DẦN. In mảng sau khi sắp xếp (mergeSort) (float)
    void mang_b4c4(int arr[], int size, int key); // Nhập một số x từ bàn phím, kiểm tra xem x có trong mảng không? (linearSearch) (int)
    int mang_b5c4(int arr[], int arr_size); // Giá trị lớn nhất trong dãy.
    void mang_b6c4(int arr[], int l, int r); // Sắp xếp giá trị của dãy theo chiều giảm dần. (mergeSort) (int)
    void mang_b7c4(int arr[], int size); // Nhập số nguyên x và k. Thêm phần tử x vào vị trí thứ k trong mảng.
    // mang_b8c4 (tuong tu b1c4)
    // mang_b9c4 (tuong tu b1c4)
    // mang_b10c4 (tuong tu b6c4)

// Cau 5 (Read and Write)
    void mang_b1c5(int arr[], int size, char* filename); // Ghi vào tệp .txt những phần tử lẻ của mảng.
    void mang_b2c5(float array[], int size, char* filename); // Ghi vào tệp .txt những phần tử dương của mảng
    void mang_b3c5(float arr[], int arr_size, char* filename); // Ghi vào tệp .txt những phần tử nhỏ hơn 10 trong mảng.
    void mang_b4c5(int arr[], int arr_size, char* filename); // Ghi vào tệp .txt những phần tử chẵn của dãy.
    // mang_b5c5 (tuong tu b2c5)
    // mang_b6c5 (tuong tu b2c5)
    void mang_b7c5(int arr[], int size, char* filename); // Ghi vào tệp .txt so am trong mang
    // mang_b8c5 (tuong tu b1c5)
    // mang_b9c5 (tuong tu b1c5)
    // mang_b10c5 (tuong tu b2c5)

#endif // !DEBUG
